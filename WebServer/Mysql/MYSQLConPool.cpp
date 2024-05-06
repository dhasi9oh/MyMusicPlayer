#include "MYSQLConPool.h"

MysqlDao::MysqlDao()
{
	auto& cfg = ConfigMgr::Inst();
	const auto& host = cfg["Mysql"]["Host"];
	const auto& port = cfg["Mysql"]["Port"];
	const auto& pwd = cfg["Mysql"]["Passwd"];
	const auto& schema = cfg["Mysql"]["Schema"];
	const auto& user = cfg["Mysql"]["User"];
	m_pool.reset(new MYSQLConPool(host + ":" + port, user, pwd, schema, 5));
}

MysqlDao::~MysqlDao() 
{
	m_pool->Close();
}

int MysqlDao::RegUser(const std::string& usr, const std::string& email, const std::string& pwd)
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}
		// 准备调用存储过程
		std::unique_ptr<sql::PreparedStatement> stmt(con->m_con->prepareStatement(
			"CALL reg_user(?, ?, ?, @result)"
		));
		// 设置输入参数
		stmt->setString(1, usr);
		stmt->setString(2, email);
		stmt->setString(3, pwd);

		// 由于PreparedStatement不直接支持注册输出参数，我们需要使用会话变量或其他方法来获取输出参数的值

		// 执行存储过程
		stmt->execute();
		// 如果存储过程设置了会话变量或有其他方式获取输出参数的值，你可以在这里执行SELECT查询来获取它们
	    // 例如，如果存储过程设置了一个会话变量@result来存储输出结果，可以这样获取：
		std::unique_ptr<sql::Statement> stmtResult(con->m_con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmtResult->executeQuery(
			"SELECT @result AS result"
		));
		if (res->next()) {
			int result = res->getInt("result");
			std::cout << "Result: " << result << std::endl;
			return result;
		}
		return -1;
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return -1;
	}
}

bool MysqlDao::CheckEmail(const std::string& usr, const std::string& email) 
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}
		// 准备查询语句
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT email FROM user WHERE usr = ?"
		));
		// 绑定参数
		pstmt->setString(1, usr);
		// 执行查询
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		// 遍历结果集
		while (res->next()) {
			LOG_INFO("Check Email: ", res->getString("email").asStdString());
			if (email != res->getString("email")) {
				return false;
			}
			return true;
		}
		return true;
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}

bool MysqlDao::UpdatePwd(const std::string& usr, const std::string& newpwd) 
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}
		// 准备查询语句
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"UPDATE user SET pwd = ? WHERE usr = ?"
		));
		// 绑定参数
		pstmt->setString(1, newpwd);
		pstmt->setString(2, usr);
		// 执行更新
		int updateCount = pstmt->executeUpdate();
		LOG_INFO("Updated rows: ", updateCount);
		return true;
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}

bool MysqlDao::SearchSong(const std::string& song_name, Json::Value& root)
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}
		// 准备查询语句
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT * FROM song_message WHERE song_name LIKE ?%"
		));
		// 绑定参数
		pstmt->setString(1, song_name);
		// 获取结果集
		auto res = std::unique_ptr<sql::ResultSet>(pstmt->executeQuery());
		// 遍历结果集
		while (res->next()) {
			Json::Value value;
			value["singer"] = res->getString("singer").asStdString();
			value["song_name"] = res->getString("song_name").asStdString();
			value["duration"] = res->getString("duration").asStdString();
			root["search_list_song_message"].append(value);
		}
		return true;
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}

bool MysqlDao::GetMusicFilePath(const std::string& singer, const std::string& song_name, std::string& path)
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}
		// 准备查询语句
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT url FROM song_message WHERE singer = ? WHERE song_name = ?"
		));
		// 绑定参数
		pstmt->setString(1, singer);
		pstmt->setString(2, song_name);
		// 获取结果集
		auto res = std::unique_ptr<sql::ResultSet>(pstmt->executeQuery());
		// 遍历结果集
		while (res->next()) {
			path = res->getString("url");
		}
		return true;
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}

