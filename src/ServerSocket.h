#ifndef __SERVERSOCKET_H__
#define __SERVERSOCKET_H__

#include <string>

#include "Reactor.h"

class ServerSocket
{
public:
    int Run(std::string ip, int port);

private:
    std::string ip;
    int port;
    int listenfd;
    Reactor* reactor;
};

#endif // __SERVERSOCKET_H__