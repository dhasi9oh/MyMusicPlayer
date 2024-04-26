#pragma once

#include <mutex>
#include <memory>

template <typename T>
class Singleton {
public:

    static std::shared_ptr<T> GetInstance() {
        static std::once_flag s_flag;
        std::call_once(s_flag, [&]() {
            m_instance = std::shared_ptr<T>(new T);
            });
        return m_instance;
    }

    ~Singleton() {}

protected:

    Singleton()                                     = default;
    Singleton(const Singleton<T>&)                  = delete;
    Singleton& operator=(const Singleton<T>& st)    = delete;

protected:

    static std::shared_ptr<T> m_instance;
};


template <typename T>
std::shared_ptr<T> Singleton<T>::m_instance = nullptr;


