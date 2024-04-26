//
// Created by 86186 on 2023/12/26.
//

#ifndef UTILS_BLOCKQUEUE_HPP
#define UTILS_BLOCKQUEUE_HPP

/*#ifndef BLOCKQUEUE_EXPORT
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif // BLOCKQUEUE_EXPORT*/

#define BLOCKQUEUE_EXPORT

#include <deque>
#include <mutex>
#include <chrono>
#include <assert.h>
#include <condition_variable>

template <class T>
class BlockQueue
{
public:

	BlockQueue(int max_size = 1000)
	{
		assert(max_size > 0);
		m_MaxSize = max_size;
		is_Open = true;
	}

	~BlockQueue()
	{
		close();
	}

	bool empty()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		return m_Deque.empty();
	}

	bool full()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		return m_Deque.size() >= m_MaxSize;
	}

	void close()
	{
		{
			std::lock_guard<std::mutex> lock(m_Mtx);
			is_Open = false;
		}

		m_PushCon.notify_all();
		m_PopCon.notify_all();
	}

	bool isOpen()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		return is_Open;
	}


	size_t size()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		return m_Deque.size();
	}

	void setMaxSize(int cnt)
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		m_MaxSize = cnt;
	}

	T front()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		return m_Deque.front();
	}

	T back()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		return m_Deque.back();
	}

	// 放入一个元素并通知一个调用了pop函数并堵塞的线程(无时间限制)
	bool push(const T& value)
	{
		std::unique_lock<std::mutex> lock(m_Mtx);

		m_PopCon.wait(lock, [this] { return !is_Open || m_Deque.size() < m_MaxSize; });
		if (!is_Open && m_Deque.size() >= m_MaxSize) return false;

		m_Deque.push_back(value);
		m_PopCon.notify_one();

		return true;
	}

	// 放入一个元素并通知一个调用了pop函数并堵塞的线程(无时间限制)
	bool emplace(T&& value)
	{
		std::unique_lock<std::mutex> lock(m_Mtx);

		m_PopCon.wait(lock, [this] { return !is_Open || m_Deque.size() < m_MaxSize; });
		if (!is_Open && m_Deque.size() >= m_MaxSize) return false;

		m_Deque.emplace(std::move(value));
		m_PopCon.notify_one();

		return true;
	}

	// 取出一个元素并通知一个调用了push函数并堵塞的线程(无时间限制)
	bool pop(T& value)
	{
		std::unique_lock<std::mutex> lock(m_Mtx);

		m_PopCon.wait(lock, [this] { return !is_Open || !m_Deque.empty(); });
		if (!is_Open && m_Deque.empty()) return false;

		value = std::move(m_Deque.front());
		m_Deque.pop_front();

		m_PushCon.notify_one();

		return true;
	}

	// 取出一个元素并通知一个调用了push函数并堵塞的线程(有时间限制)
	bool pop(T& value, int timeout)
	{
		std::unique_lock<std::mutex> lock(m_Mtx);

		if (m_PopCon.wait_for(lock,
				std::chrono::seconds(timeout),
				[this] { return !is_Open || !m_Deque.empty(); }
				)
				) return false;

		if (!is_Open && m_Deque.empty()) return false;

		value = std::move(m_Deque.front());
		m_Deque.pop_front();

		m_PushCon.notify_one();

		return true;
	}

	// 清空队列
	void clear()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		m_Deque.clear();
	}

	// 堵塞队列关闭后还剩余的全部元素
	std::deque<T>& residualData()
	{
		std::lock_guard<std::mutex> lock(m_Mtx);

		return m_Deque;
	}

private:

	int m_MaxSize;

	bool is_Open;

	std::mutex m_Mtx;

	std::deque<T> m_Deque;

	std::condition_variable m_PushCon;

	std::condition_variable m_PopCon;
};


#endif // UTILS_BLOCKQUEUE_HPP