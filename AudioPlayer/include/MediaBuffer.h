#ifndef MEDIABUFFER_H
#define MEDIABUFFER_H

#include "chrono"
#include <qmap.h>
#include <qlist.h>
#include <qtimer.h>
#include <qalgorithms.h>

struct SongMessage
{
	QString song_name;
	QString singer;
	int duration;


	bool operator<(const SongMessage& message)
	{
		return *this < message;
	}
};

bool operator<(const SongMessage& a, const SongMessage& b)
{
	return a.singer < b.singer;
}

class MediaBuffer : public QObject
{
	Q_OBJECT

public:

	explicit MediaBuffer(QObject* parent = nullptr);

	virtual ~MediaBuffer() = default;

	inline void setMax(qint32 num) { m_max = num; } //设置最大歌曲的数目

	inline void setTime(qint32 second) { m_second = second; } //设置歌曲的存活时间

	inline void setTimer(qint32 second) { m_timer.setInterval(second); } //设置定时器定时清理buffer内歌曲的时长

	inline bool hasSource(const SongMessage& message) { return m_idx.count(message); }

	bool getSource(const SongMessage& source, QByteArray* arr);

	void addSource(const SongMessage& source, const QByteArray& arr);

private:

	struct Node
	{
		time_t time;
		SongMessage message;
		QByteArray data;
	};

private:

	void _pop_front();

	void _update(qint32 idx);

	void _sift_down(qint32 idx);

	void _swap_node(qint32 i, qint32 j);

private slots:

	void _tick();

private:

	qint32						m_max;
	qint32						m_second;
	QTimer						m_timer;
	QList<Node>					m_Heap;
	QMap<SongMessage, qint32>	m_idx;
};


#endif // !MEDIABUFFER_H
