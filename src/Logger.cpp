#include "Logger.h"

#include <cstdio>
#include <cstdarg>
#include <cstdlib>

Logger *Logger::logger = nullptr;

void Logger::debug(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    fflush( stdout );
    va_end(vaList);
    return ;
}

void Logger::info(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    fflush( stdout );
    va_end(vaList);
    return ;
}

void Logger::warn(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    fflush( stdout );
    va_end(vaList);
    return ;
}

void Logger::error(const char *format, ...)
{
    va_list vaList;
    va_start(vaList, format);
    vfprintf(stdout, format, vaList);
    fflush( stdout );
    va_end(vaList);
    return ;
}
