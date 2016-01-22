//
//  ActionManager.cpp
//  ServerRType
//
//  Created by Julien Athomas on 09/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ActionManager.hpp"

char* resSer(std::string data)
{
    return (const_cast<char *>(data.c_str()));
}

ActionManager::ActionManager(IGameManager* gameManager) :
    _gameManager(gameManager)
{
    actions[1] = &ActionManager::setName;
    actions[2] = &ActionManager::roomList;
    actions[3] = &ActionManager::newRoom;
    actions[4] = &ActionManager::joinRoom;
    actions[5] = &ActionManager::leaveRoom;
    actions[6] = &ActionManager::play;
    actions[7] = &ActionManager::dataMap;
    actions[9] = &ActionManager::endGame;
}


void ActionManager::runAction(std::pair<ISocket*, Packet *>& action)
{
    int actionCode = action.second->getType();
    
    auto it = actions.find(actionCode);
    if (it == actions.end())
        throw std::runtime_error("Action does not exist");
    (this->*it->second)(action);
}

void ActionManager::dataMap(std::pair<ISocket*, Packet *>& action)
{
}


void ActionManager::endGame(std::pair<ISocket*, Packet *>& action)
{
    auto rooms = _gameManager->getRooms();
    
    for (unsigned int i=0; i<rooms.size(); ++i)
    {
        if (rooms[i]->getStarted())
        {
            auto players = rooms[i]->getPlayers();
            if (std::find(players.begin(), players.end(), action.first) != players.end())
            {
                auto& savedPlayer = rooms[i]->getSavedPlayers();
                std::stringstream ss;
                ss << savedPlayer.size() << " ";
                for (unsigned int j=0; j<savedPlayer.size(); ++j)
                    ss << savedPlayer[j]->getName() << " " << savedPlayer[j]->getScore() << " ";
                Packet packet = Packet::build(ENDGAME, ss.str());
                reinterpret_cast<ASocket*>(action.first)->addData<Packet>(packet, &serPacket);
                _gameManager->removeFromRoom(rooms[i]->getName(), action.first);
                break;
            }
        }
    }
}

void ActionManager::newRoom(std::pair<ISocket*, Packet *>& action)
{
    auto data = action.second->getData();
    unsigned char *data2 = Packet::toBuf(data);
    std::string roomName(reinterpret_cast<char *>(&data2[1]));
    std::cout << "adding room with name " << roomName << std::endl;
    _gameManager->addRoom(roomName, data2[0] - 48, action.first);
    roomList(action);
}

void ActionManager::joinRoom(std::pair<ISocket*, Packet *>& action)
{
    auto data = action.second->getData();
    unsigned char *data2 = Packet::toBuf(data);
    std::string tmp((char *)data2);
    std::cout << tmp.size()<< tmp << std::endl;
    _gameManager->addToRoom(tmp, action.first);
    roomList(action);
}
void ActionManager::leaveRoom(std::pair<ISocket*, Packet *>& action)
{
    auto data = action.second->getData();
//    for (unsigned int i=0;i<data.size(); ++i)
//    {
//        std::cout << "data: " << data[i] << std::endl;
//    }
    _gameManager->removeFromRoom("my first room", action.first);
    unsigned char *data2 = Packet::toBuf(data);
    std::string tmp((char *)data2);
    Packet packet = Packet::build(LEAVE, tmp);
    reinterpret_cast<ASocket*>(action.first)->addData<Packet>(packet, &serPacket);
    std::cout << "leaveRoom" << std::endl;
}
void ActionManager::roomList(std::pair<ISocket*, Packet *>& action)
{
    _gameManager->sendRooms();
    std::cout << "roomList" << std::endl;
}
void ActionManager::setName(std::pair<ISocket*, Packet *>& action)
{
    auto data = action.second->getData();
    unsigned char *data2 = Packet::toBuf(data);
    std::string userName((char *)data2);
    
    if (_gameManager->getServ()->getMutex())
        _gameManager->getServ()->getMutex()->lock();
    std::vector<ISocket *>& clients = _gameManager->getServ()->getClients();
    for (auto it=clients.begin(); it != clients.end(); ++it)
    {
        if (*it != action.first && (*it)->getName() == userName)
        {
            _gameManager->getServ()->close(action.first->getFd());
            clients.erase(remove(clients.begin(), clients.end(), action.first), clients.end());
            if (_gameManager->getServ()->getMutex())
                _gameManager->getServ()->getMutex()->unlock();
            return ;
        }
    }
    if (_gameManager->getServ()->getMutex())
        _gameManager->getServ()->getMutex()->unlock();
    Packet packet = Packet::build(CONNECT, userName);
    reinterpret_cast<ASocket*>(action.first)->addData<Packet>(packet, &serPacket);
    action.first->getName() = userName;
    std::cout << "setName" << std::endl;
}

void ActionManager::play(std::pair<ISocket*, Packet *>& action)
{
    std::vector<Room *>& rooms = _gameManager->getRooms();
    std::string tmp("");
    
    for (unsigned int i=0; i<rooms.size(); ++i)
    {
        auto players = rooms[i]->getPlayers();
        if (players.size() && players[0] == action.first)
        {
            auto data = action.second->getData();
            for (unsigned int i=0; i<data.size(); ++i)
                tmp += data[i];
            rooms[i]->setMap(tmp);
            _gameManager->launchGame(rooms[i]);
            return ;
        }
    }
    std::cout << "play" << std::endl;
}
