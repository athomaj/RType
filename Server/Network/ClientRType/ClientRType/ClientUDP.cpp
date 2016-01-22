//
//  ClientUDP.cpp
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ClientUDP.hpp"

ClientUDP::ClientUDP() :
    AClient(SOCK_DGRAM, IPPROTO_UDP, new UDPSocket(0, "", 0), UDP)
{

}

ClientUDP::ClientUDP(std::string const& ip, int const port) :
AClient(SOCK_DGRAM, IPPROTO_UDP, new UDPSocket(0, ip, port), UDP)
{
    
}

void ClientUDP::checkFds()
{
    if (FD_ISSET(_fd->getFd(), &fdRead))
    {
        _mutex->lock();
        _fd->readData();
        _mutex->unlock();
    }
    if (FD_ISSET(_fd->getFd(), &fdWrite))
    {
        _mutex->lock();
        _fd->writeData();
        _mutex->unlock();
    }
}

void ClientUDP::setFds()
{
    FD_SET(_fd->getFd(), &fdRead);
    if (_fd->dataToWrite())
        FD_SET(_fd->getFd(), &fdWrite);
}