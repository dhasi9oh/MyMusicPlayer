#include "SongItem.h"

SongItem::SongItem(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::SongItem)
{
	init();
}

SongItem::~SongItem()
{
	delete ui;
}

QString SongItem::getNumber() const
{
	return ui->number->text();
}

void SongItem::setNumber(int number)
{
	ui->number->setNum(number);
}

QPixmap SongItem::getSongImage() const
{
	return ui->img->pixmap();
}

void SongItem::setSongImage(const QPixmap& songImage)
{
	ui->img->setPixmap(songImage);
}

QString SongItem::getSongName() const
{
	return ui->song_name->text();
}

void SongItem::setSongName(const QString& songName)
{
	ui->song_name->setText(songName);
}

QString SongItem::getSinger() const
{
	return ui->singer->text();
}

void SongItem::setSinger(const QString& songArtist)
{
	ui->singer->setText(songArtist);
}

QString SongItem::getTime() const
{
	return ui->time->text();
}

void SongItem::setTime(const QString& time)
{
	ui->time->setText(time);
}

void SongItem::setLoved(bool loved)
{
	ui->love_button->setProperty("state", loved ? "love_red" : "love");
}

void SongItem::setDownloaded(bool downloaded)
{
	ui->download_button->setProperty("state", downloaded ? "remove" : "downloaded");
}

void SongItem::init()
{
	ui->setupUi(this);

	connect(ui->love_button, &QPushButton::released,
		[&]
		{
			if (ui->love_button->property("state") == "love") {
				emit love_button_clicked(this);
			}
			else {
				emit remove_button_clicked(this);
			}
		}
	);

	connect(ui->download_button, &QPushButton::released,
		[&] { emit this->download_button_clicked(this); });
}
