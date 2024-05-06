#include "RegisterWindow.h"

RegisterWindow::RegisterWindow(QWidget* parent)
	: TinyWidgetLibrary::RemovableWidget(parent)
{
	initWidget();
	initHandle();
	initConnect();
}

RegisterWindow::~RegisterWindow()
{
	delete ui;
}

void RegisterWindow::onRegisterButtonClicked()
{
	if (!checkUserValid()) {
		showTip("请输入账号", false);
		return;
	}

	if (!checkPwdValid()) {
		showTip("请输入密码", false);
		return;
	}

	if (!checkConfirmValid()) {
		showTip("请再次输入密码", false);
		return;
	}

	if (!checkEmailValid()) {
		showTip("请输入邮箱", false);
		return;
	}

	auto user = ui->usrInput->getLineEdit()->text();
	auto pwd = ui->pwdInput->getLineEdit()->text();
	auto confirm = ui->pwdAgainInput->getLineEdit()->text();
	auto email = ui->email->getLineEdit()->text();

	QJsonObject json_obj;
	json_obj["user"] = user;
	json_obj["passwd"] = pwd;
	json_obj["confirm"] = confirm;
	json_obj["email"] = email;

	HttpMgr::GetInstance()->postHttpReq(QUrl(gate_url_prefix + "/user_register"),
		json_obj, ReqId::ID_REG_USER, Modules::REGISTERMOD);
}

void RegisterWindow::onGetVarifyCodeButtonClicked()
{
	if (!checkEmailValid()) {
		showTip("请输入邮箱", false);
		return;
	}

	auto email = ui->email->getLineEdit()->text();

	QJsonObject json_obj;
	json_obj["email"] = email;

	HttpMgr::GetInstance()->postHttpReq(QUrl(gate_url_prefix + "/get_varifycode"),
		json_obj, ReqId::ID_GET_VARIFY_CODE, Modules::REGISTERMOD);
}

void RegisterWindow::slotRegsterModFinish(ReqId id, QByteArray res, ErrorCodes err, QJsonObject json)
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

void RegisterWindow::initWidget()
{
	ui = new Ui::RegisterWindow;
	ui->setupUi(this);
	initMove();

	ui->usrInput->setPlaceholderText("输入注册的账号");
	ui->usrInput->setFrameColor(QColor(90, 93, 97));
	ui->usrInput->setTargetColor(QColor(255, 255, 255));
	ui->usrInput->setBackgroundColor(QColor(90, 93, 97));
	ui->usrInput->setFocusInFontColor(QColor(80, 80, 80));
	ui->usrInput->setFocusOutFontColor(QColor(255, 255, 255));
	ui->usrInput->setFocusInPlaceholderTextColor(QColor(150, 150, 150));
	ui->usrInput->setFocusOutPlaceholderTextColor(QColor(255, 255, 255));

	ui->pwdInput->setPlaceholderText("输入注册密码");
	ui->pwdInput->getLineEdit()->setEchoMode(QLineEdit::Password);
	ui->pwdInput->setFrameColor(QColor(90, 93, 97));
	ui->pwdInput->setTargetColor(QColor(255, 255, 255));
	ui->pwdInput->setBackgroundColor(QColor(90, 93, 97));
	ui->pwdInput->setFocusInFontColor(QColor(80, 80, 80));
	ui->pwdInput->setFocusOutFontColor(QColor(255, 255, 255));
	ui->pwdInput->setFocusInPlaceholderTextColor(QColor(150, 150, 150));
	ui->pwdInput->setFocusOutPlaceholderTextColor(QColor(255, 255, 255));

	ui->pwdAgainInput->setPlaceholderText("再次输入注册密码");
	ui->pwdAgainInput->getLineEdit()->setEchoMode(QLineEdit::Password);
	ui->pwdAgainInput->setFrameColor(QColor(90, 93, 97));
	ui->pwdAgainInput->setTargetColor(QColor(255, 255, 255));
	ui->pwdAgainInput->setBackgroundColor(QColor(90, 93, 97));
	ui->pwdAgainInput->setFocusInFontColor(QColor(80, 80, 80));
	ui->pwdAgainInput->setFocusOutFontColor(QColor(255, 255, 255));
	ui->pwdAgainInput->setFocusInPlaceholderTextColor(QColor(150, 150, 150));
	ui->pwdAgainInput->setFocusOutPlaceholderTextColor(QColor(255, 255, 255));

	ui->registerButton->setFrameColor(QColor(80, 90, 100));
	ui->registerButton->setTriggerColor(QColor(80, 90, 100));

	ui->cancelButton->setFrameColor(QColor(218, 218, 218));
	ui->cancelButton->setTriggerColor(QColor(218, 218, 218));

	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}

void RegisterWindow::initHandle()
{
	m_handlers.insert(ReqId::ID_REG_USER,
		[this](const QJsonObject& obj)
		{
			int error = obj["error"].toInt();
			if (error != ErrorCodes::SUCCESS) {
				showTip(tr("参数错误"), false);
				return;
			}
			auto user = obj["user"].toString();
			showTip(tr("注册成功"), true);
			qDebug() << "user is " << user;

			emit register_success();
		}
	);

	m_handlers.insert(ReqId::ID_GET_VARIFY_CODE,
		[this](const QJsonObject& obj)
		{
			int error = obj["error"].toInt();
			if (error != ErrorCodes::SUCCESS) {
				showTip(tr("参数错误"), false);
				return;
			}
			auto user = obj["user"].toString();
			showTip(tr("获取验证码成功"), true);
			qDebug() << "email is " << user;
		}
	);
}

void RegisterWindow::initConnect()
{
	connect(ui->close, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->min, &QPushButton::clicked, this, &QWidget::showMinimized);
	connect(ui->cancelButton, &QPushButton::clicked, [&] { emit cancel_button_clicked(); });
}

bool RegisterWindow::checkPwdValid() const
{
	auto pwd = ui->pwdInput->getLineEdit()->text();
	if (pwd.length() < 6 || pwd.length() > 15) {
		qDebug() << "Pass length invalid";
		return false;
	}

	return true;
}

bool RegisterWindow::checkUserValid() const
{
	auto user = ui->usrInput->getLineEdit()->text();
	if (user.isEmpty()) {
		qDebug() << "User empty ";
		return false;
	}

	return true;
}

bool RegisterWindow::checkEmailValid() const
{
	auto email = ui->email->getLineEdit()->text();
	if (email.isEmpty()) {
		qDebug() << "User empty ";
		return false;
	}

	return true;
}

bool RegisterWindow::checkConfirmValid() const
{
	auto confirm = ui->pwdAgainInput->getLineEdit()->text();
	if (confirm.isEmpty()) {
		qDebug() << "confirm empty ";
		return false;
	}

	return true;
}
