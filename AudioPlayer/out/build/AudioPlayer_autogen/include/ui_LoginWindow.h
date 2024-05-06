/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Buttons/RectangleButton/StandardButton.h"
#include "TextBox/ComboBox.h"
#include "TextBox/TextBox.h"

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *login;
    QVBoxLayout *verticalLayout_2;
    QWidget *topBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *min;
    QPushButton *close;
    QWidget *middleBar;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QWidget *inputBar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QFrame *inputFrame;
    QVBoxLayout *verticalLayout;
    TinyWidgetLibrary::ComboBox *numInput;
    TinyWidgetLibrary::TextBox *pwdInput;
    QSpacerItem *horizontalSpacer_5;
    QWidget *buttonBar;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    TinyWidgetLibrary::StandardButton *loginButton;
    QSpacerItem *horizontalSpacer_9;
    TinyWidgetLibrary::StandardButton *registerButton;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(300, 350);
        verticalLayout_3 = new QVBoxLayout(LoginWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        login = new QWidget(LoginWindow);
        login->setObjectName("login");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setMinimumSize(QSize(0, 0));
        login->setMaximumSize(QSize(16777215, 16777215));
        login->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(50, 53, 58);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(login);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 5);
        topBar = new QWidget(login);
        topBar->setObjectName("topBar");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(topBar->sizePolicy().hasHeightForWidth());
        topBar->setSizePolicy(sizePolicy1);
        topBar->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(40, 42, 45);\n"
"}"));
        horizontalLayout = new QHBoxLayout(topBar);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        min = new QPushButton(topBar);
        min->setObjectName("min");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(min->sizePolicy().hasHeightForWidth());
        min->setSizePolicy(sizePolicy2);
        min->setMinimumSize(QSize(30, 30));
        min->setMaximumSize(QSize(30, 30));
        min->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/zuixiaohua.png);\n"
"	background-color: rgb(60, 65, 70);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(70, 75, 80);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(55, 56, 62);\n"
"}"));
        min->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(min);

        close = new QPushButton(topBar);
        close->setObjectName("close");
        close->setMinimumSize(QSize(30, 30));
        close->setMaximumSize(QSize(30, 30));
        close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: none;\n"
"	icon: url(:/image/guanbi.png);\n"
"	background-color: rgb(240, 80, 70);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color:rgb(220, 60, 40)\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(210, 40, 20);\n"
"}\n"
""));

        horizontalLayout->addWidget(close);


        verticalLayout_2->addWidget(topBar);

        middleBar = new QWidget(login);
        middleBar->setObjectName("middleBar");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(4);
        sizePolicy3.setHeightForWidth(middleBar->sizePolicy().hasHeightForWidth());
        middleBar->setSizePolicy(sizePolicy3);
        horizontalLayout_5 = new QHBoxLayout(middleBar);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label = new QLabel(middleBar);
        label->setObjectName("label");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setMinimumSize(QSize(100, 100));
        label->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(middleBar);

        inputBar = new QWidget(login);
        inputBar->setObjectName("inputBar");
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(6);
        sizePolicy5.setHeightForWidth(inputBar->sizePolicy().hasHeightForWidth());
        inputBar->setSizePolicy(sizePolicy5);
        horizontalLayout_2 = new QHBoxLayout(inputBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(6, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        inputFrame = new QFrame(inputBar);
        inputFrame->setObjectName("inputFrame");
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(inputFrame->sizePolicy().hasHeightForWidth());
        inputFrame->setSizePolicy(sizePolicy6);
        verticalLayout = new QVBoxLayout(inputFrame);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        numInput = new TinyWidgetLibrary::ComboBox(inputFrame);
        numInput->setObjectName("numInput");
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(numInput->sizePolicy().hasHeightForWidth());
        numInput->setSizePolicy(sizePolicy7);
        QFont font;
        font.setPointSize(11);
        numInput->setFont(font);

        verticalLayout->addWidget(numInput);

        pwdInput = new TinyWidgetLibrary::TextBox(inputFrame);
        pwdInput->setObjectName("pwdInput");
        sizePolicy7.setHeightForWidth(pwdInput->sizePolicy().hasHeightForWidth());
        pwdInput->setSizePolicy(sizePolicy7);
        pwdInput->setFont(font);

        verticalLayout->addWidget(pwdInput);


        horizontalLayout_2->addWidget(inputFrame);

        horizontalSpacer_5 = new QSpacerItem(6, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(inputBar);

        buttonBar = new QWidget(login);
        buttonBar->setObjectName("buttonBar");
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(2);
        sizePolicy8.setHeightForWidth(buttonBar->sizePolicy().hasHeightForWidth());
        buttonBar->setSizePolicy(sizePolicy8);
        horizontalLayout_3 = new QHBoxLayout(buttonBar);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        loginButton = new TinyWidgetLibrary::StandardButton(buttonBar);
        loginButton->setObjectName("loginButton");
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy9);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calisto MT")});
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        loginButton->setFont(font1);
        loginButton->setCursor(QCursor(Qt::PointingHandCursor));
        loginButton->setMouseTracking(true);
        loginButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(loginButton);

        horizontalSpacer_9 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        registerButton = new TinyWidgetLibrary::StandardButton(buttonBar);
        registerButton->setObjectName("registerButton");
        sizePolicy9.setHeightForWidth(registerButton->sizePolicy().hasHeightForWidth());
        registerButton->setSizePolicy(sizePolicy9);
        registerButton->setFont(font1);
        registerButton->setCursor(QCursor(Qt::PointingHandCursor));
        registerButton->setMouseTracking(true);
        registerButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(registerButton);

        horizontalSpacer_10 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);


        verticalLayout_2->addWidget(buttonBar);


        verticalLayout_3->addWidget(login);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        min->setText(QString());
        close->setText(QString());
        label->setText(QString());
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
