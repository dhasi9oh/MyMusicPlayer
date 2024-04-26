#include "MYSQLMgr.h"

MysqlMgr::~MysqlMgr()
{
}

bool MysqlMgr::CheckEmail(const std::string& name, const std::string& email)
{
	return m_conPool.CheckEmail(name, email);
}

bool MysqlMgr::UpdatePwd(const std::string& name, const std::string& newpwd)
{
	return m_conPool.UpdatePwd(name, newpwd);
}

bool MysqlMgr::SearchSong(const std::string& song_name, Json::Value& value)
{
	return m_conPool.SearchSong(song_name, value);
}

bool MysqlMgr::CheckPwd(const std::string& name, const std::string& pwd, UserInfo& userInfo)
{
	return m_conPool.CheckPwd(name, pwd, userInfo);
}

int MysqlMgr::CheckSongExist(int uid, const std::string& singer, const std::string& song_name)
{
	return m_conPool.CheckSongExist(uid, singer, song_name);
}

bool MysqlMgr::LoginUser(int uid, Json::Value& value)
{
	return  m_conPool.LoginUser(uid, value);
}

int MysqlMgr::RegUser(const std::string& name, const std::string& email, const std::string& pwd)
{
	return m_conPool.RegUser(name, email, pwd);
}

bool MysqlMgr::GetMusicFilePath(const std::string& singer, const std::string& song_name, std::string& path)
{
	return GetMusicFilePath(singer, song_name, path);
}

bool MysqlMgr::AddSongToSongList(int uid, const std::string& singer, const std::string& song_name)
{
	return m_conPool.AddSongToSongList(uid, singer, song_name);
}

bool MysqlMgr::RemoveSongFromSongList(int uid, const std::string& singer, const std::string& song_name)
{
	return m_conPool.RemoveSongFromSongList(uid, singer, song_name);
}

MysqlMgr::MysqlMgr()
{
}
