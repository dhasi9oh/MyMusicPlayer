#include "LoginWindow.h"

LoginWindow::LoginWindow(QWidget* parent)
		: QDialog(parent)
{
	initWidget();
	initHandle();
	initConnect();

	auto users = m_localUsr->getUsers();
	ui->numInput->getComboBox()->addItems(users);
}

LoginWindow::~LoginWindow()
{
	delete ui;
}

void LoginWindow::onLoginButtonClicked()
{
	if (!checkUserValid()) {
		showTip("请输入账号", false);
		return;
	}

	if (!checkPwdValid()) {
		showTip("请输入密码", false);
		return;
	}

	auto user = ui->numInput->getComboBox()->currentText();
	auto pwd = ui->pwdInput->getLineEdit()->text();
	//发送http请求获取验证码
	QJsonObject json_obj;
	json_obj["user"] = user;
	json_obj["passwd"] = xorString(pwd);
	HttpMgr::GetInstance()->postHttpReq(QUrl(gate_url_prefix + "/user_login"),
		json_obj, ReqId::ID_LOGIN_USER, Modules::LOGINMOD);
}

void LoginWindow::slotLoginModFinish(ReqId id, QByteArray res, ErrorCodes err, QJsonObject json)
{
	if (err != ErrorCodes::SUCCESS) {
		showTip(tr("网络请求错误"), false);
		return;
	}

	// 解析 JSON 字符串,res需转化为QByteArray
	QJsonDocument jsonDoc = QJsonDocument::fromJson(res);
	//json解析错误
	if (jsonDoc.isNull()) {
		showTip(tr("json解析错误"), false);
		return;
	}

	//json解析错误
	if (!jsonDoc.isObject()) {
		showTip(tr("json解析错误"), false);
		return;
	}

	//调用对应的逻辑,根据id回调。
	m_handlers[id](jsonDoc.object());
}

void LoginWindow::initWidget()
{
	ui = new Ui::LoginWindow();
	ui->setupUi(this);

	ui->numInput->setPlaceholderText("输入账号");
	ui->numInput->setFrameColor(QColor(90, 93, 97));
	ui->numInput->setTargetColor(QColor(255, 255, 255));
	ui->numInput->setBackgroundColor(QColor(90, 93, 97));
	ui->numInput->setFocusInFontColor(QColor(80, 80, 80));
	ui->numInput->setFocusOutFontColor(QColor(255, 255, 255));
	ui->numInput->setFocusInPlaceholderTextColor(QColor(150, 150, 150));
	ui->numInput->setFocusOutPlaceholderTextColor(QColor(255, 255, 255));

	ui->pwdInput->setPlaceholderText("输入密码");
	ui->pwdInput->getLineEdit()->setEchoMode(QLineEdit::Password);
	ui->pwdInput->setFrameColor(QColor(90, 93, 97));
	ui->pwdInput->setTargetColor(QColor(255, 255, 255));
	ui->pwdInput->setBackgroundColor(QColor(90, 93, 97));
	ui->pwdInput->setFocusInFontColor(QColor(80, 80, 80));
	ui->pwdInput->setFocusOutFontColor(QColor(255, 255, 255));
	ui->pwdInput->setFocusInPlaceholderTextColor(QColor(150, 150, 150));
	ui->pwdInput->setFocusOutPlaceholderTextColor(QColor(255, 255, 255));

	ui->loginButton->setFrameColor(QColor(80, 90, 100));
	ui->loginButton->setTriggerColor(QColor(80, 90, 100));

	ui->registerButton->setFrameColor(QColor(218, 218, 218));
	ui->registerButton->setTriggerColor(QColor(218, 218, 218));

	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}

void LoginWindow::initHandle()
{
	m_handlers.insert(ReqId::ID_LOGIN_USER,
		[this](const QJsonObject& obj)
		{
			int error = obj["error"].toInt();
			if (error != ErrorCodes::SUCCESS) {
				showTip(tr("参数错误"), false);
				return;
			}
			auto user = obj["user"].toString();
			showTip(tr("登录成功"), true);
			qDebug() << "user is " << user;

			emit login_success(obj);
		}
	);
}

void LoginWindow::initConnect()
{
	connect(ui->close, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->min, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->registerButton, &QPushButton::clicked, this, &LoginWindow::register_button_clicked);
	connect(HttpMgr::GetInstance().get(), &HttpMgr::signalLoginMod, this, &LoginWindow::slotLoginModFinish);
}

bool LoginWindow::checkPwdValid() const
{
	auto pwd = ui->pwdInput->getLineEdit()->text();
	if (pwd.length() < 6 || pwd.length() > 15) {
		qDebug() << "Pass length invalid";
		return false;
	}

	return true;
}

bool LoginWindow::checkUserValid() const
{
	auto user = ui->numInput->getComboBox()->currentText();
	if (user.isEmpty()) {
		qDebug() << "User empty ";
		return false;
	}

	return true;
}
