#include "Logger.h"

#include <cstdio>
#include <cstdarg>

Logger *Logger::logger = nullptr;

void Logger::debug(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    va_end(vaList);
    return ;
}

void Logger::info(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    va_end(vaList);
    return ;
}

void Logger::warn(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    va_end(vaList);
    return ;
}

void Logger::error(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    va_end(vaList);
    return ;
}
