#pragma once

#include <queue>
#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include "const.h"
#include "Loger.h"
#include "ConfigMgr.h"
#include "BlockQueue.h"

class SqlConnection {
public:
	SqlConnection(sql::Connection* con, int64_t lasttime) :m_con(con), _last_oper_time(lasttime) {}
	std::unique_ptr<sql::Connection> m_con;
	int64_t _last_oper_time;
};

class MYSQLConPool {
public:
	MYSQLConPool(const std::string& url, const std::string& user, const std::string& pass, const std::string& schema, int poolSize)
		: m_url(url), m_user(user), m_pass(pass), m_schema(schema), m_poolSize(poolSize), b_stop(false) {
		try {
			for (int i = 0; i < m_poolSize; ++i) {
				sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
				auto* con = driver->connect(m_url, m_user, m_pass);
				con->setSchema(m_schema);
				// 获取当前时间戳
				auto currentTime = std::chrono::system_clock::now().time_since_epoch();
				// 将时间戳转换为秒
				long long timestamp = std::chrono::duration_cast<std::chrono::seconds>(currentTime).count();
				m_pool.push(std::make_unique<SqlConnection>(con, timestamp));
			}

			_check_thread = std::thread([this]() {
				while (!b_stop) {
					checkConnection();
					std::this_thread::sleep_for(std::chrono::seconds(60));
				}
				});

			_check_thread.detach();
		}
		catch (sql::SQLException& e) {
			// 处理异常
			std::cout << "mysql pool init failed, error is " << e.what() << std::endl;
		}
	}

	void checkConnection() {
		std::lock_guard<std::mutex> guard(mutex_);
		int poolsize = m_pool.size();
		// 获取当前时间戳
		auto currentTime = std::chrono::system_clock::now().time_since_epoch();
		// 将时间戳转换为秒
		long long timestamp = std::chrono::duration_cast<std::chrono::seconds>(currentTime).count();
		for (int i = 0; i < poolsize; i++) {
			auto con = std::move(m_pool.front());
			m_pool.pop();
			Defer defer([this, &con]() {
				m_pool.push(std::move(con));
				});

			if (timestamp - con->_last_oper_time < 5) {
				continue;
			}

			try {
				std::unique_ptr<sql::Statement> stmt(con->m_con->createStatement());
				stmt->executeQuery("SELECT 1");
				con->_last_oper_time = timestamp;
				std::cout << "execute timer alive query , cur is " << timestamp << std::endl;
			}
			catch (sql::SQLException& e) {
				std::cout << "Error keeping connection alive: " << e.what() << std::endl;
				// 重新创建连接并替换旧的连接
				sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
				auto* newcon = driver->connect(m_url, m_user, m_pass);
				newcon->setSchema(m_schema);
				con->m_con.reset(newcon);
				con->_last_oper_time = timestamp;
			}
		}
	}

	std::unique_ptr<SqlConnection> getConnection() {
		std::unique_lock<std::mutex> lock(mutex_);
		cond_.wait(lock, [this] {
			if (b_stop) {
				return true;
			}
			return !m_pool.empty(); });
		if (b_stop) {
			return nullptr;
		}
		std::unique_ptr<SqlConnection> con(std::move(m_pool.front()));
		m_pool.pop();
		return con;
	}

	void returnConnection(std::unique_ptr<SqlConnection> con) {
		std::unique_lock<std::mutex> lock(mutex_);
		if (b_stop) {
			return;
		}
		m_pool.push(std::move(con));
		cond_.notify_one();
	}

	void Close() {
		b_stop = true;
		cond_.notify_all();
	}

	~MYSQLConPool() {
		std::unique_lock<std::mutex> lock(mutex_);
		while (!m_pool.empty()) {
			m_pool.pop();
		}
	}

private:
	std::string m_url;
	std::string m_user;
	std::string m_pass;
	std::string m_schema;
	int m_poolSize;
	std::queue<std::unique_ptr<SqlConnection>> m_pool;
	std::mutex mutex_;
	std::condition_variable cond_;
	std::atomic<bool> b_stop;
	std::thread _check_thread;
};

struct UserInfo {
	std::string name;
	std::string pwd;
	int uid;
	std::string email;
};

class MysqlDao
{
public:

	MysqlDao();
	~MysqlDao();
	bool CheckEmail(const std::string& user, const std::string& email);
	bool CheckPwd(const std::string& user, const std::string& pwd, UserInfo& userInfo);
	int CheckSongExist(int uid, const std::string& singer, const std::string& song_name);
	bool LoginUser(int uid, Json::Value& value);
	int RegUser(const std::string& user, const std::string& email, const std::string& pwd);
	bool UpdatePwd(const std::string& user, const std::string& newpwd);
	bool SearchSong(const std::string& song_name, Json::Value& value);
	bool GetMusicFilePath(const std::string& singer, const std::string& song_name, std::string& path);
	bool AddSongToSongList(int uid, const std::string& singer, const std::string& song_name);
	bool RemoveSongFromSongList(int uid, const std::string& singer, const std::string& song_name);

private:
	std::unique_ptr<MYSQLConPool> m_pool;
};