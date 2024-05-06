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
		// ׼�����ô洢����
		std::unique_ptr<sql::PreparedStatement> stmt(con->m_con->prepareStatement(
			"CALL reg_user(?, ?, ?, @result)"
		));
		// �����������
		stmt->setString(1, usr);
		stmt->setString(2, email);
		stmt->setString(3, pwd);

		// ����PreparedStatement��ֱ��֧��ע�����������������Ҫʹ�ûỰ������������������ȡ���������ֵ

		// ִ�д洢����
		stmt->execute();
		// ����洢���������˻Ự��������������ʽ��ȡ���������ֵ�������������ִ��SELECT��ѯ����ȡ����
	    // ���磬����洢����������һ���Ự����@result���洢������������������ȡ��
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
		// ׼����ѯ���
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT email FROM user WHERE usr = ?"
		));
		// �󶨲���
		pstmt->setString(1, usr);
		// ִ�в�ѯ
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		// ���������
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
		// ׼����ѯ���
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"UPDATE user SET pwd = ? WHERE usr = ?"
		));
		// �󶨲���
		pstmt->setString(1, newpwd);
		pstmt->setString(2, usr);
		// ִ�и���
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
		// ׼����ѯ���
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT * FROM song_message WHERE song_name LIKE ?%"
		));
		// �󶨲���
		pstmt->setString(1, song_name);
		// ��ȡ�����
		auto res = std::unique_ptr<sql::ResultSet>(pstmt->executeQuery());
		// ���������
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
		// ׼����ѯ���
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT url FROM song_message WHERE singer = ? WHERE song_name = ?"
		));
		// �󶨲���
		pstmt->setString(1, singer);
		pstmt->setString(2, song_name);
		// ��ȡ�����
		auto res = std::unique_ptr<sql::ResultSet>(pstmt->executeQuery());
		// ���������
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
		// ���ô������
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
		// ���ô������
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
		// ׼��SQL���
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"SELECT * FROM user WHERE usr = ?"
		));
		// ��usr�滻Ϊ��Ҫ��ѯ���û���
		pstmt->setString(1, usr);
		// ִ�в�ѯ
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		std::string origin_pwd = "";
		// ���������
		while (res->next()) {
			origin_pwd = res->getString("pwd");
			// �����ѯ��������
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
	//����ֵ-1Ϊsqlִ��ʧ��
	//����ֵ0Ϊ�û�������������ڸ赥��
	//����ֵ1Ϊ�û�����������ڸ赥��

	auto con = m_pool->getConnection();
	if (con == nullptr) {
		return -1;
	}

	Defer defer([this, &con]() {
		m_pool->returnConnection(std::move(con));
		});

	try {
		// ׼��SQL���
		std::unique_ptr<sql::PreparedStatement> pstmt(con->m_con->prepareStatement(
			"CALL checkSongExist(?, ?, ?)"
		));
		pstmt->setInt(1, uid);
		pstmt->setString(2, singer);
		pstmt->setString(3, song_name);

		// ִ�в�ѯ
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

		// ׼�����ô洢����
		std::unique_ptr<sql::PreparedStatement> stmt(con->m_con->prepareStatement(
			"SELECT *��FROM song_list��WHERE uid = ?"
		));
		// �����������
		stmt->setInt(1, uid);

		// ����PreparedStatement��ֱ��֧��ע�����������������Ҫʹ�ûỰ������������������ȡ���������ֵ

		// ִ�д洢����
		if (!stmt->execute()) return false;
		// ����洢���������˻Ự��������������ʽ��ȡ���������ֵ�������������ִ��SELECT��ѯ����ȡ����
		// ���磬����洢����������һ���Ự����@result���洢������������������ȡ��
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
