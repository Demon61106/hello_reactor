#ifndef __REACTOR_H__
#define __REACTOR_H__

#include <map>

#include "Demultiplexer.h"

class Reactor
{
public:
    Reactor(Demultiplexer* demultiplexer) {
        this->demultiplexer = demultiplexer;
    }
    int RegiterEvHandler(Handle hd, EventHandler* evHdr);
    int UnregiterEvHandler(Handle hd);
    int Dispatch();
private:
    std::map<Handle, EventHandler*> hd2EvHdr;
    Demultiplexer* demultiplexer;
};

#endif // __REACTOR_H__