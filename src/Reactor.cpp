#include "Reactor.h"

#include <string>

int Reactor::RegiterEvHandler(Handle hd, EventHandler* evHdr) {
    this->hd2EvHdr.insert(std::map<Handle, EventHandler*>::value_type(hd, evHdr));
    this->demultiplexer->Add(hd);
    return 0;
}

int Reactor::UnregiterEvHandler(Handle hd) {
    this->demultiplexer->Remove(hd);
    this->hd2EvHdr.erase(hd);
    return 0;
}

int Reactor::Dispatch() 
{
    while (true) {
        int ret = this->demultiplexer->Dispath(this->hd2EvHdr);
        if (ret < 0) {
            return -1;
        }
    }    
    return 0;
}