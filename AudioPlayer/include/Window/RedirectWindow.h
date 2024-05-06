#pragma once

#include <qsharedpointer.h>

#include "MainWindow.h"
#include "LoginWindow.h"
#include "RegisterWindow.h"

class RedirectWindow : public QObject
{
	Q_OBJECT

public:

	explicit RedirectWindow(QWidget *parent = nullptr);

	virtual ~RedirectWindow();

private slots:

	void	slotSwitchLogin();
	void	slotSwitchReset();
	void	slotSwitchRegister();
	void	slotSwitchMain(const QJsonObject &obj);

private:

	QScopedPointer<MainWindow> m_main;
	QScopedPointer<LoginWindow> m_login;
	QScopedPointer<RegisterWindow> m_register;

};
