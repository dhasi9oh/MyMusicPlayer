#pragma once

#include "Loger.h"
#include "RedisMgr.h"
#include "BlockQueue.h"

#include <atomic>

class RedisConPool {
public:

    RedisConPool(size_t poolSize, const char* host, int port, const char* pwd)
        : m_connections(poolSize), host_(host), port_(port)
    {
        for (size_t i = 0; i < poolSize; ++i) {
            auto* context = redisConnect(host, port);
            if (context == nullptr || context->err != 0) {
                if (context != nullptr) {
                    redisFree(context);
                }
                continue;
            }
            auto reply = (redisReply*)redisCommand(context, "AUTH %s", pwd);
            if (reply->type == REDIS_REPLY_ERROR) {
                LOG_INFO("��֤ʧ��");
                //ִ�гɹ� �ͷ�redisCommandִ�к󷵻ص�redisReply��ռ�õ��ڴ�
                freeReplyObject(reply);
                continue;
            }
            //ִ�гɹ� �ͷ�redisCommandִ�к󷵻ص�redisReply��ռ�õ��ڴ�
            freeReplyObject(reply);
            std::cout << "��֤�ɹ�" << std::endl;
            m_connections.push(context);
        }
    }

    ~RedisConPool()
    {
        Close();
    }

    redisContext* getConnection()
    {
        redisContext* context = nullptr;
        m_connections.pop(context);
        return context;
    }

    void returnConnection(redisContext* context)
    {
        m_connections.push(context);
    }

    void Close()
    {
        m_connections.close();
    }

private:

    int port_;
    const char* host_;
    BlockQueue<redisContext*> m_connections;
};