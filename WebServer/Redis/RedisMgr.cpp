#include "RedisMgr.h"

RedisMgr::RedisMgr() {
	auto& gCfgMgr = ConfigMgr::Inst();
	auto host = gCfgMgr["Redis"]["Host"];
	auto port = gCfgMgr["Redis"]["Port"];
	auto pwd = gCfgMgr["Redis"]["Passwd"];
	m_connPool.reset(new RedisConPool(5, host.c_str(), atoi(port.c_str()), pwd.c_str()));
}

RedisMgr::~RedisMgr() {
	m_connPool->Close();
}

bool RedisMgr::Get(const std::string& key, std::string& value)
{
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "GET %s", key.c_str());
	if (reply == NULL) {
		LOG_INFO("[ GET  {} ] failed", key);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	if (reply->type != REDIS_REPLY_STRING) {
		LOG_INFO("[ GET  {} ] failed", key);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	value = reply->str;
	freeReplyObject(reply);

	LOG_INFO("Succeed to execute command [ GET {} ]", key);
	m_connPool->returnConnection(connect);
	return true;
}

bool RedisMgr::Set(const std::string& key, const std::string& value) {
	//执行redis命令行
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "SET %s %s", key.c_str(), value.c_str());

	//如果返回NULL则说明执行失败
	if (NULL == reply)
	{
		LOG_INFO("Execut command [ SET {}  {} ] failure ! ", key, value);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	//如果执行失败则释放连接
	if (!(reply->type == REDIS_REPLY_STATUS && (strcmp(reply->str, "OK") == 0 || strcmp(reply->str, "ok") == 0)))
	{
		LOG_INFO("Execut command [ SET {}  {} ] failure ! ", key, value);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	//执行成功 释放redisCommand执行后返回的redisReply所占用的内存
	freeReplyObject(reply);
	LOG_INFO("Execut command [ SET {}  {} ] success ! ", key, value);
	m_connPool->returnConnection(connect);
	return true;
}

bool RedisMgr::LPush(const std::string& key, const std::string& value)
{
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "LPUSH %s %s", key.c_str(), value.c_str());
	if (NULL == reply)
	{
		LOG_INFO("Execut command [ LPUSH {}  {} ] failure ! ", key, value);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	if (reply->type != REDIS_REPLY_INTEGER || reply->integer <= 0) {
		LOG_INFO("Execut command [ LPUSH {}  {} ] failure ! ", key, value);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	LOG_INFO("Execut command [ LPUSH {}  {} ] success ! ", key, value);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}

bool RedisMgr::LPop(const std::string& key, std::string& value) {
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "LPOP %s ", key.c_str());
	if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
		LOG_INFO("Execut command [ LPOP {} ] failure ! ", key);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}
	value = reply->str;
	LOG_INFO("Execut command [ LPOP {} ] success ! ", key);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}

bool RedisMgr::RPush(const std::string& key, const std::string& value) {
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "RPUSH %s %s", key.c_str(), value.c_str());
	if (NULL == reply)
	{
		LOG_INFO("Execut command [ RPUSH {}  {} ] failure ! ", key, value);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	if (reply->type != REDIS_REPLY_INTEGER || reply->integer <= 0) {
		LOG_INFO("Execut command [ RPUSH {}  {} ] failure ! ", key, value);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}

	LOG_INFO("Execut command [ RPUSH {}  {} ] success ! ", key, value);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}
bool RedisMgr::RPop(const std::string& key, std::string& value) {
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "RPOP %s ", key.c_str());
	if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
		LOG_INFO("Execut command [ RPOP {} ] failure ! ", key);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}
	value = reply->str;
	LOG_INFO("Execut command [ RPOP {} ] success ! ", key);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}

bool RedisMgr::HSet(const std::string& key, const std::string& hkey, const std::string& value) {
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "HSET %s %s %s", key.c_str(), hkey.c_str(), value.c_str());
	if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
		LOG_INFO("Execut command [ HSet {}  {}  {} ] failure ! ", key, hkey, value);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}
	LOG_INFO("Execut command [ HSet {}  {}  {} ] success ! ", key, hkey, value);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}

bool RedisMgr::HSet(const char* key, const char* hkey, const char* hvalue, size_t hvaluelen)
{
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	const char* argv[4];
	size_t argvlen[4];
	argv[0] = "HSET";
	argvlen[0] = 4;
	argv[1] = key;
	argvlen[1] = strlen(key);
	argv[2] = hkey;
	argvlen[2] = strlen(hkey);
	argv[3] = hvalue;
	argvlen[3] = hvaluelen;

	auto reply = (redisReply*)redisCommandArgv(connect, 4, argv, argvlen);
	if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
		LOG_INFO("Execut command [ HSet {}  {}  {} ] failure ! ", key, hkey, hvalue);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}
	LOG_INFO("Execut command [ HSet {}  {}  {} ] success ! ", key, hkey, hvalue);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}

std::string RedisMgr::HGet(const std::string& key, const std::string& hkey)
{
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return "";
	}
	const char* argv[3];
	size_t argvlen[3];
	argv[0] = "HGET";
	argvlen[0] = 4;
	argv[1] = key.c_str();
	argvlen[1] = key.length();
	argv[2] = hkey.c_str();
	argvlen[2] = hkey.length();

	auto reply = (redisReply*)redisCommandArgv(connect, 3, argv, argvlen);
	if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
		freeReplyObject(reply);
		LOG_INFO("Execut command [ HSet {}  {} ] failure ! ", key, hkey);
		m_connPool->returnConnection(connect);
		return "";
	}

	std::string value = reply->str;
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	LOG_INFO("Execut command [ HSet {}  {} ] success ! ", key, hkey);
	return value;
}

bool RedisMgr::Del(const std::string& key)
{
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}
	auto reply = (redisReply*)redisCommand(connect, "DEL %s", key.c_str());
	if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
		LOG_INFO("Execut command [ Del {} ] failure ! ", key);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}
	LOG_INFO("Execut command [ Del {} ] success ! ", key);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}

bool RedisMgr::ExistsKey(const std::string& key)
{
	auto connect = m_connPool->getConnection();
	if (connect == nullptr) {
		return false;
	}

	auto reply = (redisReply*)redisCommand(connect, "exists %s", key.c_str());
	if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER || reply->integer == 0) {
		LOG_INFO("Not Found [ Key {} ] ! ", key);
		freeReplyObject(reply);
		m_connPool->returnConnection(connect);
		return false;
	}
	LOG_INFO(" Found [ Key {} ] exists ! ", key);
	freeReplyObject(reply);
	m_connPool->returnConnection(connect);
	return true;
}
