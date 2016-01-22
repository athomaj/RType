//
//  ServerUDPUDP.cpp
//  ServerUDPRType
//
//  Created by Julien Athomas on 03/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ServerUDP.hpp"

ServerUDP::ServerUDP() :
    AServer(SOCK_DGRAM, IPPROTO_UDP, new UDPSocket(), UDP)
{
}

void ServerUDP::checkFds()
{
    if (FD_ISSET(_fd->getFd(), &fdRead))
    {
        _fd->readData();
        try
        {
            Packet* action = reinterpret_cast<ASocket*>(_fd)->getData<Packet*>(&unserPacket);
            _udpActions.push_back(action);
            if (_gameEngine)
                _gameEngine->getThreadCond()->signal();
        }
        catch (std::runtime_error const& err)
        {
        }
    }
}

void ServerUDP::broadcast(Packet& packet)
{
    auto clients = _fd->getUdpClients();
    
    for (unsigned int i=0; i<clients.size(); ++i)
    {
        reinterpret_cast<ASocket*>(_fd)->addData<Packet>(packet, &serPacket);
        _fd->writeUdpData(clients[i]);
    }
}

void ServerUDP::setFds()
{
    FD_SET(_fd->getFd(), &fdRead);
    FD_SET(_fd->getFd(), &fdWrite);
}
