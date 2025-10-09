
#pragma once

#include <spdlog/spdlog.h>

#define LOG_INSTANCE Log::GetInstance()

#define LOG_ENABLE 1

#ifdef LOG_ENABLE
    #define LOG_INFO(...) SPDLOG_INFO(__VA_ARGS__)
    #define LOG_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
    #define LOG_DEBUG(...) SPDLOG_DEBUG(__VA_ARGS__)
    #define LOG_WARN(...) SPDLOG_WARN(__VA_ARGS__)
    #define LOG_CRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)
#else
    #define LOG_INFO(...) (void)0
    #define LOG_ERROR(...) (void)0
    #define LOG_DEBUG(...) (void)0
    #define LOG_WARN(...) (void)0
    #define LOG_CRITICAL(...) (void)0
#endif



class Log
{
public:
    static Log& GetInstance();

    
private:
    Log();
    ~Log();

    void Init();
    void Shutdown();
};