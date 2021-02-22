#include "Demultiplexer.h"

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "Logger.h"

#define MAX_EVENT_NUMBER 1024

int EpollDemultiplexer::Init() 
{
    epollfd = epoll_create(1);
    if (epollfd < 0) {
        log->error("epoll_create error\n");
        return -1;
    }
    return 0;
}

int EpollDemultiplexer::Add(Handle hd)
{
    epoll_event event;
    event.data.fd = hd;
    event.events = EPOLLIN;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, hd, &event);
    return 0;
}

int EpollDemultiplexer::Remove(Handle hd)
{
    return 0;
}

int EpollDemultiplexer::Dispath(std::map<Handle, EventHandler*>& hd2EvHdr)
{
    epoll_event events[MAX_EVENT_NUMBER];
    int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
    if (ret < 0) {
        log->error("epoll wait error");
        return -1;
    }

    for (int i = 0; i < ret; ++i) {
        int fd = events[i].data.fd;
        EventHandler* handler = hd2EvHdr[fd];
        if (handler == nullptr) {
            log->error("handler is nullptr");
            continue;
        }
        if (events[i].events & EPOLLIN) {            
            ret = handler->Read();
        } else if (events[i].events & EPOLLOUT) {
            ret = handler->Write();
        }
        if (ret < 0) {
            return -1;
        }
    }
    return 0;
}