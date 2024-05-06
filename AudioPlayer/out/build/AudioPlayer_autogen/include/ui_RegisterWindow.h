/********************************************************************************
** Form generated from reading UI file 'RegisterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Buttons/RectangleButton/StandardButton.h"
#include "TextBox/TextBox.h"

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *window;
    QVBoxLayout *verticalLayout_2;
    QWidget *topBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *min;
    QPushButton *close;
    QWidget *inputBar;
    QHBoxLayout *horizontalLayout_2;
    QFrame *inputFrame;
    QVBoxLayout *verticalLayout;
    TinyWidgetLibrary::TextBox *usrInput;
    TinyWidgetLibrary::TextBox *pwdInput;
    TinyWidgetLibrary::TextBox *pwdAgainInput;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    TinyWidgetLibrary::TextBox *email;
    TinyWidgetLibrary::StandardButton *send;
    QWidget *ButtonBar;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    TinyWidgetLibrary::StandardButton *registerButton;
    QSpacerItem *horizontalSpacer_9;
    TinyWidgetLibrary::StandardButton *cancelButton;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(318, 350);
        verticalLayout_3 = new QVBoxLayout(RegisterWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        window = new QWidget(RegisterWindow);
        window->setObjectName("window");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(window->sizePolicy().hasHeightForWidth());
        window->setSizePolicy(sizePolicy);
        window->setMinimumSize(QSize(0, 0));
        window->setMaximumSize(QSize(16777215, 16777215));
        window->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(50, 53, 58);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(window);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 10);
        topBar = new QWidget(window);
        topBar->setObjectName("topBar");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(topBar->sizePolicy().hasHeightForWidth());
        topBar->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(topBar);
        horizontalLayout->setObjectName("horizontalLayout");
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

        inputBar = new QWidget(window);
        inputBar->setObjectName("inputBar");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(3);
        sizePolicy3.setHeightForWidth(inputBar->sizePolicy().hasHeightForWidth());
        inputBar->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(inputBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        inputFrame = new QFrame(inputBar);
        inputFrame->setObjectName("inputFrame");
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(inputFrame->sizePolicy().hasHeightForWidth());
        inputFrame->setSizePolicy(sizePolicy4);
        verticalLayout = new QVBoxLayout(inputFrame);
        verticalLayout->setObjectName("verticalLayout");
        usrInput = new TinyWidgetLibrary::TextBox(inputFrame);
        usrInput->setObjectName("usrInput");

        verticalLayout->addWidget(usrInput);

        pwdInput = new TinyWidgetLibrary::TextBox(inputFrame);
        pwdInput->setObjectName("pwdInput");

        verticalLayout->addWidget(pwdInput);

        pwdAgainInput = new TinyWidgetLibrary::TextBox(inputFrame);
        pwdAgainInput->setObjectName("pwdAgainInput");

        verticalLayout->addWidget(pwdAgainInput);

        widget = new QWidget(inputFrame);
        widget->setObjectName("widget");
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        email = new TinyWidgetLibrary::TextBox(widget);
        email->setObjectName("email");
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(3);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(email->sizePolicy().hasHeightForWidth());
        email->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(email);

        send = new TinyWidgetLibrary::StandardButton(widget);
        send->setObjectName("send");
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(send->sizePolicy().hasHeightForWidth());
        send->setSizePolicy(sizePolicy6);

        horizontalLayout_4->addWidget(send);


        verticalLayout->addWidget(widget);


        horizontalLayout_2->addWidget(inputFrame);


        verticalLayout_2->addWidget(inputBar);

        ButtonBar = new QWidget(window);
        ButtonBar->setObjectName("ButtonBar");
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(1);
        sizePolicy7.setHeightForWidth(ButtonBar->sizePolicy().hasHeightForWidth());
        ButtonBar->setSizePolicy(sizePolicy7);
        horizontalLayout_3 = new QHBoxLayout(ButtonBar);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 10, 0, 10);
        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        registerButton = new TinyWidgetLibrary::StandardButton(ButtonBar);
        registerButton->setObjectName("registerButton");
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(registerButton->sizePolicy().hasHeightForWidth());
        registerButton->setSizePolicy(sizePolicy8);
        QFont font;
        font.setFamilies({QString::fromUtf8("Calisto MT")});
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        registerButton->setFont(font);
        registerButton->setCursor(QCursor(Qt::PointingHandCursor));
        registerButton->setMouseTracking(true);
        registerButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(registerButton);

        horizontalSpacer_9 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        cancelButton = new TinyWidgetLibrary::StandardButton(ButtonBar);
        cancelButton->setObjectName("cancelButton");
        sizePolicy8.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy8);
        cancelButton->setFont(font);
        cancelButton->setCursor(QCursor(Qt::PointingHandCursor));
        cancelButton->setMouseTracking(true);
        cancelButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(cancelButton);

        horizontalSpacer_10 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);


        verticalLayout_2->addWidget(ButtonBar);


        verticalLayout_3->addWidget(window);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Form", nullptr));
        min->setText(QString());
        close->setText(QString());
        send->setText(QCoreApplication::translate("RegisterWindow", "PushButton", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "\346\263\250\345\206\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("RegisterWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
