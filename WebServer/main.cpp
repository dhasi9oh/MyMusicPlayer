#include <stdio.h>
#include "WebServer.h"

extern "C" {
    void *__wrap_memcpy(void *dest, const void *src, size_t n) {
        // 这里可以添加你自己的代码

        // 调用真正的memcpy函数
        return memcpy(dest, src, n);
    }
}


int main()
{
	try
	{
		MysqlMgr::GetInstance();
		RedisMgr::GetInstance();
		auto & gCfgMgr = ConfigMgr::Inst();
		std::string gate_port_str = gCfgMgr["GateServer"]["Port"];
		unsigned short gate_port = atoi(gate_port_str.c_str());
		net::io_context ioc{ 1 };
		boost::asio::signal_set signals(ioc, SIGINT, SIGTERM);
		signals.async_wait([&ioc](const boost::system::error_code& error, int signal_number) {
			if (error) {
				return;
			}
			ioc.stop();
			});
		std::make_shared<CServer>(ioc, gate_port)->Start();
		std::cout << "Gate Server listen on port: " << gate_port << std::endl;
		ioc.run();
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}