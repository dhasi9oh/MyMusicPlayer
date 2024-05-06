#pragma once

#include <map>
#include <functional>

#include "const.h"
#include "RedisMgr.h"
#include "MYSQLMgr.h"
#include "Singleton.hpp"
#include "HttpConnection.h"
#include "VarifyServer.h"

class HttpConnection;
typedef std::function<void(std::shared_ptr<HttpConnection>)> HttpHandler;

class LogicSystem :public Singleton<LogicSystem>
{
	friend class Singleton<LogicSystem>;
public:

	virtual ~LogicSystem();

	void RegGet(std::string, HttpHandler handler);
	void RegPost(std::string, HttpHandler handler);
	bool HandleGet(std::string, std::shared_ptr<HttpConnection>);
	bool HandlePost(std::string, std::shared_ptr<HttpConnection>);

private:

	LogicSystem();

private:

	std::map<std::string, HttpHandler> m_getHandlers;
	std::map<std::string, HttpHandler> m_postHandlers;
};
