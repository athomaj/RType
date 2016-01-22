//
//  AClient.cpp
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "AClient.hpp"

AClient::AClient(int const sockType, int const protoType, ISocket *fd, clientType clientType) :
_sockType(sockType), _protoType(protoType), _fd(fd), _clientType(clientType), _win(NULL), _mutex(new Mutex())
{
    _mutex->init();
}

#ifdef _WIN32
void AClient::close(socketType const fd)
{
    closesocket(fd);
}
#else
void AClient::close(socketType const fd)
{
    ::close(fd);
}
#endif

char* serialize(std::string data)
{
    return (const_cast<char *>(data.c_str()));
}

ISocket* AClient::getSocket()
{
    return (_fd);
}

void AClient::setMenuWindow(MenuWindow *win)
{
    _win = win;
}

void AClient::run(std::string const& ip, int const port)
{
    _sIn.sin_family = AF_INET;
    _sIn.sin_port = htons(port);
    _sIn.sin_addr.s_addr = inet_addr(ip.c_str());
    socket();
    if (_clientType == TCP)
        connect();

    while (42)
    {
        resetFds();
        setFds();
        select();
        checkFds();
    }
}

void AClient::socket()
{
    std::cout << "socket" << std::endl;
    if ((_fd->getFd() = ::socket(AF_INET, _sockType, _protoType)) == -1)
    {
        perror("socket()");
        throw ("server socket init failed\n");
    }
    maxFd = _fd->getFd();
}

void AClient::connect()
{
    if (::connect(_fd->getFd(), reinterpret_cast<const struct sockaddr *>(&_sIn),
                  sizeof(struct sockaddr_in)) < 0)
    {
        std::cout << "connect failed" << std::endl;
        throw std::runtime_error("connec failed");
    }
}

void AClient::select()
{
    struct timeval timeout;
    
    timeout.tv_sec = 0;
    timeout.tv_usec = 100;
    if (::select(maxFd + 1, &fdRead, &fdWrite, NULL, &timeout) == -1)
        throw ("select failed\n");
//    _win->setConnected(true);
}

void AClient::resetFds()
{
    FD_ZERO(&fdRead);
    FD_ZERO(&fdWrite);
}

IMutex* AClient::getMutex()
{
    return (_mutex);
}

