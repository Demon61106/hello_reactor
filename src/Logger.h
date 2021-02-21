#ifndef __LOGGER_H__
#define __LOGGER_H__

class Logger
{
public:
    static Logger *Instance()
    {
        if (logger == nullptr)  // TODO lock
        {
            logger = new Logger();
        }
        return logger;
    }
    void debug(const char *buf, ...);
    void info(const char *buf, ...);
    void warn(const char *buf, ...);
    void error(const char *buf, ...);

private:
    Logger(){};
    Logger(Logger &)=delete;
    Logger &operator=(const Logger &)=delete;
    static Logger *logger;
};

#define log Logger::Instance()

#endif // __LOGGER_H__