#pragma once

#include <qsharedpointer.h>

#include "MainWindow.h"
#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "Helper/Window/RemovableWindow.h"

class RedirectWindow : public TinyWidgetLibrary::RemovableMainWindow
{
	Q_OBJECT

public:

	explicit RedirectWindow(QWidget *parent = nullptr);

	virtual ~RedirectWindow();

private slots:

	void	slotSwitchLogin();
	void	slotSwitchReset();
	void	slotSwitchRegister();
	void	slotSwitchMain(ReqId, QJsonObject, ErrorCodes);

private:

	MainWindow* m_main;
	LoginWindow* m_login;
	RegisterWindow* m_register;

};
