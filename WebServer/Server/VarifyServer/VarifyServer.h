#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <grpcpp/grpcpp.h>

#include "const.h"
#include "ConfigMgr.h"
#include "BlockQueue.h"
#include "Singleton.hpp"
#include "message.grpc.pb.h"


using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;

using message::GetVarifyReq;
using message::GetVarifyRsp;
using message::VarifyService;

class RPConPool {
public:
	RPConPool(size_t poolSize, std::string host, std::string port)
		: m_connections(poolSize), m_host(host), m_port(port)
	{
		for (size_t i = 0; i < poolSize; ++i) {

			std::shared_ptr<Channel> channel = grpc::CreateChannel(host + ":" + port,
				grpc::InsecureChannelCredentials());

			m_connections.push(VarifyService::NewStub(channel));
		}
	}

	~RPConPool()
	{
		m_connections.close();
		auto deq = m_connections.residualData();
		while (!deq.empty()) {
			deq.pop_back();
		}
	}

	std::shared_ptr<VarifyService::Stub> getConnection()
	{
		std::shared_ptr<VarifyService::Stub> context;
		m_connections.pop(context);
		return context;
	}

	void returnConnection(std::shared_ptr<VarifyService::Stub> context)
	{
		m_connections.push(context);
	}

	void Close()
	{
		m_connections.close();
	}

private:

	std::string m_host;
	std::string m_port;
	BlockQueue<std::shared_ptr<VarifyService::Stub>> m_connections;

};

class VerifyGrpcClient :public Singleton<VerifyGrpcClient>
{
	friend class Singleton<VerifyGrpcClient>;
public:

	~VerifyGrpcClient()
	{
	}

	GetVarifyRsp GetVarifyCode(std::string email)
	{
		ClientContext context;
		GetVarifyRsp reply;
		GetVarifyReq request;
		request.set_email(email);
		auto stub = m_pool->getConnection();
		Status status = stub->GetVarifyCode(&context, request, &reply);

		if (status.ok()) {
			m_pool->returnConnection(stub);
			return reply;
		}
		else {
			m_pool->returnConnection(stub);
			reply.set_error(ErrorCodes::RPCFailed);
			return reply;
		}
	}

private:

	VerifyGrpcClient();
	std::unique_ptr<RPConPool> m_pool;
};
