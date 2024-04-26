
//int ClientControl::start(int avgc, char **avgv)
//{
//	QApplication a(avgc, avgv);
//	QHostAddress addr("127.0.0.1");
//	if (initSocket(addr, 5000)) {
//		initLoginWindow();
//	}
//	return QApplication::exec();
//}
//
//void ClientControl::onLoginWindowLoginButtonClicked()
//{
//	QString usr = m_loginWindow->getAccount();
//	QString pwd = m_loginWindow->getPassword();
//
//	bool flag = usr.isEmpty();
//	flag = flag || pwd.isEmpty();
//
//	if (flag) {
//		messageHint("请输入用户名或密码");
//	}
//	else {
//		m_socket->sendLogin(usr, pwd);
//		m_socket->waitForReadyRead(500);
//	}
//}
//
//void ClientControl::onLoginWindowRegisterButtonClicked()
//{
//	m_loginWindow->hide();
//	m_registerWindow->show();
//}
//
//void ClientControl::loginSuccess(bool flag, const QJsonObject &obj)
//{
//	if (!flag) {
//		messageHint("输入的账号或密码错误");
//		return;
//	}
//
//	m_user->deleteLater();
//	m_loginWindow->deleteLater();
//	m_registerWindow->deleteLater();
//
//	m_user				= nullptr;
//	m_loginWindow		= nullptr;
//	m_registerWindow	= nullptr;
//
//	initMusicWindow();
//
//	LoveItem list;
//	loginSuccessAddLoveItem(&list, obj);
//	loginSuccessAddHomeItem(list, obj);
//}
//
//void ClientControl::onEnrollWindowCancelButtonClicked()
//{
//	m_registerWindow->hide();
//	m_loginWindow->show();
//}
//
//void ClientControl::onEnrollWindowRegisterButtonClicked()
//{
//	QString usr = m_registerWindow->getNumber();
//	QString pwd = m_registerWindow->getPassword();
//	QString again_pwd = m_registerWindow->getConfirmPassword();
//
//	bool flag = usr.isEmpty();
//	flag = flag || pwd.isEmpty();
//	flag = flag || again_pwd.isEmpty();
//	flag = flag || (pwd != again_pwd);
//
//	if (flag) {
//		QString str;
//
//		if (usr.isEmpty()) {
//			str = QString("请输入用户名");
//		}
//		else if (pwd.isEmpty()) {
//			str = QString("请输入用户的密码");
//		}
//		else if (again_pwd.isEmpty()) {
//			str = QString("请再次输入用户的密码");
//		}
//		else {
//			str = QString("再次输入的密码和原密码不同");
//		}
//
//		messageHint(str);
//	}
//	else {
//		m_socket->sendEnroll(usr, pwd);
//		m_socket->waitForReadyRead(500);
//	}
//}
//
//void ClientControl::enrollSuccess(bool flag, const QJsonObject &obj)
//{
//	QString str;
//
//	if (flag) {
//		str = "注册成功";
//		m_registerWindow->hide();
//		m_loginWindow->show();
//	}
//	else {
//		str = "你的账户已经存在";
//	}
//
//	messageHint(str);
//}
//
//void ClientControl::volumeChange(int value)
//{
//	m_player->setVolume(value);
//}
//
//void ClientControl::onMainWindowPreButtonClicked()
//{
//	QListWidget* ptr	= m_musicWindow->getCurrentList();
//	if (ptr == nullptr) return;
//
//	int idx				= ptr->currentRow();
//	if (idx == -1) return;
//
//	idx = (idx - 1 + ptr->count()) % ptr->count();
//	ptr->setCurrentRow(idx);
//	emit ptr->itemDoubleClicked(ptr->item(idx));
//}
//
//void ClientControl::onMainWindowNextButtonClicked()
//{
//	QListWidget* ptr	= m_musicWindow->getCurrentList();
//	if (ptr == nullptr) return;
//
//	int idx				= ptr->currentRow();
//	if (idx == -1) return;
//
//	idx = (idx + 1) % ptr->count();
//	ptr->setCurrentRow(idx);
//	emit ptr->itemDoubleClicked(ptr->item(idx));
//}
//
//void ClientControl::onMainWindowPlayButtonClicked()
//{
//	bool state = m_musicWindow->getPlayState();
//	m_musicWindow->setPlayState(state);
//	if (state) {
//		m_player->play();
//	}
//	else {
//		m_player->pause();
//	}
//}
//
//void ClientControl::onMainWindowSearchSong(const QString &song)
//{
//	m_socket->sendSearchSong(song);
//	m_socket->waitForReadyRead(500);
//}
//
//void ClientControl::onNetworkSongItemClicked(QListWidgetItem *item)
//{
//	QListWidget *ptr = m_musicWindow->getCurrentList();
//	if (ptr == nullptr) return;
//
//	auto it = dynamic_cast<SongItem*>(ptr->itemWidget(item));
//	if (it == nullptr) return;
//
//	const QString singer	= it->getSinger();
//	const QString song_name = it->getSongName();
//	const QStringList list({singer, song_name});
//
//	if (!m_buffer->hasSource(list)) {
//		quint16 port = 50001;
//		QHostAddress addr("127.0.0.1");
//		m_resourceSocket->connectToHost(addr, port);
//		m_resourceSocket->waitForConnected(500);
//
//		QByteArray arr = m_resourceSocket->getMusicFile(song_name, singer);
//		m_resourceSocket->disconnectFromHost();
//
//		if (m_resourceSocket->isValid()) {
//			m_buffer->addSource(list, arr);
//		}
//	}
//	
//	playBufferSong(singer, song_name);
//}
//
//void ClientControl::onAddLocalFileButtonClicked()
//{
//	const QStringList name_list = QFileDialog::getOpenFileNames(
//			nullptr, "获取本地歌集", "music_files", "*.mp3");
//
//	if (name_list.empty()) return;
//
//	m_musicWindow->setLocalFilePageToCurrent();
//	m_musicWindow->getMusicFileSongList()->clear();
//
//	for (int i = 0; i < name_list.size(); i++) {
//		auto item = new FileSongItem(name_list[i]);
//		item->setNumber(i + 1);
//
//		connect(item, &FileSongItem::remove_button_clicked,
//				this, &ClientControl::onLocalFileItemRemoveButtonClicked);
//
//		m_musicWindow->insertMusicFileItem(item);
//	}
//}
//
//void ClientControl::onLocalFileItemRemoveButtonClicked(FileSongItem *item)
//{
//	auto ptr = m_musicWindow->getMusicFileSongList();
//	ptr->removeItemWidget(
//			findLocalItem(m_musicWindow->getMusicFileSongList(), item->getSongPath())
//			);
//
//	adjustLocalSongItemNumber(ptr);
//}
//
//void ClientControl::onLocalFileSongItemClicked(QListWidgetItem *item)
//{
//	const QString path = dynamic_cast<FileSongItem*>(
//			m_musicWindow->getLoveSongList()->itemWidget(item)
//			)->getSongPath();
//
//	m_player->setSource(path);
//	m_musicWindow->setSinger("");
//	m_musicWindow->setSongName(path);
//	m_musicWindow->setSongDuration((int)m_player->duration());
//}
//
//void ClientControl::onItemLoveButtonClicked(SongItem *ptr)
//{
//	m_socket->sendAddSongToSongList(ptr->getSongName(), ptr->getSinger());
//	m_socket->waitForReadyRead(500);
//}
//
//void ClientControl::onItemRemoveButtonClicked(SongItem *ptr)
//{
//	m_socket->sendRemoveSongFromSongList(ptr->getSongName(), ptr->getSinger());
//	m_socket->waitForReadyRead(500);
//}
//
//void ClientControl::onItemDownLoadButtonClicked(SongItem *item)
//{
//	if (item == nullptr) return;
//
//	QByteArray arr;
//	QStringList list;
//	list << item->getSinger() << item->getSongName();
//
//	if (!m_buffer->hasSource(list)) {
//		quint16 port = 50001;
//		QHostAddress addr("127.0.0.1");
//		m_resourceSocket->connectToHost(addr, port);
//		m_resourceSocket->waitForConnected(500);
//		arr = m_resourceSocket->getMusicFile(list[0], list[1]);
//		m_resourceSocket->disconnectFromHost();
//
//		if (m_resourceSocket->isValid()) {
//			Q_ASSERT(m_buffer->hasSource(list));
//			m_buffer->addSource(list, arr);
//		}
//	}
//
//	m_buffer->getSource(list, &arr);
//	downLoadMusicFile(list[0], list[1], arr);
//}
//
//void ClientControl::onMainWindowSliderMoved(int value)
//{
//	m_musicWindow->setSongCurrentTime(value);
//}
//
//void ClientControl::onMainWindowSliderReleased(int value)
//{
//	m_player->setPosition(value * m_player->duration() / m_musicWindow->getProgressMax());
//}
//
//void ClientControl::onMainWindowTimeProcessChanged(int value)
//{
//	m_musicWindow->setSongDuration(value);
//}
//
//void ClientControl::searchSongSuccess(bool flag, const QJsonObject &obj)
//{
//	if (!flag) {
//		messageHint("搜索歌曲失败");
//		return;
//	}
//
//	m_musicWindow->setSearchPageToCurrent();
//	m_musicWindow->getSearchSongList()->clear();
//	searchSuccessAddItem(obj);
//}
//
//void ClientControl::onItemLoveSuccess(bool flag, const QJsonObject &obj)
//{
//	if (!flag) return;
//
//	auto love_ptr	= m_musicWindow->getLoveSongList();
//	if (love_ptr == nullptr) return;
//
//	auto home_ptr	= m_musicWindow->getHomeSongList();
//	if (home_ptr == nullptr) return;
//
//	QString name	= obj["song_name"].toString();
//	QString singer	= obj["singer"].toString();
//
//	auto ptr	= dynamic_cast<SongItem*>(home_ptr->itemWidget(findNetworkItem(home_ptr, name, singer)));
//	if (ptr == nullptr) return;
//
//	auto new_ptr	= new SongItem();
//
//	connect(new_ptr, &SongItem::remove_button_clicked,
//			this, &ClientControl::onItemRemoveButtonClicked);
//
//	ptr->setLoved(true);
//	new_ptr->setLoved(true);
//	new_ptr->setSinger(singer);
//	new_ptr->setSongName(name);
//
//	m_musicWindow->insertLoveSongItem(new_ptr);
//	adjustNetworkSongItemNumber(love_ptr);
//}
//
//void ClientControl::onItemRemoveSuccess(bool flag, const QJsonObject &obj)
//{
//	if (!flag) return;
//
//	auto love_ptr	= m_musicWindow->getLoveSongList();
//	if (love_ptr == nullptr) return;
//
//	auto home_ptr	= m_musicWindow->getHomeSongList();
//	if (home_ptr == nullptr) return;
//
//	QString name	= obj["song_name"].toString();
//	QString singer	= obj["singer"].toString();
//
//	love_ptr->removeItemWidget(findNetworkItem(love_ptr, name, singer));
//	dynamic_cast<SongItem*>(home_ptr->itemWidget(
//			findNetworkItem(love_ptr, name, singer)))->setLoved(false);
//
//	adjustNetworkSongItemNumber(m_musicWindow->getLoveSongList());
//}
//
//void ClientControl::initLoginWindow()
//{
//	m_user				= new LocalUsr(this);
//	m_loginWindow		= new LoginWindow();
//	m_registerWindow	= new RegisterWindow();
//	QList<QString> users = m_user->getUsers();
//
//	for (const QString& user : users) m_loginWindow->addAccount(user);
//
//	connect(m_loginWindow, &LoginWindow::login_button_clicked,
//			this, &ClientControl::onLoginWindowLoginButtonClicked);
//	connect(m_loginWindow, &LoginWindow::register_button_clicked,
//			this, &ClientControl::onLoginWindowRegisterButtonClicked);
//	connect(m_loginWindow, &LoginWindow::close_button_clicked,
//			this, &ClientControl::deleteLater);
//	connect(m_registerWindow, &RegisterWindow::register_button_clicked,
//			this, &ClientControl::onEnrollWindowRegisterButtonClicked);
//	connect(m_registerWindow, &RegisterWindow::cancel_button_clicked,
//			this, &ClientControl::onEnrollWindowCancelButtonClicked);
//	connect(m_registerWindow, &RegisterWindow::close_button_clicked,
//			this, &ClientControl::deleteLater);
//	connect(m_socket, &TcpSocket::loginSuccess, this, &ClientControl::loginSuccess);
//	connect(m_socket, &TcpSocket::enrollSuccess, this, &ClientControl::enrollSuccess);
//	connect(m_socket, &TcpSocket::disconnected, this, &ClientControl::deleteLater);
//
//	m_loginWindow->show();
//}
//
//void ClientControl::initMusicWindow()
//{
//	m_musicWindow 		= new MainWindow();
//	m_files				= new LocalFile(this);
//	m_buffer			= new MediaBuffer(this);
//	m_player			= new MediaPlayer(this);
//	m_resourceSocket 	= new ResourceFileSocket(this);
//
//	m_musicWindow->setHomePageToCurrent();
//	m_musicWindow->setVolumeCurrentValue(m_player->getVolume());
//
//	connect(m_musicWindow, &MainWindow::pre_button_clicked,
//			this, &ClientControl::onMainWindowPreButtonClicked);
//	connect(m_musicWindow, &MainWindow::next_button_clicked,
//			this, &ClientControl::onMainWindowNextButtonClicked);
//	connect(m_musicWindow, &MainWindow::play_button_clicked,
//			this, &ClientControl::onMainWindowPlayButtonClicked);
//
//	connect(m_musicWindow, &MainWindow::local_file_button_clicked,
//			this, &ClientControl::onAddLocalFileButtonClicked);
//	connect(m_musicWindow->getMusicFileSongList(), &QListWidget::itemDoubleClicked,
//			this, &ClientControl::onLocalFileSongItemClicked);
//
//	connect(m_musicWindow, &MainWindow::volume_slider_move,
//			this, &ClientControl::volumeChange);
//	connect(m_musicWindow, &MainWindow::process_slider_release,
//			this, &ClientControl::onMainWindowSliderReleased);
//	connect(m_player, &QMediaPlayer::positionChanged,
//			this, &ClientControl::onMainWindowSliderMoved);
//	connect(m_player, &QMediaPlayer::durationChanged,
//			this, &ClientControl::onMainWindowTimeProcessChanged);
//
//	connect(m_musicWindow, &MainWindow::search_lineedit_return,
//			this, &ClientControl::onMainWindowSearchSong);
//	connect(m_socket, &TcpSocket::searchSongSuccess,
//			this, &ClientControl::searchSongSuccess);
//
//	connect(m_musicWindow->getHomeSongList(), &QListWidget::itemDoubleClicked,
//			this, &ClientControl::onNetworkSongItemClicked);
//	connect(m_musicWindow->getLoveSongList(), &QListWidget::itemDoubleClicked,
//			this, &ClientControl::onNetworkSongItemClicked);
//
//	connect(m_socket, &TcpSocket::addSongToSongListSuccess,
//			this, &ClientControl::onItemLoveSuccess);
//	connect(m_socket, &TcpSocket::removeSongFromSongListSuccess,
//			this, &ClientControl::onItemRemoveSuccess);
//
//}
//
//bool ClientControl::initSocket(const QHostAddress &address, quint16 port)
//{
//	m_socket = new TcpSocket(this);
//	m_socket->connectToHost(address, port);
//	return m_socket->waitForConnected(3000);
//}
//
//void ClientControl::playBufferSong(const QString &singer, const QString &name)
//{
//	QByteArray data;
//	QStringList list({singer, name});
//
//	m_musicWindow->setSinger(singer);
//	m_musicWindow->setSongName(name);
//	m_musicWindow->setPlayState(true);
//	m_buffer->getSource(list, &data);
//	m_player->setData(data);
//	m_player->play();
//}
//
//void ClientControl::messageHint(const QString &message)
//{
//	auto ptr = new TinyWidgetLibrary::MessageBoxHint;
//	ptr->setText(message);
//	ptr->show();
//}
//
//void ClientControl::loginSuccessAddLoveItem(ClientControl::LoveItem *list, const QJsonObject &obj)
//{
//	QJsonArray love_list_arr = obj["love_list_song_message"].toArray();
//
//	for (int i = 0; i < love_list_arr.size(); i++) {
//		auto item	= new SongItem();
//		QJsonObject msg		= love_list_arr[i].toObject();
//		QString singer		= msg["singer"].toString();
//		QString song_name	= msg["song_name"].toString();
//		int duration        = msg["song_duration"].toInt();
//
//		connect(item, &SongItem::love_button_clicked,
//				this, &ClientControl::onItemLoveButtonClicked);
//		connect(item, &SongItem::download_button_clicked,
//				this, &ClientControl::onItemDownLoadButtonClicked);
//
//		item->setLoved(true);
//		item->setNumber(i + 1);
//		item->setSinger(singer);
//		item->setSongName(song_name);
//		item->setTime(conversion(duration));
//
//		m_musicWindow->insertLoveSongItem(item);
//		list->append(qMakePair(singer, song_name));
//	}
//}
//
//void ClientControl::loginSuccessAddHomeItem(const ClientControl::LoveItem &list, const QJsonObject &obj)
//{
//	QJsonArray home_list_arr = obj["home_list_song_message"].toArray();
//
//	for (int i = 0; i < home_list_arr.size(); i++) {
//		auto item	= new SongItem();
//		QJsonObject msg = home_list_arr[i].toObject();
//
//		connect(item, &SongItem::remove_button_clicked,
//				this, &ClientControl::onItemRemoveButtonClicked);
//		connect(item, &SongItem::download_button_clicked,
//				this, &ClientControl::onItemDownLoadButtonClicked);
//
//		auto it = std::find_if(list.begin(), list.end(),
//				[&](const QPair<QString, QString>& a)
//				{
//					return a.first == item->getSinger()
//						   && a.second == item->getSongName();
//				}
//		);
//
//		item->setNumber(i + 1);
//		item->setLoved(it == list.end());
//		item->setSinger(msg["singer"].toString());
//		item->setSongName(msg["song_name"].toString());
//		item->setTime(conversion(msg["time"].toInt()));
//
//		m_musicWindow->insertHomeSongItem(item);
//	}
//}
//
//void ClientControl::searchSuccessAddItem(const QJsonObject &obj)
//{
//	QJsonArray search_list_arr = obj["search_list_song_message"].toArray();
//
//	for (int i = 0; i < search_list_arr.size(); i++) {
//		auto item			= new SongItem();
//		QJsonObject msg		= search_list_arr[i].toObject();
//		QString singer		= msg["singer"].toString();
//		QString song_name	= msg["song_name"].toString();
//
//		connect(item, &SongItem::love_button_clicked,
//				this, &ClientControl::onItemLoveButtonClicked);
//		connect(item, &SongItem::download_button_clicked,
//				this, &ClientControl::onItemDownLoadButtonClicked);
//
//		item->setLoved(true);
//		item->setNumber(i + 1);
//		item->setSinger(singer);
//		item->setSongName(song_name);
//		item->setTime(conversion(msg["song_duration"].toInt()));
//
//		m_musicWindow->insertSearchSongItem(item);
//	}
//}
//
//void ClientControl::adjustNetworkSongItemNumber(QListWidget *ptr)
//{
//	for (int i = 0; i < ptr->count(); i++) {
//		auto item = dynamic_cast<SongItem*>(ptr->itemWidget(ptr->item(i)));
//		item->setNumber(i);
//	}
//}
//
//void ClientControl::adjustLocalSongItemNumber(QListWidget *ptr)
//{
//	for (int i = 0; i < ptr->count(); i++) {
//		auto item = dynamic_cast<FileSongItem*>(ptr->itemWidget(ptr->item(i)));
//		item->setNumber(i);
//	}
//}
//
//void ClientControl::downLoadMusicFile(const QString &singer, const QString &name, QByteArray &arr)
//{
//	QString file_name = "_" + singer + "_" + name + ".mp3";
//	QDir dir(QCoreApplication::applicationDirPath());
//	dir.mkdir("music_files");
//	dir.cd("music_files");
//	
//	QFile file(dir.absolutePath() + "/" + file_name);
//
//	file.open(QIODevice::WriteOnly);
//	file.write(arr);
//	file.close();
//}
//
//QListWidgetItem* findNetworkItem(QListWidget* ptr, const QString& name, const QString& singer)
//{
//	for (int i = 0; i < ptr->count(); ++i) {
//		auto p = dynamic_cast<SongItem*>(ptr->item(i));
//		if (p != nullptr && p->getSongName() == name && singer == p->getSinger()) {
//			return ptr->item(i);
//		}
//	}
//	return nullptr;
//}
//
//
//QListWidgetItem* findLocalItem(QListWidget* ptr, const QString& path)
//{
//	for (int i = 0; i < ptr->count(); ++i) {
//		auto p = dynamic_cast<FileSongItem*>(ptr->item(i));
//		if (p != nullptr && p->getSongPath() == path) {
//			return ptr->item(i);
//		}
//	}
//	return nullptr;
//}