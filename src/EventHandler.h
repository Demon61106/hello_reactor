#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

typedef int Handle;

class Reactor;

class EventHandler
{
public:
    EventHandler(Handle hd):hd(hd) {}
    virtual int Read() = 0;
    virtual int Write() = 0;
    virtual int Error() = 0;

protected:
    Handle hd;    
};

class ListenHandler:public EventHandler
{
public:
    ListenHandler(Handle hd, Reactor* r):EventHandler(hd),reactor(r) {}
    int Read();
    int Write();
    int Error();
private:
    Reactor* reactor;
};

class SocketHandler:public EventHandler
{
public:
    SocketHandler(Handle hd):EventHandler(hd) {}
    int Read();
    int Write();
    int Error();
};

#endif // __EVENTHANDLER_H__
