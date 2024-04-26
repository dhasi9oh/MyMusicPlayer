#include "HttpMgr.h"

HttpMgr::HttpMgr(QObject* parent)
	: QObject(parent)
{
}

HttpMgr::~HttpMgr()
{
}

void HttpMgr::postHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod)
{
	QByteArray data = QJsonDocument(json).toJson();
	//通过url构造请求
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));
	//发送请求，并处理响应, 获取自己的智能指针，构造伪闭包并增加智能指针引用计数
	auto self = shared_from_this();
	QNetworkReply * reply = m_manager.post(request, data);
	//设置信号和槽等待发送完成
	QObject::connect(reply, &QNetworkReply::finished, [reply, self, req_id, mod, json](){
		//处理错误的情况
		if(reply->error() != QNetworkReply::NoError){
			qDebug() << reply->errorString();
			//发送信号通知完成
			emit self->signalHttpFinish(req_id, "", ErrorCodes::ERR_NETWORK, mod, json);
			reply->deleteLater();
			return;
		}

		//无错误则读回请求
		QByteArray res = reply->readAll();

		//发送信号通知完成
		emit self->signalHttpFinish(req_id, res, ErrorCodes::SUCCESS, mod, json);
		reply->deleteLater();
		return;
	});
}

void HttpMgr::slotHttpFinish(ReqId id, QByteArray res, ErrorCodes err, Modules mod, QJsonObject json)
{
	//发送信号通知指定模块http响应结束
	switch (mod)
	{
	case REGISTERMOD:
		emit signalEnrollMod(id, res, err, json);
		break;
	case RESETMOD:
		emit signalResetMod(id, res, err, json);
		break;
	case LOGINMOD:
		emit signalLoginMod(id, res, err, json);
		break;
	case MUSICMOD:
		emit signalMusicMod(id, res, err, json);
		break;
	default:
		break;
	}
}



