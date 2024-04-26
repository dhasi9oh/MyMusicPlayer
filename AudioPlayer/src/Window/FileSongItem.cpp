#include "FileSongItem.h"

FileSongItem::FileSongItem(QString path, QWidget* parent)
		: QWidget(parent)
		, ui(new Ui::FileSongItem())
{
	init();
	ui->song_name->setText(path);
}

FileSongItem::~FileSongItem()
{
	delete ui;
}

QString FileSongItem::getNumber() const
{
	return ui->number->text();
}

void FileSongItem::setNumber(int number)
{
	ui->number->setNum(number);
}

QString FileSongItem::getSongPath() const
{
	return ui->song_name->text();
}

void FileSongItem::setSongPath(const QString &path)
{
	ui->song_name->setText(path);
}

void FileSongItem::init()
{
	ui->setupUi(this);

	connect(ui->remove_button, &QPushButton::clicked,
			[&] { emit remove_button_clicked(this); });
}
