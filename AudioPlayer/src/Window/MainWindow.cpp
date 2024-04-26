#include "MainWindow.h"

MainWindow::MainWindow(const QJsonObject& obj, QWidget* parent)
		: QWidget(parent)
{
	initWidget();
	initHandle();
	initConnect();
	
	uid = obj["uid"].toInt();
	emit login_success(obj);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::slotPreButtonClicked()
{
	QListWidget* ptr = 
		qobject_cast<QListWidget*>(
			ui->stackedWidget->currentWidget());
	if (ptr == nullptr) return;

	int idx = ptr->currentRow();
	if (idx == -1) return;

	idx = (idx - 1 + ptr->count()) % ptr->count();
	ptr->setCurrentRow(idx);
	emit ptr->itemDoubleClicked(ptr->item(idx));
}

void MainWindow::slotNextButtonClicked()
{
	QListWidget* ptr =
		qobject_cast<QListWidget*>(
			ui->stackedWidget->currentWidget());
	if (ptr == nullptr) return;

	int idx = ptr->currentRow();
	if (idx == -1) return;

	idx = (idx + 1) % ptr->count();
	ptr->setCurrentRow(idx);
	emit ptr->itemDoubleClicked(ptr->item(idx));
}

void MainWindow::slotPlayButtonClicked()
{
	bool playing = m_player->isPlaying();

	if (playing) {
		m_player->stop();
	}
	else {
		m_player->play();
	}

	ui->play_button->setProperty("state", playing ? "" : "");
}

void MainWindow::slotLocalFileButtonClicked()
{
	const QStringList name_list = QFileDialog::getOpenFileNames(
		nullptr, "获取本地歌集", "music_files", "*.mp3");

	if (name_list.empty()) return;

	ui->local_list_control->clear();
	ui->stackedWidget->setCurrentWidget(ui->local_list_control);

	for (int i = 0; i < name_list.size(); i++) {
		auto item = new FileSongItem(name_list[i]);
		item->setNumber(i + 1);

		connect(item, &FileSongItem::remove_button_clicked,
			this, &MainWindow::slotLocalFileSongItemRemoveButtonClicked);

		insertMusicFileItem(item);
	}
}

void MainWindow::slotProgressMove(qint64 duration)
{
	qreal value = duration / (qreal)m_player->duration();
	ui->horizontalSlider->setValue(value * ui->horizontalSlider->maximum());
	ui->label->setText(transfTimeStr(duration / 1000) + "/" + transfTimeStr(m_player->duration() / 1000));
}

void MainWindow::slotProgressRelease(int value)
{
	m_player->setPosition(value * m_player->duration() / ui->horizontalSlider->maximum());
}

void MainWindow::slotSearchSongNameReturn()
{
	const QString song_name = ui->search_lineedit->getLineEdit()->text();
	QJsonObject obj;
	obj["song_name"] = song_name;

	HttpMgr::GetInstance()->postHttpReq(
		gate_url_prefix + "/search_song",
		obj,
		ReqId::ID_SEARCH_SONG,
		Modules::MUSICMOD
	);
}

void MainWindow::slotSongItemLoveButtonClicked(SongItem* widget_ptr)
{
	const QString song_name = widget_ptr->getSongName();
	const QString singer = widget_ptr->getSinger();

	QJsonObject obj;
	obj["uid"] = uid;
	obj["singer"] = singer;
	obj["song_name"] = song_name;
	obj["duration"] = transfTimeInt(widget_ptr->getTime());

	HttpMgr::GetInstance()->postHttpReq(
		gate_url_prefix + "/add_song_to_song_list",
		obj,
		ReqId::ID_ADD_SONG_TO_SONGLIST,
		Modules::MUSICMOD
	);
}

void MainWindow::slotSongItemRemoveButtonClicked(SongItem* widget_ptr)
{
	const QString song_name = widget_ptr->getSongName();
	const QString singer = widget_ptr->getSinger();

	QJsonObject obj;
	obj["uid"] = uid;
	obj["singer"] = singer;
	obj["song_name"] = song_name;

	HttpMgr::GetInstance()->postHttpReq(
		gate_url_prefix + "/remove_song_from_song_list",
		obj,
		ReqId::ID_REMOVE_SONG_TO_SONGLIST,
		Modules::MUSICMOD
	);
}

void MainWindow::slotSongItemDownLoadButtonClicked(SongItem* widget_ptr)
{
	auto ptr = qobject_cast<QListWidget*>(ui->stackedWidget->currentWidget());
	if (ptr == nullptr) {
		return;
	}

	auto item = findWidget(ptr, widget_ptr);
	if (item == nullptr) {
		return;
	}

	struct SongMessage message;
	message.singer = ui->singer->text();
	message.song_name = ui->song_name->text();
	message.duration = transfTimeInt(widget_ptr->getTime());


	if (m_buffer->hasSource(message)) {
		QByteArray arr;
		m_buffer->getSource(message, &arr);
		createMusicFile(message.singer, message.song_name, arr);
		return;
	}

	QJsonObject obj;
	obj["singer"] = message.singer;
	obj["song_name"] = message.song_name;
	obj["duration"] = message.duration;

	HttpMgr::GetInstance()->postHttpReq(
		gate_url_prefix + "/get_song_body",
		obj,
		ReqId::ID_DOWNLOAD_SONG,
		Modules::MUSICMOD
	);
}

void MainWindow::slotSongItemButtonDoubleClicked(QListWidgetItem* item)
{
	QListWidget* ptr = qobject_cast<QListWidget*>(ui->stackedWidget->currentWidget());
	if (ptr == nullptr) {
		return;
	}

	auto it = dynamic_cast<SongItem*>(ptr->itemWidget(item));
	if (it == nullptr) {
		return;
	}

	struct SongMessage message;
	message.singer = ui->singer->text();
	message.song_name = ui->song_name->text();
	message.duration = transfTimeInt(it->getTime());


	if (m_buffer->hasSource(message)) {
		QByteArray arr;
		m_buffer->getSource(message, &arr);
		ui->singer->setText(message.singer);
		ui->song_name->setText(message.song_name);
		setSongTimer(m_player->duration() / 1000);
		m_player->setData(arr);
		return;
	}

	QJsonObject obj;
	obj["singer"] = message.singer;
	obj["song_name"] = message.song_name;

	HttpMgr::GetInstance()->postHttpReq(
		gate_url_prefix + "/get_song_body",
		obj,
		ReqId::ID_GET_SONG_BODY,
		Modules::MUSICMOD
	);
}

void MainWindow::slotLocalFileSongItemRemoveButtonClicked(FileSongItem* widget_ptr)
{
	auto item = findWidget(ui->local_list_control, widget_ptr);
	if (item != nullptr) {
		ui->local_list_control->removeItemWidget(item);
	}
}

void MainWindow::slotLocalFileSongItemDoubleClicked(FileSongItem* item)
{
	QString path = item->getSongPath();
	if (!QFile::exists(path)) return;

	QFile file(path);
	file.open(QIODeviceBase::ReadOnly);
	QByteArray arr = file.readAll();
	file.close();

	ui->singer->setText("");
	ui->song_name->setText(path);
	m_player->setData(arr);
	setSongTimer(m_player->duration() / 1000);
}

void MainWindow::slotMusicModFinish(ReqId id, QByteArray res, ErrorCodes err, QJsonObject json)
{
	if (err != ErrorCodes::SUCCESS) {
		showTip(tr("网络请求错误"), false);
		return;
	}
	m_handlers[id](res, json);
}

void MainWindow::setSongTimer(qint64 duration)
{
	ui->horizontalSlider->setValue(0);
	ui->label->setText(transfTimeStr(0) + "/" + transfTimeStr(duration));
}

void MainWindow::insertHomeSongItem(SongItem *widget)
{
	auto ptr = new QListWidgetItem;

	ui->home_list_control->addItem(ptr);
	ui->home_list_control->setItemWidget(ptr, widget);
	ui->stackedWidget->setCurrentWidget(ui->home_song_list);
}

void MainWindow::insertLoveSongItem(SongItem *widget)
{
	auto ptr = new QListWidgetItem;

	ui->home_list_control->addItem(ptr);
	ui->song_list_control->setItemWidget(ptr, widget);
	ui->stackedWidget->setCurrentWidget(ui->love_song_list);
}

void MainWindow::insertSearchSongItem(SongItem *widget)
{
	auto ptr = new QListWidgetItem;

	ui->home_list_control->addItem(ptr);
	ui->song_list_control->setItemWidget(ptr, widget);
	ui->stackedWidget->setCurrentWidget(ui->search_song_list);
}

void MainWindow::insertMusicFileItem(FileSongItem *widget)
{
	auto ptr = new QListWidgetItem;

	ui->home_list_control->addItem(ptr);
	ui->song_list_control->setItemWidget(ptr, widget);
	ui->stackedWidget->setCurrentWidget(ui->music_file_list);
}

void MainWindow::createMusicFile(const QString& name, const QString& singer, const QByteArray& arr)
{
	QString file_name = singer + "_" + name + ".mp3";
	QDir dir(QCoreApplication::applicationDirPath());
	if (!dir.exists("music_files")) {
		dir.mkdir("music_files");
	}
	dir.cd("music_files");

	QFile file(dir.absolutePath() + "/" + file_name);
	file.open(QIODevice::WriteOnly);
	file.write(arr);
	file.close();

	showTip("下载完成", true);
}

void MainWindow::initWidget()
{
	ui = new Ui::AudioPlayer();
	ui->setupUi(this);
	ui->search_lineedit->setFrameColor(QColor(90, 93, 97));
	ui->search_lineedit->setTargetColor(QColor(255, 255, 255));
	ui->search_lineedit->setBackgroundColor(QColor(90, 93, 97));
	ui->search_lineedit->setFocusInFontColor(QColor(80, 80, 80));
	ui->search_lineedit->setFocusOutFontColor(QColor(255, 255, 255));
	ui->search_lineedit->setPlaceholderText("搜索歌曲");
	ui->search_lineedit->setFocusInPlaceholderTextColor(QColor(150, 150, 150));
	ui->search_lineedit->setFocusOutPlaceholderTextColor(QColor(255, 255, 255));

	m_floatWindow	= new TinyWidgetLibrary::PointFixedWidget(ui->volume);

	QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	policy.setVerticalStretch(0);
	policy.setHorizontalStretch(0);
	policy.setHeightForWidth(m_floatWindow->sizePolicy().hasHeightForWidth());

	m_floatWindow->setSize(QSize(20, 100));
	m_floatWindow->setOrientation(TinyWidgetLibrary::PointFixedWidget::Orientation::TOP);
	m_floatWindow->setSizePolicy(policy);

	m_slider		= new TinyWidgetLibrary::Slider(m_floatWindow);
	m_slider->setDirection(TinyWidgetLibrary::Slider::Direction::BottomToTop);
	m_slider->setFixedSize(QSize(20, 100));

	auto layout		= new QVBoxLayout(m_floatWindow);
	layout->setSpacing(0);
	layout->addWidget(m_slider);
	layout->setContentsMargins(0, 0,0, 0);

	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}

void MainWindow::initHandle()
{
	m_handlers.insert(ReqId::ID_LOGIN_USER,
		[this](const QByteArray& arr, const QJsonObject& obj)
		{
			QJsonArray home_list_arr = obj["home_list_song_message"].toArray();

			for (int i = 0; i < home_list_arr.size(); i++) {
				auto item = new SongItem();
				QJsonObject msg = home_list_arr[i].toObject();

				connect(item, &SongItem::remove_button_clicked,
					this, &MainWindow::slotSongItemLoveButtonClicked);
				connect(item, &SongItem::download_button_clicked,
					this, &MainWindow::slotSongItemDownLoadButtonClicked);

				item->setLoved(false);
				item->setNumber(i + 1);
				item->setSinger(msg["singer"].toString());
				item->setSongName(msg["song_name"].toString());
				item->setTime(transfTimeStr(msg["time"].toInt()));

				insertHomeSongItem(item);
			}

			QJsonArray love_list_arr = obj["love_list_song_message"].toArray();

			for (int i = 0; i < love_list_arr.size(); i++) {
				auto item = new SongItem();
				QJsonObject msg = love_list_arr[i].toObject();
				QString singer = msg["singer"].toString();
				QString song_name = msg["song_name"].toString();
				int duration = msg["song_duration"].toInt();

				connect(item, &SongItem::love_button_clicked,
					this, &MainWindow::slotSongItemRemoveButtonClicked);
				connect(item, &SongItem::download_button_clicked,
					this, &MainWindow::slotSongItemDownLoadButtonClicked);

				item->setLoved(true);
				item->setNumber(i + 1);
				item->setSinger(singer);
				item->setSongName(song_name);
				item->setTime(transfTimeStr(duration));

				insertLoveSongItem(item);
			}
		});

	m_handlers.insert(ReqId::ID_SEARCH_SONG,
		[this](const QByteArray& arr, const QJsonObject& json)
		{
			ui->search_list_control->clear();

			QJsonObject obj(QJsonDocument::fromJson(arr).object());
			QJsonArray search_list_arr = obj["search_list_song_message"].toArray();

			for (int i = 0; i < search_list_arr.size(); i++) {
				auto item = new SongItem();
				QJsonObject msg = search_list_arr[i].toObject();
				QString singer = msg["singer"].toString();
				QString song_name = msg["song_name"].toString();

				connect(item, &SongItem::love_button_clicked,
					this, &MainWindow::slotSongItemLoveButtonClicked);
				connect(item, &SongItem::download_button_clicked,
					this, &MainWindow::slotSongItemDownLoadButtonClicked);

				item->setLoved(true);
				item->setNumber(i + 1);
				item->setSinger(singer);
				item->setSongName(song_name);
				item->setTime(transfTimeStr(msg["song_duration"].toInt()));

				insertSearchSongItem(item);
			}

			ui->stackedWidget->setCurrentWidget(ui->search_list_control);
		});

	m_handlers.insert(ReqId::ID_ADD_SONG_TO_SONGLIST,
		[this](const QByteArray& arr, const QJsonObject& json)
		{
			QJsonDocument doc(QJsonDocument::fromJson(arr));
			QJsonObject obj(doc.object());

			auto item = new SongItem();
			item->setLoved(true);
			item->setSinger(obj["singer"].toString());
			item->setSongName(obj["song_name"].toString());
			item->setTime(transfTimeStr(obj["duration"].toInt()));

			ui->stackedWidget->setCurrentWidget(ui->song_list_control);
		});

	m_handlers.insert(ReqId::ID_REMOVE_SONG_TO_SONGLIST,
		[this](const QByteArray& arr, const QJsonObject& json)
		{
			QJsonDocument doc(QJsonDocument::fromJson(arr));
			QJsonObject obj(doc.object());

			QString singer = obj["singer"].toString();
			QString song_name = obj["song_name"].toString();

			for (int i = 0; i < ui->local_list_control->count(); i++) {
				auto it = ui->local_list_control->item(i);
				auto item = dynamic_cast<SongItem*>(
					ui->local_list_control->itemWidget(it)
					);

				if (item->getSongName() == song_name &&
					item->getSinger() == singer) {
					ui->local_list_control->removeItemWidget(it);
					break;
				}
			}

			ui->stackedWidget->setCurrentWidget(ui->song_list_control);
		});

	m_handlers.insert(ReqId::ID_DOWNLOAD_SONG,
		[this](const QByteArray& arr, const QJsonObject& json)
		{
			SongMessage message;
			message.singer = json["singer"].toString();
			message.song_name = json["song_name"].toString();
			message.duration = json["duration"].toInt();

			m_buffer->addSource(message, arr);
			createMusicFile(message.song_name, message.singer, arr);
		});

	m_handlers.insert(ReqId::ID_GET_SONG_BODY,
		[this](const QByteArray& arr, const QJsonObject& json)
		{
			SongMessage message;
			message.singer = json["singer"].toString();
			message.song_name = json["song_name"].toString();
			message.duration = json["duration"].toInt();

			m_buffer->addSource(message, arr);
			ui->singer->setText(message.singer);
			ui->singer->setText(message.song_name);
			setSongTimer(message.duration);
		});

}

void MainWindow::initConnect()
{
	connect(ui->min, &QPushButton::clicked,
		this, &QWidget::showMinimized);
	connect(ui->close, &QPushButton::clicked,
		this, &QWidget::close);
	connect(ui->pre_button, &QPushButton::clicked,
		this, &MainWindow::slotPreButtonClicked);
	connect(ui->next_button, &QPushButton::clicked,
		this, &MainWindow::slotNextButtonClicked);
	connect(ui->play_button, &QPushButton::clicked,
		this, &MainWindow::slotPlayButtonClicked);
	connect(ui->open_file, &QPushButton::clicked,
		this, &MainWindow::slotLocalFileButtonClicked);
	connect(ui->search_lineedit->getLineEdit(), &QLineEdit::returnPressed,
		this, &MainWindow::slotSearchSongNameReturn);
	connect(m_slider, &TinyWidgetLibrary::Slider::valueChanged,
		m_player->audioOutput(), &QAudioOutput::setVolume);
	connect(ui->volume, &QPushButton::clicked,
		[&] { m_floatWindow->setVisible(!m_floatWindow->isVisible()); });
	connect(ui->home, &QPushButton::clicked,
		[&] { ui->stackedWidget->setCurrentWidget(ui->home_song_list); });
	connect(ui->love_list, &QPushButton::clicked,
		[&] { ui->stackedWidget->setCurrentWidget(ui->love_song_list); });
	connect(ui->file_set, &QPushButton::clicked,
		[&] { ui->stackedWidget->setCurrentWidget(ui->music_file_list); });
	connect(ui->search, &QPushButton::clicked,
		[&] { ui->stackedWidget->setCurrentWidget(ui->search_song_list); });
	connect(m_player, &MediaPlayer::durationChanged,
		this, &MainWindow::slotProgressMove);
	connect(HttpMgr::GetInstance().get(), &HttpMgr::signalMusicMod,
		this, &MainWindow::slotMusicModFinish);
	connect(this, &MainWindow::login_success,
		[&](const QJsonObject obj) { slotMusicModFinish(ID_LOGIN_USER, "", SUCCESS, obj); });
}
