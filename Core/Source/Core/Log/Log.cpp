
#include "Log.h"

#include <iostream>

Log::Log()
{
    Init();
}

Log::~Log()
{
    Shutdown();
}

void Log::Init()
{
    std::cout << "Log Init" << std::endl;
}

void Log::Shutdown()
{
    std::cout << "Log Shutdown" << std::endl;
}

Log& Log::GetInstance()
{
    static Log instance;
    return instance;
}
