#pragma once

#include "const.h"
#include "LogicSystem.h"

class LogicSystem;

class HttpConnection : public std::enable_shared_from_this<HttpConnection>
{
	friend class LogicSystem;
public:

	HttpConnection(boost::asio::io_context& ioc);
	virtual ~HttpConnection();

	void Start();
	void PreParseGetParam();
	tcp::socket& GetSocket() { return m_socket; }

private:
	void CheckDeadline();
	void WriteResponse();
	void HandleReq();

	tcp::socket								m_socket;
	beast::flat_buffer						m_buffer{ 8192 };	// The buffer for performing reads.
	http::request<http::dynamic_body>		m_request;			// The request message.
	http::response<http::dynamic_body>		m_response;			// The response message.
	net::steady_timer						deadline_
	{ m_socket.get_executor(), std::chrono::seconds(60) };	// The timer for putting a deadline on connection processing.
	std::string								m_getUrl;
	std::unordered_map<std::string, std::string> m_getParams;
};


