#include <QApplication>
#include <qpushbutton.h>
#include <qstyle.h>
#include "RedirectWindow.h"
#include "SongItem.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");

    if (qss.open(QFile::ReadOnly))
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else {
        qDebug("Open failed");
    }
    // ��ȡ��ǰӦ�ó����·��
    QString app_path = QCoreApplication::applicationDirPath();
    // ƴ���ļ���
    QString fileName = "config.ini";
    QString config_path = QDir::toNativeSeparators(app_path +
        QDir::separator() + fileName);

    QSettings settings(config_path, QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://" + gate_host + ":" + gate_port;

	return a.exec();
}