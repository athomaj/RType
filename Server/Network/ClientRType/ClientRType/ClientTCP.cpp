//
//  ClientTCP.cpp
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ClientTCP.hpp"

ClientTCP::ClientTCP() :
    AClient(SOCK_STREAM, IPPROTO_IP, new TCPSocket(), TCP)
{
    
}

void ClientTCP::checkFds()
{
    if (FD_ISSET(_fd->getFd(), &fdRead))
    {
        if (_fd->readData() == -1)
        {
            _win->currentPage = MenuWindow::CONNECTION;
            close(_fd->getFd());
            throw std::runtime_error("Server not available");
        }
    }
    if (FD_ISSET(_fd->getFd(), &fdWrite))
    {
        _fd->writeData();
    }
}

void ClientTCP::setFds()
{
    FD_SET(_fd->getFd(), &fdRead);
    if (_fd->dataToWrite())
        FD_SET(_fd->getFd(), &fdWrite);
}