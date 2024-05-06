/********************************************************************************
** Form generated from reading UI file 'SongItem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGITEM_H
#define UI_SONGITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *song_message;
    QHBoxLayout *horizontalLayout_2;
    QLabel *number;
    QLabel *img;
    QWidget *message;
    QVBoxLayout *verticalLayout_2;
    QLabel *singer;
    QLabel *song_name;
    QLabel *time;
    QPushButton *love_button;
    QPushButton *download_button;

    void setupUi(QWidget *SongItem)
    {
        if (SongItem->objectName().isEmpty())
            SongItem->setObjectName("SongItem");
        SongItem->resize(301, 64);
        horizontalLayout = new QHBoxLayout(SongItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        song_message = new QWidget(SongItem);
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

        img = new QLabel(song_message);
        img->setObjectName("img");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(img->sizePolicy().hasHeightForWidth());
        img->setSizePolicy(sizePolicy1);
        img->setMinimumSize(QSize(0, 0));
        img->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: white;\n"
"}"));

        horizontalLayout_2->addWidget(img);

        message = new QWidget(song_message);
        message->setObjectName("message");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(6);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(message->sizePolicy().hasHeightForWidth());
        message->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(message);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 0, 5, 0);
        singer = new QLabel(message);
        singer->setObjectName("singer");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(singer->sizePolicy().hasHeightForWidth());
        singer->setSizePolicy(sizePolicy3);
        singer->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"}"));

        verticalLayout_2->addWidget(singer);

        song_name = new QLabel(message);
        song_name->setObjectName("song_name");
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(song_name->sizePolicy().hasHeightForWidth());
        song_name->setSizePolicy(sizePolicy4);
        song_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"}"));

        verticalLayout_2->addWidget(song_name);


        horizontalLayout_2->addWidget(message);

        time = new QLabel(song_message);
        time->setObjectName("time");
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(time->sizePolicy().hasHeightForWidth());
        time->setSizePolicy(sizePolicy5);
        time->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"}"));

        horizontalLayout_2->addWidget(time);

        love_button = new QPushButton(song_message);
        love_button->setObjectName("love_button");
        sizePolicy5.setHeightForWidth(love_button->sizePolicy().hasHeightForWidth());
        love_button->setSizePolicy(sizePolicy5);
        love_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/love.png);\n"
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

        horizontalLayout_2->addWidget(love_button);

        download_button = new QPushButton(song_message);
        download_button->setObjectName("download_button");
        sizePolicy5.setHeightForWidth(download_button->sizePolicy().hasHeightForWidth());
        download_button->setSizePolicy(sizePolicy5);
        download_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/download.png);\n"
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
        download_button->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(download_button);


        horizontalLayout->addWidget(song_message);


        retranslateUi(SongItem);

        QMetaObject::connectSlotsByName(SongItem);
    } // setupUi

    void retranslateUi(QWidget *SongItem)
    {
        SongItem->setWindowTitle(QCoreApplication::translate("SongItem", "Form", nullptr));
        number->setText(QCoreApplication::translate("SongItem", "01", nullptr));
        img->setText(QString());
        singer->setText(QString());
        song_name->setText(QString());
        time->setText(QCoreApplication::translate("SongItem", "00:00", nullptr));
        love_button->setText(QString());
        download_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SongItem: public Ui_SongItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGITEM_H
