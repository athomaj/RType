//
//  ManageClient.cpp
//  ServerRType
//
//  Created by Julien Athomas on 09/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

# include <string>
# include <iostream>
# include <sstream>
#include "GameManager.hpp"

char *serialize(std::string data)
{
    return (const_cast<char *>(data.c_str()));
}

GameManager::GameManager(IServer* serv) :
    _serv(serv), _actionManager(this), _playerByRoom(4)
{
#ifdef _WIN32
	_mutex = new MutexWin();
#else
	_mutex = new Mutex();
#endif
    _mutex->init();
    _ports[4545] = false;
    _ports[4546] = false;
    _ports[4547] = false;
    _ports[4548] = false;
    _ports[4549] = false;
    _ports[4550] = false;
    _ports[4551] = false;
    _ports[4552] = false;
    _ports[4553] = false;
    _ports[4554] = false;
}

void GameManager::checkDeadClients()
{
    auto clients = _serv->getClients();
    if (_serv->getMutex())
        _serv->getMutex()->lock();
    std::vector<std::vector<ISocket*>::iterator> toErase;
    for (unsigned int i=0; i<_rooms.size(); ++i)
    {
        std::vector<ISocket*> players = _rooms[i]->getPlayers();
        for (auto it = players.begin(); it != players.end(); ++it)
            if (find(clients.begin(), clients.end(), *it) == clients.end())
                toErase.push_back(it);
        for (unsigned int i=0; i<toErase.size(); ++i)
            players.erase(toErase[i]);
        toErase.clear();
    }
    if (_serv->getMutex())
        _serv->getMutex()->unlock();
}

void GameManager::run()
{
    while (1)
    {
        auto action = _serv->getActions();
        if (action)
        {
            checkDeadClients();
            launchAction(*action);
        }
            auto it = _rooms.begin();
        while (it != _rooms.end())
        {
            if ((*it)->getNbPlayer() == (*it)->getMaxPlayer())
            {
                auto players = (*it)->getPlayers();
                std::string playerNames("");
                Packet packetRdy = Packet::build(READY, "");
                playerNames.append(players[0]->getName());
                playerNames += " ";
                for (unsigned int i=1; i<players.size(); ++i)
                {
                    reinterpret_cast<ASocket *>(players[i])->addData<Packet>(packetRdy, serPacket);
                    playerNames.append(players[i]->getName());
                    playerNames += " ";
                }
                Packet packet = Packet::build(DATAMAP, playerNames);
                reinterpret_cast<ASocket *>(players[0])->addData<Packet>(packet, serPacket);
                ++it;
            }
            else if ((*it)->getNbPlayer() == 0)
            {
                int port =(*it)->getPort();
                std::string roomName = (*it)->getName();
                it = removeRoom((*it)->getName());
                _pool.releaseThread(roomName);
                _ports[port] = false;
            }
            else
                ++it;
        }
        _serv->getCond()->wait();
    }
}

void GameManager::launchAction(std::pair<ISocket*, Packet*>& action)
{
    try
    {
        _actionManager.runAction(action);
    } catch (std::runtime_error const& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::string to_string(int value)
	{
		std::ostringstream s;
		s << value;
		return (s.str());
	}

void GameManager::addRoom(const std::string &roomName, int const roomSize, ISocket* player)
{
    int port;
    
    if ((port = getAvailablePort()) != -1)
    {
        auto it = _rooms.begin();
        
        while (it != _rooms.end())
        {
            (*it)->removePlayer(player);
            ++it;
        }
        _rooms.push_back(new Room(roomName, port, player, roomSize));
    }
}

std::vector<Room *>::iterator GameManager::removeRoom(const std::string &roomName)
{
    auto it = _rooms.begin();
    
    while (it != _rooms.end())
    {
        if ((*it)->getName() == roomName)
        {
//            _serv->close();
            setAvailablePort((*it)->getPort());
            it = _rooms.erase(it);
            break;
        }
        ++it;
    }
    return it;
}

void GameManager::removeFromRoom(std::string const& roomName, ISocket* player)
{
    auto it = _rooms.begin();
    
    while (it != _rooms.end())
    {
        if ((*it)->getName() == roomName)
        {
            (*it)->removePlayer(player);
            break;
        }
        ++it;
    }
}

void GameManager::addToRoom(std::string const& roomName, ISocket* player)
{

    auto it = _rooms.begin();
    
    while (it != _rooms.end())
    {
        (*it)->removePlayer(player);
        ++it;
    }
    it = _rooms.begin();
    while (it != _rooms.end())
    {
//        it->removePlayer(player);
        if ((*it)->getName() == roomName)
        {
            std::cout << "Adding Player" << std::endl;
            (*it)->addPlayer(player);
            break;
        }
        ++it;
    }
}

unsigned long GameManager::getRoomSize(std::string const& roomName) const
{
    return (_rooms.size());
}

int GameManager::getAvailablePort()
{
    auto it = _ports.begin();
    while (it != _ports.end())
    {
        if (it->second == false)
        {
            it->second = true;
            return (it->first);
        }
        ++it;
    }
    return (-1);
}

void GameManager::setAvailablePort(int const port)
{
    auto it = _ports.find(port);
    if (it != _ports.end())
        it->second = false;
}

void GameManager::launchGame(Room* room)
{
    try
    {
        auto pool = _pool.getAvailableThread();
        pool.second->setRoom(room);
        pool.second->getThreadCond()->signal();
        auto players = room->getPlayers();
        room->setStarted(true);
        std::cout << "laucnhing game with port " << room->getPort() << std::endl;
        for (unsigned int j=0; j<players.size(); ++j)
        {
            Packet packet = Packet::build(START, std::to_string(j) + " " + room->getMap() + " " + std::to_string(room->getPort()));
            reinterpret_cast<ASocket*>(players[j])->addData<Packet>(packet, &serPacket);
        }
        sendRooms();
#ifdef _WIN32
		Sleep(4000);
#else
		sleep(4);
#endif
        for (unsigned int j=0; j<players.size(); ++j)
        {
            Packet packet = Packet::build(ENDGAME, "");
            reinterpret_cast<ASocket*>(players[j])->addData<Packet>(packet, &serPacket);
        }
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void GameManager::sendRooms()
{
    std::vector<unsigned char> packToSer;
    for (unsigned int i=0; i<_rooms.size(); ++i)
    {
        if (!_rooms[i]->getStarted())
        {
            std::string roomName = _rooms[i]->getName();
            std::cout << roomName << " " << _rooms[i]->getStarted() << std::endl;
            packToSer.push_back(static_cast<unsigned char>(i));
            packToSer.push_back(static_cast<unsigned char>(_rooms[i]->getMaxPlayer()));
            packToSer.push_back(static_cast<unsigned char>(_rooms[i]->getNbPlayer()));
            for (unsigned int i=0; i<roomName.length(); ++i)
            {
                packToSer.push_back(static_cast<unsigned char>(roomName[i]));
            }
            packToSer.push_back('\n');
            Packet packet = Packet::build(ROOM, packToSer);
            _serv->broadcast(packet);
            packToSer.clear();
        }
    }
}

IServer* GameManager::getServ()
{
    return _serv;
}

std::vector<Room *>& GameManager::getRooms()
{
    return _rooms;
}


