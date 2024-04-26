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

class Log
{
public:

	using Level = spdlog::level::level_enum;

	//using FileEven = spdlog::file_event_handlers;

public:

	static Log* getInstance()
	{
		static Log log;
		return &log;
	}

public:

	~Log()
	{
		is_Open.store(false);
	}

	bool async() const
	{
		return is_Async.load();
	}

	bool open() const
	{
		return is_Open.load();
	}

	Level getLevel() const
	{
		return m_MinLevel;
	}

	void initOut(Level level = Level::err)
	{
		if (is_Async.load()) {
			spdlog::init_thread_pool(m_MaxSize, 1);
			m_Log = spdlog::stdout_color_mt<spdlog::async_factory>("m_Out");
		}
		else {
			m_Log = spdlog::stdout_color_mt("m_Out");
		}

		m_MinLevel = level;
		is_Open.store(true);
	}

	void  initBasic(std::string name = "log.txt", Level level = Level::err)
	{
		if (is_Async.load()) {
			spdlog::init_thread_pool(m_MaxSize, 1);
			m_Log = spdlog::basic_logger_mt<spdlog::async_factory>("m_AsyncBasic", name, true);
		}
		else {
			m_Log = spdlog::basic_logger_mt("m_Basic", name, true);
		}

		m_MinLevel = level;
		is_Open.store(true);
	}

	void initRotating(std::string name = "log.txt", Level level = Level::err
		, size_t memory_size = 50 * 1024 * 1024, size_t file_cnt = 10)
	{
		if (is_Async.load()) {
			spdlog::init_thread_pool(m_MaxSize, 1);
			m_Log = spdlog::rotating_logger_mt<spdlog::async_factory>("m_AsyncRotating", name, memory_size, file_cnt, true);
		}
		else {
			m_Log = spdlog::rotating_logger_mt("m_Rotating", name, memory_size, file_cnt, true);
		}

		m_MinLevel = level;
		is_Open.store(true);
	}

	void initDaily(std::string name = "log.txt", Level level = Level::err
		, int hour = 0, int min = 0, size_t file_cnt = 10)
	{
		if (is_Async.load()) {
			spdlog::init_thread_pool(m_MaxSize, 1);
			m_Log = spdlog::daily_logger_mt<spdlog::async_factory>("m_AsyncDaily", name, hour, min, true, file_cnt);
		}
		else {
			m_Log = spdlog::daily_logger_mt("m_Daily", name, hour, min, true, file_cnt);
		}

		m_MinLevel = level;
		is_Open.store(true);
	}

	void initMaxSize(int max_size)
	{
		m_MaxSize = max_size;
	}

	void setAsync()
	{
		is_Async.store(true);
	}

	void close()
	{
		is_Open.store(false);
	}

	/*void setFileEvent(FileEven event)
	{
		m_Event = event;
	}*/

	bool write(Level level, const std::string& s)
	{
		if (is_Open.load() == false) {
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
		m_MinLevel = Level::debug;
		is_Open.store(false);
		is_Async.store(false);
		m_MaxSize = 8192;
		m_Log = nullptr;
	}

	void _switchWrite(Level level, const std::string& str)
	{
		assert(m_Log != nullptr);

		switch (level) {
		case spdlog::level::err:
			m_Log->error(str.c_str());
			break;
		case spdlog::level::info:
			m_Log->info(str.c_str());
			break;
		case spdlog::level::warn:
			m_Log->warn(str.c_str());
			break;
		case spdlog::level::debug:
			m_Log->debug(str.c_str());
			break;
		case spdlog::level::trace:
			m_Log->trace(str.c_str());
			break;
		case spdlog::level::critical:
			m_Log->critical(str.c_str());
			break;
		default:
			m_Log->debug(str.c_str());
			break;
		}
	}

private:

    int m_MaxSize;

    Level m_MinLevel;

    //FileEven m_Event;

    std::atomic<bool> is_Open;

    std::atomic<bool> is_Async;

    std::shared_ptr<spdlog::logger> m_Log;
};


#define LOG_DEBUG(...) Log::getInstance()->write(Log::Level::debug, ##__VA_ARGS__)
#define LOG_INFO(...) Log::getInstance()->write(Log::Level::info, ##__VA_ARGS__)
#define LOG_WARN(...) Log::getInstance()->write(Log::Level::warn, ##__VA_ARGS__)
#define LOG_ERR(...) Log::getInstance()->write(Log::Level::err, ##__VA_ARGS__)


#endif // !UTILS_LOGER_H
