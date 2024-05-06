/********************************************************************************
** Form generated from reading UI file 'AudioPlayer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOPLAYER_H
#define UI_AUDIOPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TextBox/TextBox.h"

QT_BEGIN_NAMESPACE

class Ui_AudioPlayer
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *main_window;
    QVBoxLayout *verticalLayout_2;
    QWidget *window_control;
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QPushButton *min;
    QPushButton *close;
    QWidget *song_message;
    QHBoxLayout *horizontalLayout_2;
    QWidget *img_background;
    QVBoxLayout *verticalLayout_4;
    QLabel *img;
    QWidget *song_control;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *singer;
    QPushButton *open_file;
    QLabel *song_name;
    QWidget *play_buttons;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pre_button;
    QPushButton *play_button;
    QPushButton *next_button;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QSlider *horizontalSlider;
    QLabel *label;
    TinyWidgetLibrary::TextBox *search_lineedit;
    QStackedWidget *stackedWidget;
    QWidget *music_file_list;
    QVBoxLayout *verticalLayout_7;
    QListWidget *local_list_control;
    QWidget *search_song_list;
    QVBoxLayout *verticalLayout_8;
    QListWidget *search_list_control;
    QWidget *home_song_list;
    QVBoxLayout *verticalLayout_5;
    QListWidget *home_list_control;
    QWidget *love_song_list;
    QVBoxLayout *verticalLayout_6;
    QListWidget *song_list_control;
    QWidget *other_control;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *home;
    QPushButton *search;
    QPushButton *love_list;
    QPushButton *file_set;
    QPushButton *volume;
    QPushButton *setting;

    void setupUi(QWidget *AudioPlayer)
    {
        if (AudioPlayer->objectName().isEmpty())
            AudioPlayer->setObjectName("AudioPlayer");
        AudioPlayer->resize(328, 602);
        verticalLayout = new QVBoxLayout(AudioPlayer);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        main_window = new QWidget(AudioPlayer);
        main_window->setObjectName("main_window");
        main_window->setStyleSheet(QString::fromUtf8("#main_window {\n"
"	background-color: rgb(50, 53, 58);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(main_window);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        window_control = new QWidget(main_window);
        window_control->setObjectName("window_control");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(window_control->sizePolicy().hasHeightForWidth());
        window_control->setSizePolicy(sizePolicy);
        window_control->setMinimumSize(QSize(0, 50));
        window_control->setMaximumSize(QSize(16777215, 50));
        window_control->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(40, 42, 45);\n"
"}"));
        horizontalLayout = new QHBoxLayout(window_control);
        horizontalLayout->setObjectName("horizontalLayout");
        logo = new QLabel(window_control);
        logo->setObjectName("logo");

        horizontalLayout->addWidget(logo);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        title = new QLabel(window_control);
        title->setObjectName("title");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"	padding-left: 10px;\n"
"}"));

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        min = new QPushButton(window_control);
        min->setObjectName("min");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(min->sizePolicy().hasHeightForWidth());
        min->setSizePolicy(sizePolicy1);
        min->setMinimumSize(QSize(30, 30));
        min->setMaximumSize(QSize(30, 30));
        min->setCursor(QCursor(Qt::PointingHandCursor));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon);
        min->setIconSize(QSize(20, 24));

        horizontalLayout->addWidget(min);

        close = new QPushButton(window_control);
        close->setObjectName("close");
        close->setMinimumSize(QSize(30, 30));
        close->setMaximumSize(QSize(30, 30));
        close->setCursor(QCursor(Qt::PointingHandCursor));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon1);
        close->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(close);


        verticalLayout_2->addWidget(window_control);

        song_message = new QWidget(main_window);
        song_message->setObjectName("song_message");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(song_message->sizePolicy().hasHeightForWidth());
        song_message->setSizePolicy(sizePolicy2);
        song_message->setMinimumSize(QSize(0, 110));
        song_message->setMaximumSize(QSize(16777215, 110));
        horizontalLayout_2 = new QHBoxLayout(song_message);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(8, 5, 8, 5);
        img_background = new QWidget(song_message);
        img_background->setObjectName("img_background");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(img_background->sizePolicy().hasHeightForWidth());
        img_background->setSizePolicy(sizePolicy3);
        img_background->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(img_background);
        verticalLayout_4->setObjectName("verticalLayout_4");
        img = new QLabel(img_background);
        img->setObjectName("img");

        verticalLayout_4->addWidget(img);


        horizontalLayout_2->addWidget(img_background);

        song_control = new QWidget(song_message);
        song_control->setObjectName("song_control");
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(song_control->sizePolicy().hasHeightForWidth());
        song_control->setSizePolicy(sizePolicy4);
        verticalLayout_3 = new QVBoxLayout(song_control);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(5, 0, 5, 0);
        widget_2 = new QWidget(song_control);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(2);
        sizePolicy5.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy5);
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        singer = new QLabel(widget_2);
        singer->setObjectName("singer");
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(3);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(singer->sizePolicy().hasHeightForWidth());
        singer->setSizePolicy(sizePolicy6);
        QFont font1;
        font1.setPointSize(8);
        singer->setFont(font1);
        singer->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"	padding-left: 10px;\n"
"}"));

        horizontalLayout_6->addWidget(singer);

        open_file = new QPushButton(widget_2);
        open_file->setObjectName("open_file");
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(open_file->sizePolicy().hasHeightForWidth());
        open_file->setSizePolicy(sizePolicy7);
        open_file->setCursor(QCursor(Qt::PointingHandCursor));
        open_file->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background-color: transparent;\n"
"	icon: url(:/image/folder open-fill.png);\n"
"}"));

        horizontalLayout_6->addWidget(open_file);


        verticalLayout_3->addWidget(widget_2);

        song_name = new QLabel(song_control);
        song_name->setObjectName("song_name");
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(3);
        sizePolicy8.setHeightForWidth(song_name->sizePolicy().hasHeightForWidth());
        song_name->setSizePolicy(sizePolicy8);
        QFont font2;
        font2.setPointSize(12);
        song_name->setFont(font2);
        song_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"	padding-left: 6px;\n"
"}"));

        verticalLayout_3->addWidget(song_name);

        play_buttons = new QWidget(song_control);
        play_buttons->setObjectName("play_buttons");
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(5);
        sizePolicy9.setHeightForWidth(play_buttons->sizePolicy().hasHeightForWidth());
        play_buttons->setSizePolicy(sizePolicy9);
        horizontalLayout_3 = new QHBoxLayout(play_buttons);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, -1, 0, -1);
        pre_button = new QPushButton(play_buttons);
        pre_button->setObjectName("pre_button");
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(pre_button->sizePolicy().hasHeightForWidth());
        pre_button->setSizePolicy(sizePolicy10);
        pre_button->setCursor(QCursor(Qt::PointingHandCursor));
        pre_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/diyiyeshouyeshangyishou.png);\n"
"	background-color: rgb(80, 90, 100);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(80, 90, 100, 200);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(80, 90, 100, 120);\n"
"}"));
        pre_button->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(pre_button);

        play_button = new QPushButton(play_buttons);
        play_button->setObjectName("play_button");
        sizePolicy10.setHeightForWidth(play_button->sizePolicy().hasHeightForWidth());
        play_button->setSizePolicy(sizePolicy10);
        play_button->setCursor(QCursor(Qt::PointingHandCursor));
        play_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/arrow-.png);\n"
"	background-color: rgb(80, 90, 100);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(80, 90, 100, 200);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(80, 90, 100, 120);\n"
"}"));
        play_button->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(play_button);

        next_button = new QPushButton(play_buttons);
        next_button->setObjectName("next_button");
        sizePolicy10.setHeightForWidth(next_button->sizePolicy().hasHeightForWidth());
        next_button->setSizePolicy(sizePolicy10);
        next_button->setCursor(QCursor(Qt::PointingHandCursor));
        next_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/zuihouyiyemoyexiayishou.png);\n"
"	background-color: rgb(80, 90, 100);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(80, 90, 100, 200);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(80, 90, 100, 120);\n"
"}"));
        next_button->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(next_button);


        verticalLayout_3->addWidget(play_buttons);


        horizontalLayout_2->addWidget(song_control);


        verticalLayout_2->addWidget(song_message);

        widget = new QWidget(main_window);
        widget->setObjectName("widget");
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(5, 3, 5, 3);
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	height: 2px;\n"
"	border: 1px solid;\n"
"	border-radius: 1px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"	height: 2px;\n"
"	border: 1px;\n"
"	border-top-left-radius: 2px;\n"
"	border-bottom-left-radius: 2px;\n"
"	background-color: #00B0AE;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"	height: 2px;\n"
"	background: #EAEAEA;\n"
"	border: 1px solid #EAEAEA;\n"
"	border-top-right-radius: 2px;\n"
"	border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal\n"
"{\n"
"    width: 8px;\n"
"    margin-top: -3px;\n"
"    margin-bottom: -3px;\n"
"    border-radius: 4px;\n"
"    background:rgba(255, 255, 255, 255);\n"
"}\n"
""));
        horizontalSlider->setValue(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider);

        label = new QLabel(widget);
        label->setObjectName("label");
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy11);
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: white;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        horizontalLayout_5->addWidget(label);


        verticalLayout_2->addWidget(widget);

        search_lineedit = new TinyWidgetLibrary::TextBox(main_window);
        search_lineedit->setObjectName("search_lineedit");
        sizePolicy.setHeightForWidth(search_lineedit->sizePolicy().hasHeightForWidth());
        search_lineedit->setSizePolicy(sizePolicy);
        search_lineedit->setMinimumSize(QSize(0, 40));
        search_lineedit->setMaximumSize(QSize(16777215, 40));
        search_lineedit->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgba(255, 255, 255, 50);\n"
"}"));

        verticalLayout_2->addWidget(search_lineedit);

        stackedWidget = new QStackedWidget(main_window);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"#home_list_control,#song_list_control,#local_list_control,#search_list_control {\n"
"	outline: none;\n"
"	background-color: rgb(51, 53, 56);\n"
"}\n"
"\n"
"#home_list_control::item:selected,\n"
"#song_list_control::item:selected,\n"
"#local_list_control::item:selected,\n"
"#search_list_control::item:selected {\n"
"	background-color: rgb(38, 40, 45);\n"
"}\n"
"\n"
"#home_list_control::item:hover,\n"
"#song_list_control::item:hover,\n"
"#local_list_control::item:hover,\n"
"#search_list_control::item:hover {\n"
"	background: rgb(0, 100, 200);\n"
"	padding-top:0px;\n"
"	padding-bottom:0px;\n"
"}"));
        music_file_list = new QWidget();
        music_file_list->setObjectName("music_file_list");
        verticalLayout_7 = new QVBoxLayout(music_file_list);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        local_list_control = new QListWidget(music_file_list);
        local_list_control->setObjectName("local_list_control");
        local_list_control->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(local_list_control);

        stackedWidget->addWidget(music_file_list);
        search_song_list = new QWidget();
        search_song_list->setObjectName("search_song_list");
        verticalLayout_8 = new QVBoxLayout(search_song_list);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        search_list_control = new QListWidget(search_song_list);
        new QListWidgetItem(search_list_control);
        new QListWidgetItem(search_list_control);
        new QListWidgetItem(search_list_control);
        new QListWidgetItem(search_list_control);
        search_list_control->setObjectName("search_list_control");
        search_list_control->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_8->addWidget(search_list_control);

        stackedWidget->addWidget(search_song_list);
        home_song_list = new QWidget();
        home_song_list->setObjectName("home_song_list");
        verticalLayout_5 = new QVBoxLayout(home_song_list);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        home_list_control = new QListWidget(home_song_list);
        home_list_control->setObjectName("home_list_control");
        home_list_control->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(home_list_control);

        stackedWidget->addWidget(home_song_list);
        love_song_list = new QWidget();
        love_song_list->setObjectName("love_song_list");
        verticalLayout_6 = new QVBoxLayout(love_song_list);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        song_list_control = new QListWidget(love_song_list);
        song_list_control->setObjectName("song_list_control");
        song_list_control->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(song_list_control);

        stackedWidget->addWidget(love_song_list);

        verticalLayout_2->addWidget(stackedWidget);

        other_control = new QWidget(main_window);
        other_control->setObjectName("other_control");
        sizePolicy.setHeightForWidth(other_control->sizePolicy().hasHeightForWidth());
        other_control->setSizePolicy(sizePolicy);
        other_control->setMinimumSize(QSize(0, 30));
        other_control->setMaximumSize(QSize(16777215, 30));
        other_control->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(other_control);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        home = new QPushButton(other_control);
        home->setObjectName("home");
        sizePolicy10.setHeightForWidth(home->sizePolicy().hasHeightForWidth());
        home->setSizePolicy(sizePolicy10);
        home->setCursor(QCursor(Qt::PointingHandCursor));
        home->setStyleSheet(QString::fromUtf8("#home {\n"
"	border: none;\n"
"	icon: url(:/image/home.png);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"#home:hover {\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"#home:pressed {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_4->addWidget(home);

        search = new QPushButton(other_control);
        search->setObjectName("search");
        sizePolicy10.setHeightForWidth(search->sizePolicy().hasHeightForWidth());
        search->setSizePolicy(sizePolicy10);
        search->setCursor(QCursor(Qt::PointingHandCursor));
        search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/search.png);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_4->addWidget(search);

        love_list = new QPushButton(other_control);
        love_list->setObjectName("love_list");
        sizePolicy10.setHeightForWidth(love_list->sizePolicy().hasHeightForWidth());
        love_list->setSizePolicy(sizePolicy10);
        love_list->setCursor(QCursor(Qt::PointingHandCursor));
        love_list->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/love.png);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_4->addWidget(love_list);

        file_set = new QPushButton(other_control);
        file_set->setObjectName("file_set");
        sizePolicy10.setHeightForWidth(file_set->sizePolicy().hasHeightForWidth());
        file_set->setSizePolicy(sizePolicy10);
        file_set->setCursor(QCursor(Qt::PointingHandCursor));
        file_set->setStyleSheet(QString::fromUtf8("\n"
"#file_set {\n"
"	border: none;\n"
"	icon: url(:/image/set.png);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"#file_set:hover {\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"#file_set:pressed {\n"
"	background-color: rgb(50, 50, 50);\n"
"}\n"
""));

        horizontalLayout_4->addWidget(file_set);

        volume = new QPushButton(other_control);
        volume->setObjectName("volume");
        sizePolicy10.setHeightForWidth(volume->sizePolicy().hasHeightForWidth());
        volume->setSizePolicy(sizePolicy10);
        volume->setCursor(QCursor(Qt::PointingHandCursor));
        volume->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/shengyin_shiti.png);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_4->addWidget(volume);

        setting = new QPushButton(other_control);
        setting->setObjectName("setting");
        sizePolicy10.setHeightForWidth(setting->sizePolicy().hasHeightForWidth());
        setting->setSizePolicy(sizePolicy10);
        setting->setCursor(QCursor(Qt::PointingHandCursor));
        setting->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	icon: url(:/image/shezhi.png);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_4->addWidget(setting);


        verticalLayout_2->addWidget(other_control);


        verticalLayout->addWidget(main_window);


        retranslateUi(AudioPlayer);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AudioPlayer);
    } // setupUi

    void retranslateUi(QWidget *AudioPlayer)
    {
        AudioPlayer->setWindowTitle(QCoreApplication::translate("AudioPlayer", "Form", nullptr));
        logo->setText(QString());
        title->setText(QCoreApplication::translate("AudioPlayer", "Audio Player", nullptr));
#if QT_CONFIG(tooltip)
        min->setToolTip(QCoreApplication::translate("AudioPlayer", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        min->setText(QString());
#if QT_CONFIG(tooltip)
        close->setToolTip(QCoreApplication::translate("AudioPlayer", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
        close->setText(QString());
        img->setText(QString());
#if QT_CONFIG(tooltip)
        singer->setToolTip(QCoreApplication::translate("AudioPlayer", "\346\255\214\346\211\213", nullptr));
#endif // QT_CONFIG(tooltip)
        singer->setText(QString());
#if QT_CONFIG(tooltip)
        open_file->setToolTip(QCoreApplication::translate("AudioPlayer", "\345\257\274\345\205\245\351\237\263\344\271\220\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        open_file->setText(QString());
#if QT_CONFIG(tooltip)
        song_name->setToolTip(QCoreApplication::translate("AudioPlayer", "\346\255\214\346\233\262\345\220\215", nullptr));
#endif // QT_CONFIG(tooltip)
        song_name->setText(QString());
#if QT_CONFIG(tooltip)
        pre_button->setToolTip(QCoreApplication::translate("AudioPlayer", "\344\270\212\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        pre_button->setText(QString());
        play_button->setText(QString());
#if QT_CONFIG(tooltip)
        next_button->setToolTip(QCoreApplication::translate("AudioPlayer", "\344\270\213\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        next_button->setText(QString());
        label->setText(QCoreApplication::translate("AudioPlayer", "00:00/00:00", nullptr));
#if QT_CONFIG(tooltip)
        search_lineedit->setToolTip(QCoreApplication::translate("AudioPlayer", "\346\220\234\347\264\242", nullptr));
#endif // QT_CONFIG(tooltip)

        const bool __sortingEnabled = search_list_control->isSortingEnabled();
        search_list_control->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = search_list_control->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("AudioPlayer", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = search_list_control->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("AudioPlayer", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = search_list_control->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("AudioPlayer", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = search_list_control->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("AudioPlayer", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        search_list_control->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        home->setToolTip(QCoreApplication::translate("AudioPlayer", "\344\270\273\351\241\265", nullptr));
#endif // QT_CONFIG(tooltip)
        home->setText(QString());
#if QT_CONFIG(tooltip)
        search->setToolTip(QCoreApplication::translate("AudioPlayer", "\345\226\234\346\254\242\347\232\204\346\255\214\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        search->setText(QString());
#if QT_CONFIG(tooltip)
        love_list->setToolTip(QCoreApplication::translate("AudioPlayer", "\345\226\234\346\254\242\347\232\204\346\255\214\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        love_list->setText(QString());
        file_set->setText(QString());
#if QT_CONFIG(tooltip)
        volume->setToolTip(QCoreApplication::translate("AudioPlayer", "\351\237\263\351\207\217", nullptr));
#endif // QT_CONFIG(tooltip)
        volume->setText(QString());
#if QT_CONFIG(tooltip)
        setting->setToolTip(QCoreApplication::translate("AudioPlayer", "\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AudioPlayer: public Ui_AudioPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOPLAYER_H
