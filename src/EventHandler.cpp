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

#define BUFFER_SIZE 1024

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
    log->info("start to read\n");
    char buf[BUFFER_SIZE];
    memset(buf, '\0', BUFFER_SIZE);
    int ret = recv(hd, buf, BUFFER_SIZE-1, 0);
    if (ret <= 0) {
        close(hd);
        log->info("socket error");
        return -1;
    }
    log->info("get %d bytes of content: %s\n", ret, buf);
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