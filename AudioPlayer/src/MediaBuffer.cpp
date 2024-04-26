#include "MediaBuffer.h"

MediaBuffer::MediaBuffer(QObject* parent)
	: m_max(20)
{
	m_second = 1000 * 60 * 10;
	m_timer.setInterval(1000 * 60 * 5);
}

bool MediaBuffer::getSource(const SongMessage& message, QByteArray* arr)
{
	if (!hasSource(message)) { return false; }

	qint32 idx = m_idx[message];
	*arr = m_Heap[idx].data;

	_update(idx);
	return true;
}

void MediaBuffer::addSource(const SongMessage& message, const QByteArray& arr)
{
	if (hasSource(message)) {
		qint32 idx = m_idx[message];
		_update(idx);
		return;
	}

	if (m_Heap.size() >= m_max) {
		_tick();

		if (m_Heap.size() >= m_max) {
			_pop_front();
		}
	}

	std::chrono::time_point p = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(p);

	struct Node node;
	node.data = arr;
	node.message = message;
	node.time = time + m_second;

	m_Heap.append(node);
	m_idx[message] = m_Heap.size() - 1;
}

void MediaBuffer::_pop_front()
{
	if (!m_Heap.isEmpty()) {
		m_idx.remove(m_Heap.front().message);
		m_Heap.pop_front();
	}
}

void MediaBuffer::_update(qint32 idx)
{
	Q_ASSERT(idx >= 0 && idx < m_Heap.size() && !m_Heap.empty());

	m_Heap[idx].time += m_second;

	_sift_down(idx);
}

void MediaBuffer::_sift_down(qint32 idx)
{
	Q_ASSERT(idx >= 0 && idx < m_Heap.size() && !m_Heap.empty());

	for (; idx < m_Heap.size() - 1; idx++) {
		if (m_Heap[idx + 1].time < m_Heap[idx].time) {
			_swap_node(idx, idx + 1);
		}
	}
}

void MediaBuffer::_swap_node(qint32 i, qint32 j)
{
	Q_ASSERT(i >= 0 && i < m_Heap.size());
	Q_ASSERT(j >= 0 && j < m_Heap.size());

	qSwap(m_Heap[i].time, m_Heap[j].time);
    qSwap(m_Heap[i].data, m_Heap[j].data);
    qSwap(m_Heap[i].message, m_Heap[j].message);

    qSwap(m_idx[m_Heap[i].message], m_idx[m_Heap[i].message]);
}

void MediaBuffer::_tick()
{
	std::chrono::time_point p = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(p);

	while (!m_Heap.isEmpty() && m_Heap.front().time < time) {
		_pop_front();
	}
}