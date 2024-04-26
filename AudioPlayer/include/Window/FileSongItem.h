//
// Created by 86186 on 2024/3/13.
//

#ifndef AUDIOPLAYER_FILESONGITEM_H
#define AUDIOPLAYER_FILESONGITEM_H

#include <qwidget.h>

#include "ui_FileSongItem.h"

QT_BEGIN_NAMESPACE

namespace Ui {
	class FileSongItem;
};

QT_END_NAMESPACE


class FileSongItem : public QWidget
{
	Q_OBJECT

signals:

	void remove_button_clicked(FileSongItem*);

public:

	explicit FileSongItem(QString path, QWidget* parent = nullptr);
	virtual ~FileSongItem();

	QString getNumber() const;
	void	setNumber(int number);

	QString getSongPath() const;
	void	setSongPath(const QString &songPath);

private:

	void 	init();

private:

	Ui::FileSongItem	*ui;

};


#endif //AUDIOPLAYER_FILESONGITEM_H
