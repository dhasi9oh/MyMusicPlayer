#include "RedirectWindow.h"

RedirectWindow::RedirectWindow(QWidget *parent)
	: TinyWidgetLibrary::RemovableMainWindow(parent)
{
	slotSwitchLogin();
	show();
}

RedirectWindow::~RedirectWindow()
{
}

void RedirectWindow::slotSwitchLogin()
{
	if (m_login == nullptr) {
		m_login = new LoginWindow(this);
		m_login->hide();
		connect(m_login, &LoginWindow::login_success, this, &RedirectWindow::slotSwitchMain);
		connect(m_login, &LoginWindow::register_button_clicked, this, &RedirectWindow::slotSwitchRegister);
	}

	setCentralWidget(m_login);
	if (m_register != nullptr) {
		m_register->hide();
	}
	m_login->show();
}

void RedirectWindow::slotSwitchReset()
{
}

void RedirectWindow::slotSwitchRegister()
{
	if (m_register == nullptr) {
		m_register = new RegisterWindow(this);
		m_register->hide();
		connect(m_register, &RegisterWindow::cancel_button_clicked, this, &RedirectWindow::slotSwitchLogin);
		connect(m_register, &RegisterWindow::register_success, this, &RedirectWindow::slotSwitchLogin);
	}

	setCentralWidget(m_register);
	m_login->hide();
	m_register->show();
}

void RedirectWindow::slotSwitchMain(ReqId id, QJsonObject obj, ErrorCodes err)
{
	if (m_main == nullptr) {
		m_main = new MainWindow(this);
		m_main->hide();
		emit m_main->login_success(id, obj, err);
	}

	setCentralWidget(m_main);
	m_login->hide();
	m_main->show();
}
