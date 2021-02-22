#include "ServerSocket.h"

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <strings.h>

#include "Logger.h"

int ServerSocket::Run(std::string ip, int port)
{
    listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        log->error("socket error");
        return -1;
    }

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    inet_pton(AF_INET, ip.c_str(), &address.sin_addr);
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
    if (ret < 0) {
        printf("bind error\n");
        return -1;
    }

    Demultiplexer* d = new EpollDemultiplexer();
    ret = d->Init();
    if (ret < 0 ) {
        log->error("demultiplexer init failed");
        return -1;
    }
    
    reactor = new Reactor(d);

    EventHandler* evhd = new ListenHandler(listenfd, reactor);
    reactor->RegiterEvHandler(listenfd, evhd);

    ret = listen(listenfd, 5);
    if (ret < 0) {
        printf("listen failed\n");
        return -1;
    }

    log->info("reactor start run");
    reactor->Dispatch();    
    return 0;
}