#ifndef UTILS_LOG_H
#define UTILS_LOG_H

#include <string>
#include <atomic>
#include <iomanip>
#include <assert.h>
#include <spdlog/async.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include "fmt/core.h"
#include "ConfigMgr.h"

class Log
{
public:

	using Level = spdlog::level::level_enum;

public:

	static Log* getInstance()
	{
		static Log log;
		return &log;
	}

public:

	~Log()
	{
		is_open= false;
	}

	bool async() const
	{
		return is_async;
	}

	bool open() const
	{
		return is_open;
	}

	Level getLevel() const
	{
		return m_minLevel;
	}

	void initOut(Level level)
	{
		if (is_async) {
			spdlog::init_thread_pool(m_maxSize, 1);
			m_log = spdlog::stdout_color_mt<spdlog::async_factory>("m_Out");
		}
		else {
			m_log = spdlog::stdout_color_mt("m_Out");
		}

		m_minLevel = level;
		is_open = true;
	}

	void  initBasic(std::string name, Level level)
	{
		if (is_async) {
			spdlog::init_thread_pool(m_maxSize, 1);
			m_log = spdlog::basic_logger_mt<spdlog::async_factory>("m_AsyncBasic", name, true);
		}
		else {
			m_log = spdlog::basic_logger_mt("m_Basic", name, true);
		}

		m_minLevel = level;
		is_open = true;
	}

	void initRotating(std::string name, Level level, size_t memory_size, size_t file_cnt)
	{
		if (is_async) {
			spdlog::init_thread_pool(m_maxSize, 1);
			m_log = spdlog::rotating_logger_mt<spdlog::async_factory>("m_AsyncRotating", name, memory_size, file_cnt, true);
		}
		else {
			m_log = spdlog::rotating_logger_mt("m_Rotating", name, memory_size, file_cnt, true);
		}

		m_minLevel = level;
		is_open = true;
	}

	void initDaily(std::string name, Level level, int hour, int min, size_t file_cnt)
	{
		if (is_async) {
			spdlog::init_thread_pool(m_maxSize, 1);
			m_log = spdlog::daily_logger_mt<spdlog::async_factory>("m_AsyncDaily", name, hour, min, true, file_cnt);
		}
		else {
			m_log = spdlog::daily_logger_mt("m_Daily", name, hour, min, true, file_cnt);
		}

		m_minLevel = level;
		is_open = true;
	}

	void initMaxSize(int max_size)
	{
		m_maxSize = max_size;
	}

	void setAsync()
	{
		is_async = true;
	}

	void close()
	{
		is_open = false;
	}

	bool write(Level level, const std::string& s)
	{
		if (is_open == false) {
			return false;
		}

		_switchWrite(level, s);
		return true;
	}

    template <class ...Args>
    bool write(Level level, const std::string& s, Args&& ...args)
    {
        std::string str = fmt::format(s, std::forward<Args>(args)...);
        return this->write(level, str);
    }


private:

	Log()
	{
		is_open = false;
		is_async = std::stoi(ConfigMgr::Inst()["Logger"]["Async"]);
		m_maxSize = std::stoi(ConfigMgr::Inst()["Logger"]["MaxSize"]);
		m_minLevel = static_cast<Level>(std::stoi(ConfigMgr::Inst()["Logger"]["Level"]));

		if (!std::stoi(ConfigMgr::Inst()["Logger"]["Open"])) return;

		auto type = m_maxSize = std::stoi(ConfigMgr::Inst()["Logger"]["Type"]);

		switch (type)
		{
		case 0: {
			initOut(m_minLevel);
			break;
		}
		case 1: {
			initBasic(ConfigMgr::Inst()["Logger"]["FileName"], m_minLevel);
			break;
		}
		case 2: {
			initRotating(
				ConfigMgr::Inst()["Logger"]["FileName"],
				m_minLevel,
				std::stoi(ConfigMgr::Inst()["Logger"]["MemorySize"]),
				std::stoi(ConfigMgr::Inst()["Logger"]["FileCnt"]));
			break;
		}
		case 3: {
			initDaily(
				ConfigMgr::Inst()["Logger"]["FileName"],
				m_minLevel,
				std::stoi(ConfigMgr::Inst()["Logger"]["Hour"]),
				std::stoi(ConfigMgr::Inst()["Logger"]["Minute"]),
				std::stoi(ConfigMgr::Inst()["Logger"]["FileCnt"]));
			break;
		}
		default:
			break;
		}
	}

	void _switchWrite(Level level, const std::string& str)
	{
		assert(m_log != nullptr);
		m_log->log(level, str);
	}

private:

    int m_maxSize;
    Level m_minLevel;
    bool is_open;
    bool is_async;
    std::shared_ptr<spdlog::logger> m_log;
};


#define LOG_DEBUG(...) Log::getInstance()->write(Log::Level::debug, ##__VA_ARGS__)
#define LOG_INFO(...) Log::getInstance()->write(Log::Level::info, ##__VA_ARGS__)
#define LOG_WARN(...) Log::getInstance()->write(Log::Level::warn, ##__VA_ARGS__)
#define LOG_ERR(...) Log::getInstance()->write(Log::Level::err, ##__VA_ARGS__)


#endif // !UTILS_LOGER_H
