#include "RedirectWindow.h"

RedirectWindow::RedirectWindow(QWidget *parent)
	: QObject(parent)
{
	slotSwitchLogin();
}

RedirectWindow::~RedirectWindow()
{
}

void RedirectWindow::slotSwitchLogin()
{
	if (m_login.isNull()) {
		m_login.reset(new LoginWindow());
		m_login->hide();
		connect(m_login.get(), &LoginWindow::login_success, this, &RedirectWindow::slotSwitchMain);
		connect(m_login.get(), &LoginWindow::register_button_clicked, this, &RedirectWindow::slotSwitchRegister);
	}

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
		m_register.reset(new RegisterWindow());
		m_register->hide();
		connect(m_register.get(), &RegisterWindow::cancel_button_clicked, this, &RedirectWindow::slotSwitchLogin);
		connect(m_register.get(), &RegisterWindow::register_success, this, &RedirectWindow::slotSwitchLogin);
	}

	m_login->hide();
	m_register->show();
}

void RedirectWindow::slotSwitchMain(const QJsonObject& obj)
{
	if (m_main == nullptr) {
		m_main.reset(new MainWindow(obj));
		m_main->hide();
	}

	m_login->hide();
	m_main->show();

	m_login.reset();
	m_register.reset();
}
