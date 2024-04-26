#pragma once

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <queue>
#include <memory>
#include <assert.h>
#include <iostream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>
#include <unordered_map>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/filesystem.hpp>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include "Singleton.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
namespace filesystem = boost::filesystem; // from <boost/filesystem.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


enum ErrorCodes {
	Success = 0,
	Error_Json = 1001,  //Json解析错误
	RPCFailed = 1002,  //RPC请求错误
	VarifyExpired = 1003, //验证码过期
	VarifyCodeErr = 1004, //验证码错误
	UserExist = 1005,       //用户已经存在
	PasswdErr = 1006,    //密码错误
	EmailNotMatch = 1007,  //邮箱不匹配
	PasswdUpFailed = 1008,  //更新密码失败
	PasswdInvalid = 1009,   //密码更新失败
	RPCGetFailed = 1010,  //获取rpc请求失败
	FileGetFailed = 1011, //获取文件失败
	AddToSongListFailed = 1012, //将歌曲添加进歌单失败
	RemoveFromSongListFailed = 1013, //将歌曲移除歌单失败
	GetPersonalSongListFailed = 1014, //获取个人歌单失败
	SearchSongNameFailed = 1015, //搜索歌曲失败
};

// Defer类
class Defer {
public:
	// 接受一个lambda表达式或者函数指针
	Defer(std::function<void()> func) : func_(func) {}

	// 析构函数中执行传入的函数
	~Defer() {
		func_();
	}

private:
	std::function<void()> func_;
};


#define CODEPREFIX  "code_"