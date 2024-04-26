//
// Created by 86186 on 2024/3/11.
//

#ifndef AUDIOPLAYER_LOGINWINDOW_H
#define AUDIOPLAYER_LOGINWINDOW_H

#include <qwidget.h>
#include <qgraphicseffect.h>

#include "ui_LoginWindow.h"

#include "const.h"
#include "HttpMgr.h"
#include "LocalUsr.h"
#include "Helper/Window/RemovableWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class LoginWindow;
};
QT_END_NAMESPACE

class LoginWindow : public QDialog
{
	Q_OBJECT

signals:

	void	login_success(QJsonObject);
	void	register_button_clicked();

public:

	explicit LoginWindow(QWidget* parent = nullptr);
	virtual ~LoginWindow();
	
private slots:

	void	onLoginButtonClicked();
	void	slotLoginModFinish(ReqId id, QByteArray res, ErrorCodes err, QJsonObject json);

private:

	void	initWidget();
	void	initHandle();
	void	initConnect();
	bool	checkPwdValid() const;
	bool	checkUserValid() const;

private:

	Ui::LoginWindow *ui;
	LocalUsr *m_localUsr;
	QMap<ReqId, std::function<void(const QJsonObject&)>> m_handlers;

};


#endif //AUDIOPLAYER_LOGINWINDOW_H
