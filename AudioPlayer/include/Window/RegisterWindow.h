//
// Created by 86186 on 2024/3/11.
//

#ifndef AUDIOPLAYER_REGISTERWINDOW_H
#define AUDIOPLAYER_REGISTERWINDOW_H

#include <qwidget.h>
#include <qgraphicseffect.h>

#include "const.h"
#include "HttpMgr.h"
#include "ui_RegisterWindow.h"
#include "Helper/Window/RemovableWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class RegisterWindow;
};
QT_END_NAMESPACE

class RegisterWindow : public TinyWidgetLibrary::RemovableWidget
{
	Q_OBJECT

signals:

	void	register_success();
	void	cancel_button_clicked();

public:

	explicit RegisterWindow(QWidget* parent = nullptr);
	virtual ~RegisterWindow();

private slots:

	void	onRegisterButtonClicked();
	void	onGetVarifyCodeButtonClicked();
	void	slotRegsterModFinish(ReqId id, QByteArray res, ErrorCodes err, QJsonObject json);

private:

	void	initWidget();
	void	initHandle();
	void	initConnect();
	bool	checkPwdValid() const;
	bool	checkUserValid() const;
	bool	checkEmailValid() const;
	bool	checkConfirmValid() const;

private:

	Ui::RegisterWindow* ui;
	QMap<ReqId, std::function<void(const QJsonObject&)>> m_handlers;
};


#endif //AUDIOPLAYER_REGISTERWINDOW_H
