#ifndef TCPCONN_H
#define TCPCONN_H

#include "const.h"
#include "Singleton.hpp"
#include <qsharedpointer.h>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>

class HttpMgr : public QObject, public Singleton<HttpMgr>,
				public std::enable_shared_from_this<HttpMgr>
{
	Q_OBJECT

	friend class Singleton<HttpMgr>;

signals:

	void signalLoginMod(ReqId, QByteArray, ErrorCodes, QJsonObject);
	void signalResetMod(ReqId, QByteArray, ErrorCodes, QJsonObject);
	void signalEnrollMod(ReqId, QByteArray, ErrorCodes, QJsonObject);
	void signalMusicMod(ReqId, QByteArray, ErrorCodes, QJsonObject);
	void signalHttpFinish(ReqId, QByteArray, ErrorCodes, Modules, QJsonObject);

public:

	virtual ~HttpMgr();

	void postHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod);

private slots:

	void slotHttpFinish(ReqId id, QByteArray res, ErrorCodes err, Modules mod, QJsonObject json);

private:

	explicit HttpMgr(QObject* parent = nullptr);

private:

	QNetworkAccessManager m_manager;

};

#endif // !TCPCONN_H
