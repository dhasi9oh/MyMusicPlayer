//
// Created by 86186 on 2023/12/31.
//

#ifndef UTILS_THREADPOOL_H
#define UTILS_THREADPOOL_H

#include <future>
#include <thread>
#include <vector>
#include <functional>
#include <type_traits>

#include "BlockQueue.h"


class ThreadPool {
public:

	ThreadPool(size_t);

	ThreadPool(const ThreadPool&) = delete;

	ThreadPool& operator=(const ThreadPool&) = delete;

	~ThreadPool();

	template<class F, class... Args>
	auto emplace(F&& f, Args&&... args)
	-> std::future<typename std::result_of<F(Args...)>::type>;

private:

	std::vector< std::thread > m_Workers;

	BlockQueue<std::function<void()> > m_Tasks;

};


inline ThreadPool::ThreadPool(size_t threads)
{
	for(size_t i = 0; i < threads; ++i)
		m_Workers.emplace_back(
				[this]
				{
					while (true)
					{
						std::function<void()> task;

						if (m_Tasks.pop(task)) {
							task();
						}
						else if (!m_Tasks.isOpen() && m_Tasks.empty()) {
								return ;
						}
					}
				}
		);
}


template<class F, class... Args>
auto ThreadPool::emplace(F&& f, Args&&... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
	using return_type = typename std::result_of<F(Args...)>::type;

	auto task = std::make_shared<std::packaged_task<return_type()> >(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...)
	);

	std::future<return_type> res = task->get_future();
	m_Tasks.push([task]() { (*task)(); });

	return res;
}


inline ThreadPool::~ThreadPool()
{
	m_Tasks.close();

	for(std::thread &worker: m_Workers)
		worker.join();
}

#endif //UTILS_THREADPOOL_H
