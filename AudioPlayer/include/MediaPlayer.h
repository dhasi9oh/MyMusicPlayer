#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <qbuffer.h>
#include <qmediaplayer.h>
#include <qaudiooutput.h>
#include <qsharedpointer.h>

class MediaPlayer : public QMediaPlayer
{
	Q_OBJECT

public:

	explicit MediaPlayer(QObject* parent = nullptr)
		: QMediaPlayer(parent)
	{
		QAudioOutput* output = new QAudioOutput(this);
		setAudioOutput(output);
	}

	virtual ~MediaPlayer() = default;

public slots:

	void setData(const QByteArray& arr)
	{
		m_data = arr;
		m_buf.reset(new QBuffer(&m_data));
		m_buf->open(QIODeviceBase::ReadOnly);
		setSourceDevice(&*m_buf);
	}

private:

	QByteArray m_data;
	QSharedPointer<QBuffer> m_buf;

};





#endif