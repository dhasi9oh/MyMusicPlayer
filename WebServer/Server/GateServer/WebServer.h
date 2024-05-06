// WebServer.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once
#include <string>
#include "const.h"
#include "HttpConnection.h"
#include "AsioIOServicePool.h"

class CServer :public std::enable_shared_from_this<CServer>
{
public:
	CServer(boost::asio::io_context& ioc, unsigned short& port);
	void Start();
private:
	tcp::acceptor  _acceptor;
	net::io_context& _ioc;

};
