#include "EventHandler.h"

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "Logger.h"
#include "Reactor.h"

int ListenHandler::Read()
{
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int connfd = accept(hd, (struct sockaddr*)&addr, &addrlen);
    char clientAddr[INET_ADDRSTRLEN];
    log->info("accept success. client is %s:%d\n", inet_ntop(AF_INET, &addr.sin_addr, clientAddr, INET_ADDRSTRLEN), ntohs(addr.sin_port));
    EventHandler* evhd = new SocketHandler(connfd);
    this->reactor->RegiterEvHandler(connfd, evhd);
    return 0;
}

int ListenHandler::Write()
{
    return 0;
}

int ListenHandler::Error()
{
    return 0;
}

int SocketHandler::Read()
{
    return 0;
}

int SocketHandler::Write()
{
    return 0;
}

int SocketHandler::Error()
{
    return 0;
}