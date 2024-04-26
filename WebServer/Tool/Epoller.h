#ifndef UTILS_EPOLLER_H
#define UTILS_EPOLLER_H

#ifdef __linux__

#include <vector>
#include <assert.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <unordered_map>

class Epoller
{
public:

	Epoller(int max_cnt)
		: m_MaxCnt(max_cnt)
		, m_Events(max_cnt)
	{
		m_EpollFd = epoll_create(m_MaxCnt);
	}

	~Epoller()
	{
		close(m_EpollFd);
	}

	bool addFd(int fd, uint32_t event)
	{
		if (fd < 0) return false;

		epoll_event ev = {};
		ev.data.fd = fd;
		ev.events = event;

		return epoll_ctl(m_EpollFd, EPOLL_CTL_ADD, fd, &ev) == 0;
	}

	bool modFd(int fd, uint32_t events)
	{
		if (fd < 0) return false;

		epoll_event ev = {};
		ev.data.fd = fd;
		ev.events = events;

		return epoll_ctl(m_EpollFd, EPOLL_CTL_MOD, fd, &ev) == 0;
	}

	bool delFd(int fd)
	{
		if (fd < 0) return false;

		epoll_event ev = {};

		return epoll_ctl(m_EpollFd, EPOLL_CTL_DEL, fd, &ev) == 0;
	}

	int wait(int timeout)
	{
		return epoll_wait(m_EpollFd, std::addressof(m_Events.front()), (int)m_Events.size(), timeout);
	}

	int getIndexFd(int idx) const
	{
		assert(idx >= 0 && idx < m_Events.size());
		return m_Events[idx].data.fd;
	}

	uint32_t getIdxEvent(int idx) const
	{
		assert(idx >= 0 && idx < m_Events.size());
		return m_Events[idx].events;
	}


private:

	int m_MaxCnt;

	int m_EpollFd;

	std::vector<struct epoll_event> m_Events;

};


#endif // __linux__

#endif // !UTILS_EPOLLER_H
