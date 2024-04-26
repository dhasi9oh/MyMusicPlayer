#ifndef LOCALUSR_H
#define LOCALUSR_H

#include <qsqlerror.h>
#include <qsqlquery.h>
#include <qsqldatabase.h>


class LocalUsr : public QObject
{
	Q_OBJECT

public:

	using Users = QList<QString>;

public:

	explicit	LocalUsr(QObject* parent = nullptr);

	virtual		~LocalUsr();

	Users		getUsers();

	bool		hasUser(const QString& usr);

	QString		getPassword(const QString& usr);

	void		addUser(const QString& usr, const QString& pwd);

	void		removeUser(const QString& usr);

private:

	QSqlDatabase m_user;

};


#endif // !LOCALUSR_H
