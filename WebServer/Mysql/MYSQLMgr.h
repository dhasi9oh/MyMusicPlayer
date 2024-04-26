#pragma once

#include <memory>

#include "const.h"
#include "Singleton.hpp"
#include "MYSQLConPool.h"


class MysqlMgr : public Singleton<MysqlMgr>
{
	friend class Singleton<MysqlMgr>;

public:

	~MysqlMgr();
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

	MysqlMgr();

private:

	MysqlDao m_conPool;
};