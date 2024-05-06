//
// Created by 86186 on 2024/3/11.
//

#ifndef AUDIOPLAYER_MAINWINDOW_H
#define AUDIOPLAYER_MAINWINDOW_H

#include <qwidget.h>
#include <qfiledialog.h>
#include <qgraphicseffect.h>

#include "ui_AudioPlayer.h"

#include "const.h"
#include "HttpMgr.h"
#include "SongItem.h"
#include "MediaBuffer.h"
#include "MediaPlayer.h"
#include "FileSongItem.h"
#include "Progress/Slider.h"
#include "Helper/Window/PointFixedWidget.h"
#include "Helper/Window/RemovableWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class AudioPlayer;
};
QT_END_NAMESPACE

class MainWindow : public TinyWidgetLibrary::RemovableWidget
{
	Q_OBJECT

	using Func = std::function<void(const QByteArray&, const QJsonObject&)>;

signals:

	void	login_success(const QJsonObject);

public:

	explicit MainWindow(const QJsonObject& obj, QWidget* parent = nullptr);
	virtual ~MainWindow();

private slots:

	void	slotPreButtonClicked();
	void	slotNextButtonClicked();
	void	slotPlayButtonClicked();
	void	slotLocalFileButtonClicked();
	void	slotProgressMove(qint64);
	void	slotProgressRelease(int);
	void	slotSearchSongNameReturn();
	void	slotSongItemLoveButtonClicked(SongItem*);
	void	slotSongItemRemoveButtonClicked(SongItem*);
	void	slotSongItemDownLoadButtonClicked(SongItem*);
	void	slotSongItemButtonDoubleClicked(QListWidgetItem*);
	void	slotLocalFileSongItemRemoveButtonClicked(FileSongItem*);
	void	slotLocalFileSongItemDoubleClicked(FileSongItem*);
	void	slotMusicModFinish(ReqId, QByteArray, ErrorCodes, QJsonObject);

private:

	void	setSongTimer(qint64);
	void	insertHomeSongItem(SongItem* widget);
	void	insertLoveSongItem(SongItem* widget);
	void	insertSearchSongItem(SongItem* widget);
	void	insertMusicFileItem(FileSongItem* widget);
	void	createMusicFile(const QString& name, const QString& singer, const QByteArray& arr);

private:

	void	initWidget();
	void	initHandle();
	void	initConnect();
	void	initList(const QJsonObject& obj);

private:

	int uid;
	Ui::AudioPlayer * ui;
	TinyWidgetLibrary::Slider*				m_slider;
	TinyWidgetLibrary::PointFixedWidget*	m_floatWindow;
	MediaBuffer*							m_buffer;
	MediaPlayer*							m_player;
	QMap<ReqId, Func>						m_handlers;

};

#endif //AUDIOPLAYER_MAINWINDOW_H
