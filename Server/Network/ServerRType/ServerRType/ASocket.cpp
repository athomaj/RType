//
//  ASocket.cpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ASocket.hpp"

ASocket::ASocket(socketType const socket) :
_socket(socket), _writable(false), _name("Unknown"), _score(0), _highScore(0)
{
    _data = (char *)malloc(128);
    memset(_data, 0, 128);
}

socketType& ASocket::getFd()
{
    return (_socket);
}

bool ASocket::dataToWrite()
{
    return (_wData.isDataLeft());
}

std::string& ASocket::getName()
{
    return (_name);
}

std::vector<struct sockaddr_in>& ASocket::getUdpClients()
{
    return _udpClients;
}

void ASocket::writeUdpData(struct sockaddr_in& si)
{
    std::vector<unsigned char> data;
    
    data = _wData.getData();
    unsigned char *buf = Packet::toBuf(data);
    ::sendto(_socket, reinterpret_cast<char *>(buf), data.size(), 0, reinterpret_cast<struct sockaddr *>(&si), sizeof(si));
    delete[] buf;
}

int ASocket::getScore() const
{
    return (_score);
}

void ASocket::incScore()
{
    ++_score;
}

void ASocket::resetScore()
{
    if (_score > _highScore)
        _highScore = _score;
    _score = 0;
}
