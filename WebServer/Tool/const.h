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
	Error_Json = 1001,  //Json��������
	RPCFailed = 1002,  //RPC�������
	VarifyExpired = 1003, //��֤�����
	VarifyCodeErr = 1004, //��֤�����
	UserExist = 1005,       //�û��Ѿ�����
	PasswdErr = 1006,    //�������
	EmailNotMatch = 1007,  //���䲻ƥ��
	PasswdUpFailed = 1008,  //��������ʧ��
	PasswdInvalid = 1009,   //�������ʧ��
	RPCGetFailed = 1010,  //��ȡrpc����ʧ��
	FileGetFailed = 1011, //��ȡ�ļ�ʧ��
	AddToSongListFailed = 1012, //��������ӽ��赥ʧ��
	RemoveFromSongListFailed = 1013, //�������Ƴ��赥ʧ��
	GetPersonalSongListFailed = 1014, //��ȡ���˸赥ʧ��
	SearchSongNameFailed = 1015, //��������ʧ��
};

// Defer��
class Defer {
public:
	// ����һ��lambda���ʽ���ߺ���ָ��
	Defer(std::function<void()> func) : func_(func) {}

	// ����������ִ�д���ĺ���
	~Defer() {
		func_();
	}

private:
	std::function<void()> func_;
};


#define CODEPREFIX  "code_"