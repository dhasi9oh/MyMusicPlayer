#include "LogicSystem.h"

LogicSystem::LogicSystem()
{
	RegGet("/get_test", [](std::shared_ptr<HttpConnection> connection) {
		beast::ostream(connection->m_response.body()) << "receive get_test req " << std::endl;
		int i = 0;
		for (auto& elem : connection->m_getParams) {
			i++;
			beast::ostream(connection->m_response.body()) << "param" << i << " key is " << elem.first;
			beast::ostream(connection->m_response.body()) << ", " << " value is " << elem.second << std::endl;
		}
		});

	RegGet("/error_url", [](std::shared_ptr<HttpConnection> connection) {

		});


	RegPost("/error_url", [](std::shared_ptr<HttpConnection> connection) {

		});

	RegPost("/get_varifycode", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "text/json");
		Json::Value root;
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			root["error"] = ErrorCodes::Error_Json;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		if (!src_root.isMember("email")) {
			LOG_WARN("Failed to parse JSON data!");
			root["error"] = ErrorCodes::Error_Json;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		auto email = src_root["email"].asString();
		GetVarifyRsp rsp = VerifyGrpcClient::GetInstance()->GetVarifyCode(email);
		root["error"] = rsp.error();
		root["email"] = src_root["email"];
		std::string jsonstr = root.toStyledString();
		beast::ostream(connection->m_response.body()) << jsonstr;
		return true;
		});

	//day11 注册用户逻辑
	RegPost("/user_register", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "text/json");
		Json::Value root;
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			root["error"] = ErrorCodes::Error_Json;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		auto email = src_root["email"].asString();
		auto name = src_root["user"].asString();
		auto pwd = src_root["passwd"].asString();
		auto confirm = src_root["confirm"].asString();

		if (pwd != confirm) {
			LOG_WARN("password err ");
			root["error"] = ErrorCodes::PasswdErr;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		//先查找redis中email对应的验证码是否合理
		std::string  varify_code;
		bool b_get_varify = RedisMgr::GetInstance()->Get(CODEPREFIX + src_root["email"].asString(), varify_code);
		if (!b_get_varify) {
			LOG_WARN(" get varify code expired");
			root["error"] = ErrorCodes::VarifyExpired;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		if (varify_code != src_root["varifycode"].asString()) {
			LOG_WARN(" varify code error");
			root["error"] = ErrorCodes::VarifyCodeErr;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		//查找数据库判断用户是否存在
		int uid = MysqlMgr::GetInstance()->RegUser(name, email, pwd);
		if (uid == 0 || uid == -1) {
			LOG_WARN(" user or email exist");
			root["error"] = ErrorCodes::UserExist;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}
		root["error"] = 0;
		root["uid"] = uid;
		root["email"] = email;
		root["user"] = name;
		root["passwd"] = pwd;
		root["confirm"] = confirm;
		root["varifycode"] = src_root["varifycode"].asString();
		std::string jsonstr = root.toStyledString();
		beast::ostream(connection->m_response.body()) << jsonstr;
		return true;
		});

	//重置回调逻辑
	RegPost("/reset_pwd", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "text/json");
		Json::Value root;
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			root["error"] = ErrorCodes::Error_Json;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		auto email = src_root["email"].asString();
		auto user = src_root["user"].asString();
		auto pwd = src_root["passwd"].asString();

		//先查找redis中email对应的验证码是否合理
		std::string  varify_code;
		bool b_get_varify = RedisMgr::GetInstance()->Get(CODEPREFIX + src_root["email"].asString(), varify_code);
		if (!b_get_varify) {
			LOG_WARN(" get varify code expired");
			root["error"] = ErrorCodes::VarifyExpired;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		if (varify_code != src_root["varifycode"].asString()) {
			LOG_WARN(" varify code error");
			root["error"] = ErrorCodes::VarifyCodeErr;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}
		//查询数据库判断用户名和邮箱是否匹配
		bool email_valid = MysqlMgr::GetInstance()->CheckEmail(user, email);
		if (!email_valid) {
			LOG_WARN(" user email not match");
			root["error"] = ErrorCodes::EmailNotMatch;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		//更新密码为最新密码
		bool b_up = MysqlMgr::GetInstance()->UpdatePwd(user, pwd);
		if (!b_up) {
			LOG_WARN(" update pwd failed");
			root["error"] = ErrorCodes::PasswdUpFailed;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		LOG_INFO("succeed to update password");
		root["error"] = 0;
		root["email"] = email;
		root["user"] = user;
		root["passwd"] = pwd;
		root["varifycode"] = src_root["varifycode"].asString();
		std::string jsonstr = root.toStyledString();
		beast::ostream(connection->m_response.body()) << jsonstr;
		return true;
		});

	//用户登录逻辑
	RegPost("/user_login", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "text/json");
		Json::Value root;
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			root["error"] = ErrorCodes::Error_Json;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		auto name = src_root["user"].asString();
		auto pwd = src_root["passwd"].asString();
		UserInfo userInfo;
		//查询数据库判断用户名和密码是否匹配
		bool pwd_valid = MysqlMgr::GetInstance()->CheckPwd(name, pwd, userInfo);
		if (!pwd_valid) {
			LOG_WARN(" user pwd not match");
			root["error"] = ErrorCodes::PasswdInvalid;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		bool success = MysqlMgr::GetInstance()->LoginUser(userInfo.uid, root);
		if (!success) {
			LOG_WARN(" get a personal playlist");
			root["error"] = ErrorCodes::GetPersonalSongListFailed;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		root["error"] = 0;
		root["user"] = name;
		root["uid"] = userInfo.uid;
		std::string jsonstr = root.toStyledString();
		beast::ostream(connection->m_response.body()) << jsonstr;
		return true;
		});

	RegPost("/search_song", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "text/json");
		Json::Value root;
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			root["error"] = ErrorCodes::Error_Json;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		auto song_name = src_root["song_name"].asString();

		bool success = MysqlMgr::GetInstance()->SearchSong(song_name, root);
		if (!success) {
			LOG_WARN(" search song {} failed", song_name);
			root["error"] = ErrorCodes::SearchSongNameFailed;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		root["error"] = 0;
		std::string jsonstr = root.toStyledString();
		beast::ostream(connection->m_response.body()) << jsonstr;
		return true;
		});
	

	//获取歌曲文件逻辑
	RegGet("/get_song_body", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "audio/mpeg");
		Json::Reader reader;
		Json::Value src_root;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			return true;
		}

		std::string path;
		auto singer = src_root["singer"].asString();
		auto song_name = src_root["song_name"].asString();
		//查询对应文件路径
		bool success = MysqlMgr::GetInstance()->GetMusicFilePath(singer, song_name, path);
		if (!success) {
			LOG_WARN("music file does not exist singer:{} song_name:{}", singer, song_name);
			return true;
		}

		int fd = open(path.c_str(), O_RDONLY);
		if (fd <= -1) {
			LOG_WARN("music file open failed path:{}", path);
			return true;
		}

		struct stat st;
		if (fstat(fd, &st) <= -1) {
			close(fd);
			LOG_WARN("music file fstat failed path:{}", path);
			return true;
		}

		char* ptr = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
		if (ptr == MAP_FAILED) {
			close(fd);
			LOG_WARN("music file fstat failed path : {}", path);
			return true;
		}
		connection->m_response.set(http::field::content_length, std::to_string(st.st_size));
		beast::ostream(connection->m_response.body()) << beast::string_view(ptr, st.st_size);

		munmap((void*)ptr, st.st_size);
		close(fd);
		return true;
		});

	//添加歌曲到歌单
	RegPost("/add_song_to_song_list", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "audio/mpeg");
		Json::Value root;
		Json::Value src_root;
		Json::Reader reader;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			return true;
		}

		auto uid = src_root["uid"].asInt();
		auto singer = src_root["singer"].asString();
		auto song_name = src_root["song_name"].asString();

		bool exist = MysqlMgr::GetInstance()->AddSongToSongList(uid, singer, song_name);
		if (exist) {
			LOG_WARN("uid:{} already owned music file:{} {}", uid, singer, song_name);
			root["error"] = ErrorCodes::AddToSongListFailed;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		root["singer"] = singer;
		root["song_name"] = song_name;
		root["duration"] = src_root["duration"];
		std::string jsonstr = root.toStyledString();
		beast::ostream(connection->m_response.body()) << jsonstr;
		return true;
		});

	//移出歌曲从歌单
	RegPost("/remove_song_from_song_list", [](std::shared_ptr<HttpConnection> connection) {
		auto body_str = boost::beast::buffers_to_string(connection->m_request.body().data());
		LOG_INFO("receive body is {}", body_str);
		connection->m_response.set(http::field::content_type, "audio/mpeg");
		Json::Value root;
		Json::Value src_root;
		Json::Reader reader;
		bool parse_success = reader.parse(body_str, src_root);
		if (!parse_success) {
			LOG_WARN("Failed to parse JSON data!");
			return true;
		}

		auto uid = src_root["uid"].asInt();
		auto singer = src_root["singer"].asString();
		auto song_name = src_root["song_name"].asString();

		bool exist = MysqlMgr::GetInstance()->RemoveSongFromSongList(uid, singer, song_name);
		if (exist) {
			LOG_WARN("uid:{} already owned music file:{} {}", uid, singer, song_name);
			root["error"] = ErrorCodes::RemoveFromSongListFailed;
			std::string jsonstr = root.toStyledString();
			beast::ostream(connection->m_response.body()) << jsonstr;
			return true;
		}

		root["singer"] = singer;
		root["song_name"] = song_name;
		root["duration"] = src_root["duration"];
		std::string jsonstr = root.toStyledString();
		beast::ostream(connection->m_response.body()) << jsonstr;
		return true;
		});

}

void LogicSystem::RegGet(std::string url, HttpHandler handler)
{
	m_getHandlers.insert(make_pair(url, handler));
}

void LogicSystem::RegPost(std::string url, HttpHandler handler)
{
	m_postHandlers.insert(make_pair(url, handler));
}

LogicSystem::~LogicSystem()
{
}

bool LogicSystem::HandleGet(std::string path, std::shared_ptr<HttpConnection> con)
{
	if (m_getHandlers.find(path) == m_getHandlers.end()) {

		return false;
	}

	m_getHandlers[path](con);
	return true;
}

bool LogicSystem::HandlePost(std::string path, std::shared_ptr<HttpConnection> con)
{
	if (m_postHandlers.find(path) == m_postHandlers.end()) {
		return false;
	}

	m_postHandlers[path](con);
	return true;
}