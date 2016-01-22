//
//  ServerTCP.cpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ServerTCP.hpp"

ServerTCP::ServerTCP() :
    AServer(SOCK_STREAM, IPPROTO_IP, new TCPSocket(), TCP)
{
}

char *unserialize(const char *data)
{
    return (const_cast<char *>(data));
}

void ServerTCP::checkFds()
{
    std::vector<std::vector<ISocket *>::iterator> toDel;
//    int noInc = 1;
//    auto it = clients.begin();
//    
//    while (it != clients.end())
//    {
//        if (FD_ISSET((*it)->getFd(), &fdRead))
//        {
//            if ((*it)->readData() == -1)
//            {
//                auto& rooms = _gameManager->getRooms();
//                
//                for (unsigned int j=0; j<rooms.size(); ++j)
//                {
//                    std::vector<ISocket*>& players = rooms[j].getPlayers();
//                    for (auto it2 = players.begin(); it2 != players.end(); ++it2)
//                    {
//                        if (*it2 == *it)
//                        {
//                            pthread_cond_signal(&_cond);
//                            players.erase(it2);
//                            break ;
//                        }
//                    }
//                }
//                close((*it)->getFd());
//                it = clients.erase(it);
//            }
//            else
//            {
//                try
//                {
//                    Packet* action = reinterpret_cast<ASocket*>(*it)->getData<Packet*>(&unserPacket);
//                    actions.push_back(std::pair<ISocket*, Packet*>(*it, action));
//                    pthread_cond_signal(&_cond);
//                }
//                catch (std::runtime_error const& err)
//                {
//                }
//                ++it;
//            }
//            noInc = 0;
//        }
//        if (it != clients.end() && FD_ISSET((*it)->getFd(), &fdWrite))
//        {
//            (*it)->writeData();
//            ++it;
//            noInc = 0;
//        }
//        if (noInc)
//            ++it;
//        noInc = 1;
//    }
//    if (FD_ISSET(_fd->getFd(), &fdRead))
//        addClient();

    for (std::vector<ISocket *>::iterator it=clients.begin(); it != clients.end(); ++it)
    {
        if (FD_ISSET((*it)->getFd(), &fdRead))
        {
            if ((*it)->readData() == -1)
                toDel.push_back(it);
            try
            {
                Packet* action = reinterpret_cast<ASocket*>(*it)->getData<Packet*>(&unserPacket);
                actions.push_back(std::pair<ISocket*, Packet*>(*it, action));
                _cond->signal();
//                pthread_cond_signal(&_cond);
            }
            catch (std::runtime_error const& err)
            {
            }
        }
        if (FD_ISSET((*it)->getFd(), &fdWrite))
            (*it)->writeData();
    }
    if (FD_ISSET(_fd->getFd(), &fdRead))
        addClient();
    for (unsigned int i=0; i<toDel.size(); ++i)
    {
        auto& rooms = _gameManager->getRooms();

        for (unsigned int j=0; j<rooms.size(); ++j)
        {
            std::vector<ISocket*>& players = rooms[j]->getPlayers();
            for (auto it = players.begin(); it != players.end(); ++it)
            {
                if (*it == *toDel[i])
                {
                    _cond->signal();
//                    pthread_cond_signal(&_cond);
                    players.erase(it);
                    break ;
                }
            }
        }
        close((*toDel[i])->getFd());
        clients.erase(toDel[i]);
    }
}

void ServerTCP::setFds()
{
    if (_mutex)
        _mutex->lock();
    FD_SET(_fd->getFd(), &fdRead);
    for (unsigned int i=0; i < clients.size(); ++i)
    {
//        std::cout << "FD:" <<clients[i]->getFd() << " Name:" << clients[i]->getName() << std::endl;
        FD_SET(clients[i]->getFd(), &fdRead);
        if (clients[i]->dataToWrite())
            FD_SET(clients[i]->getFd(), &fdWrite);
    }
    if (_mutex)
        _mutex->unlock();
}