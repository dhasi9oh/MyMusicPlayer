#include "LocalUsr.h"

LocalUsr::LocalUsr(QObject* parent)
	: QObject(parent)
	, m_user(QSqlDatabase::addDatabase("QSQLITE"))
{
	m_user.setDatabaseName("user.db");
	m_user.open();

	Q_ASSERT(m_user.isOpen());

	QString sql = QString(
		"create table if not exists user("
		"	usr varchar(10) unique,"
		"	pwd varchar(10),"
		"	rmb_pwd int,"
		"	auto_login int"
		");"
	);

	m_user.exec(sql);
	Q_ASSERT(m_user.lastError().type() == QSqlError::NoError);
	m_user.close();
}

LocalUsr::~LocalUsr()
{
	if (m_user.isOpen()) {
		m_user.close();
	}
}

bool LocalUsr::hasUser(const QString& usr)
{
	QString sql = QString(
		"select * from user where usr='%1';"
	);

	sql = sql.arg(usr);
	m_user.open();
	QSqlQuery query = m_user.exec(sql);
	m_user.close();
	Q_ASSERT(m_user.lastError().type() == QSqlError::NoError);

	return query.next();
}

QList<QString> LocalUsr::getUsers()
{
	QString sql = QString(
		"select usr from user;"
	);

	m_user.open();
	QSqlQuery query = m_user.exec(sql);
	Q_ASSERT(m_user.lastError().type() == QSqlError::NoError);
	m_user.close();
	query.next();
	return query.value("usr").toStringList();
}

QString LocalUsr::getPassword(const QString& usr)
{
	QString sql = QString(
		"select pwd from user where usr='%1';"
	);
	sql = sql.arg(usr);
	m_user.open();
	QSqlQuery query = m_user.exec(sql);
	m_user.close();
	Q_ASSERT(m_user.lastError().type() == QSqlError::NoError);

	query.next();
	return query.value("pwd").toString();
}

void LocalUsr::addUser(const QString& usr, const QString& pwd)
{
	if (hasUser(usr)) { return; }

	QString sql = QString(
		"insert into user(usr, pwd) values('%1', '%2');"
	);
	sql = sql.arg(usr).arg(pwd);
	m_user.open();
	QSqlQuery query = m_user.exec(sql);
	m_user.close();
}

void LocalUsr::removeUser(const QString& usr)
{
	if (!hasUser(usr)) { return; }

	QString sql = QString(
		"delete from user where usr='%1';"
	);
	sql = sql.arg(usr);
	m_user.open();
	QSqlQuery query = m_user.exec(sql);
	m_user.close();
	Q_ASSERT(m_user.lastError().type() == QSqlError::NoError);
}
