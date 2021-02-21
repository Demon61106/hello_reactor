#ifndef __DEMULTIPLEXER_H__
#define __DEMULTIPLEXER_H__

#include <map>

#include "EventHandler.h"

class Demultiplexer
{
public:
    virtual int Init() = 0;
    virtual int Add(Handle hd) = 0;
    virtual int Remove(Handle hd) = 0;
    virtual int Dispath(std::map<Handle, EventHandler*>& hd2EvHdr) = 0;
};

class EpollDemultiplexer : public Demultiplexer
{
public:
    int Init();
    int Add(Handle hd);
    int Remove(Handle hd);
    int Dispath(std::map<Handle, EventHandler*>& hd2EvHdr);
private:
    int epollfd;
};

#endif // __DEMULTIPLEXER_H__