//
// Created by 86186 on 2024/3/16.
//

#ifndef AUDIOPLAYER_CONST_H
#define AUDIOPLAYER_CONST_H


#include <QDir>
#include <QSettings>
#include <qjsonvalue.h>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <QNetworkReply>
#include <qlistwidget.h>

#include "PopupBox/MessageBoxHint.h"

enum ReqId{
	ID_GET_VARIFY_CODE			= 1001, //获取验证码
	ID_REG_USER 				= 1002, //注册用户
	ID_RESET_PWD 				= 1003, //重置密码
	ID_LOGIN_USER 				= 1004, //用户登录
	ID_ADD_SONG_TO_SONGLIST		= 1005, //添加歌曲到喜欢的列表
	ID_REMOVE_SONG_TO_SONGLIST	= 1006, //移出歌曲从喜欢的列表
	ID_SEARCH_SONG				= 1007, //搜索歌曲
	ID_GET_SONG_BODY			= 1008,	//获取歌曲
	ID_DOWNLOAD_SONG			= 1009,	//下载歌曲
};

enum ErrorCodes{
	SUCCESS 	= 0, //成功
	ERR_JSON 	= 1, //Json解析失败
	ERR_NETWORK = 2, //网络错误
};

enum Modules{
	REGISTERMOD = 0, //注册模块
	RESETMOD 	= 1, //重置密码模块
	LOGINMOD 	= 2, //登录模块
	MUSICMOD	= 3, //音乐模块
};

enum TipErr{
	TIP_SUCCESS 		= 0, //成功
	TIP_EMAIL_ERR 		= 1, //注册时输入的邮箱错误
	TIP_PWD_ERR 		= 2, //登录时密码错误
	TIP_CONFIRM_ERR 	= 3, //
	TIP_PWD_CONFIRM 	= 4,
	TIP_VARIFY_ERR 		= 5, //注册时验证码错误
	TIP_USER_ERR 		= 6, //登录时用户不存在
	TIP_SONG_EXISTED	= 7, //歌曲已存在歌单
	TIP_SONG_UNEXISTED	= 8, //歌曲不存在歌单
	TIP_SEARCH_ERR		= 9, //搜索歌曲名字错误
	TIP_SONG_BODY_UNEXISTED = 10, //服务端不存在歌曲的文件
};

enum ClickLbState{
	Normal 		= 0,
	Selected 	= 1
};

extern QString gate_url_prefix;

extern std::function<QString(QString)> xorString;

extern std::function<void(const QString&, bool flag)> showTip;

extern std::function<QString(int)> transfTimeStr;

extern std::function<int(const QString&)> transfTimeInt;

extern std::function<QWidget* (QListWidget*, QListWidgetItem*)> findItem;

extern std::function<QListWidgetItem*(QListWidget*, QWidget*)> findWidget;

extern bool operator<(ReqId a, ReqId b);

#endif //AUDIOPLAYER_CONST_H