bool MysqlDao::AddSongToSongList(int uid, const std::string& singer, const std::string& song_name)
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}
		// 调用储存过程
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"CALL add_song_id_to_song_list(?, ?, ?)"
		));
		pstmt->setInt(1, uid);
		pstmt->setString(2, singer);
		pstmt->setString(3, song_name);
		return pstmt->execute();
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}

bool MysqlDao::RemoveSongFromSongList(int uid, const std::string& singer, const std::string& song_name)
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}
		// 调用储存过程
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"CALL remove_song_id_from_song_list(?, ?, ?)"
		));
		pstmt->setInt(1, uid);
		pstmt->setString(2, singer);
		pstmt->setString(3, song_name);

		return pstmt->execute();
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}

bool MysqlDao::CheckPwd(const std::string& usr, const std::string& pwd, UserInfo& userInfo) 
{
	auto con = m_pool->getConnection();
	if (con == nullptr) {
		return false;
	}

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		// 准备SQL语句
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT * FROM user WHERE usr = ?"
		));
		// 将usr替换为你要查询的用户名
		pstmt->setString(1, usr);
		// 执行查询
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		std::string origin_pwd = "";
		// 遍历结果集
		while (res->next()) {
			origin_pwd = res->getString("pwd");
			// 输出查询到的密码
			LOG_INFO("Password: ", origin_pwd);
			break;
		}

		if (pwd != origin_pwd) {
			return false;
		}
		userInfo.name = usr;
		userInfo.email = res->getString("email");
		userInfo.uid = res->getInt("uid");
		userInfo.pwd = origin_pwd;
		return true;
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}

int MysqlDao::CheckSongExist(int uid, const std::string& singer, const std::string& song_name)
{
	//返回值-1为sql执行失败
	//返回值0为用户这个歌曲不存在歌单中
	//返回值1为用户这个歌曲存在歌单中

	auto con = m_pool->getConnection();
	if (con == nullptr) {
		return -1;
	}

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		// 准备SQL语句
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"CALL checkSongExist(?, ?, ?)"
		));
		pstmt->setInt(1, uid);
		pstmt->setString(2, singer);
		pstmt->setString(3, song_name);

		// 执行查询
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		return res->rowsCount();
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return -1;
	}
}

bool MysqlDao::LoginUser(int uid, Json::Value& src_root)
{
	auto con = m_pool->getConnection();

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		if (con == nullptr) {
			return false;
		}

		Json::Value root;

		// 准备调用存储过程
		std::unique_ptr<sql::PreparedStatement> stmt(con->m_con->prepareStatement(
			"SELECT *　FROM song_list　WHERE uid = ?"
		));
		// 设置输入参数
		stmt->setInt(1, uid);

		// 由于PreparedStatement不直接支持注册输出参数，我们需要使用会话变量或其他方法来获取输出参数的值

		// 执行存储过程
		if (!stmt->execute()) return false;
		// 如果存储过程设置了会话变量或有其他方式获取输出参数的值，你可以在这里执行SELECT查询来获取它们
		// 例如，如果存储过程设置了一个会话变量@result来存储输出结果，可以这样获取：
		std::unique_ptr<sql::Statement> stmtResult(con->m_con->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmtResult->executeQuery(
			"SELECT @result AS result"
		));

		while (res->next()) {
			Json::Value value;
			value["singer"] = res->getString("singer").asStdString();
			value["song_name"] = res->getString("song_name").asStdString();
			value["duration"] = res->getString("duration").asStdString();
			root["love_list_song_message"].append(value);
		}

		res.reset(stmtResult->executeQuery(
			"SELECT * FROM song_message LIMIT 0, 100"
		));

		while (res->next()) {
			Json::Value value;
			value["singer"] = res->getString("singer").asStdString();
			value["song_name"] = res->getString("song_name").asStdString();
			value["duration"] = res->getString("duration").asStdString();
			root["home_list_song_message"].append(value);
		}

		src_root = std::move(root);

		return true;
	}
	catch (sql::SQLException& e) {
		std::string msg;
		msg.append("SQLException: ").append(e.what());
		msg.append(" (MySQL error code: ").append(std::to_string(e.getErrorCode()));
		msg.append(", SQLState: ").append(e.getSQLState()).append(" )");
		LOG_ERR(msg);
		return false;
	}
}
