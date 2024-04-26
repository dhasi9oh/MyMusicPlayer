//
// Created by 86186 on 2024/3/11.
//

#ifndef AUDIOPLAYER_SONGITEM_H
#define AUDIOPLAYER_SONGITEM_H

#include <qwidget.h>

#include "const.h"
#include "ui_SongItem.h"

QT_BEGIN_NAMESPACE

namespace Ui {
	class SongItem;
};

QT_END_NAMESPACE

class SongItem : public QWidget
{
	Q_OBJECT

signals:

	void love_button_clicked(SongItem*);
	void remove_button_clicked(SongItem*);
	void download_button_clicked(SongItem*);

public:

	explicit SongItem(QWidget* parent = nullptr);
	virtual ~SongItem();

	QString getNumber() const;
	void	setNumber(int number);

	QPixmap	getSongImage() const;
	void	setSongImage(const QPixmap &songImage);

	QString	getSongName() const;
	void	setSongName(const QString &songName);

	QString	getSinger() const;
	void	setSinger(const QString &songArtist);

	QString getTime() const;
	void	setTime(const QString &time);

	void	setLoved(bool loved);
	void	setDownloaded(bool downloaded);

private:

	void	init();

private:

	Ui::SongItem* ui;
};


#endif //AUDIOPLAYER_SONGITEM_H
