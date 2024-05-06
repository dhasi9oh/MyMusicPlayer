/********************************************************************************
** Form generated from reading UI file 'FileSongItem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESONGITEM_H
#define UI_FILESONGITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileSongItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *song_message;
    QHBoxLayout *horizontalLayout_2;
    QLabel *number;
    QWidget *message;
    QVBoxLayout *verticalLayout_2;
    QLabel *song_name;
    QPushButton *remove_button;

    void setupUi(QWidget *FileSongItem)
    {
        if (FileSongItem->objectName().isEmpty())
            FileSongItem->setObjectName("FileSongItem");
        FileSongItem->resize(286, 61);
        verticalLayout = new QVBoxLayout(FileSongItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        song_message = new QWidget(FileSongItem);
        song_message->setObjectName("song_message");
        song_message->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(60, 63, 66);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(song_message);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        number = new QLabel(song_message);
        number->setObjectName("number");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(number->sizePolicy().hasHeightForWidth());
        number->setSizePolicy(sizePolicy);
        number->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        number->setFont(font);
        number->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"}"));
        number->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(number);

        message = new QWidget(song_message);
        message->setObjectName("message");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(6);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(message->sizePolicy().hasHeightForWidth());
        message->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(message);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 0, 5, 0);
        song_name = new QLabel(message);
        song_name->setObjectName("song_name");
        song_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"}"));

        verticalLayout_2->addWidget(song_name);


        horizontalLayout_2->addWidget(message);

        remove_button = new QPushButton(song_message);
        remove_button->setObjectName("remove_button");
        sizePolicy.setHeightForWidth(remove_button->sizePolicy().hasHeightForWidth());
        remove_button->setSizePolicy(sizePolicy);
        remove_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/remove.png);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(35, 35, 35);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(40, 40, 40);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        remove_button->setIcon(icon);
        remove_button->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(remove_button);


        verticalLayout->addWidget(song_message);


        retranslateUi(FileSongItem);

        QMetaObject::connectSlotsByName(FileSongItem);
    } // setupUi

    void retranslateUi(QWidget *FileSongItem)
    {
        FileSongItem->setWindowTitle(QCoreApplication::translate("FileSongItem", "Form", nullptr));
        number->setText(QCoreApplication::translate("FileSongItem", "01", nullptr));
        song_name->setText(QCoreApplication::translate("FileSongItem", "TextLabel", nullptr));
        remove_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileSongItem: public Ui_FileSongItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESONGITEM_H
