//
//  Room.cpp
//  ServerRType
//
//  Created by Julien Athomas on 09/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "Room.hpp"

Room::Room()
{
}

Room::Room(std::string const& roomName, int const port, ISocket* host, int const maxPlayer) :
    _name(roomName), _port(port), _maxPlayer(maxPlayer), _map(""), _started(false)
{
    host->resetScore();
    _players.push_back(host);
}

std::string& Room::getMap()
{
    return (_map);
}

void Room::setMap(std::string const& map)
{
    _map = map;
}

void Room::addPlayer(ISocket* player)
{
    player->resetScore();
    _players.push_back(player);
}

void Room::removePlayer(ISocket* player)
{
    auto it = std::find(_players.begin(), _players.end(), player);
    if (it != _players.end())
        _players.erase(it);
}

std::vector<ISocket *>& Room::getPlayers()
{
    return (_players);
}


unsigned long Room::getNbPlayer() const
{
    return (_players.size());
}

int Room::getPort() const
{
    return (_port);
}

std::string& Room::getName()
{
    return (_name);
}

int Room::getMaxPlayer() const
{
    return _maxPlayer;
}

bool Room::getStarted() const
{
    return _started;
}

void Room::setStarted(bool const started)
{
    for (unsigned int i=0; i<_players.size(); ++i)
        _savePlayers.push_back(_players[i]);
    _started = started;
}
void Room::setLevelName(const std::string& value)
{
	this->levelname = value;
}

const std::string& Room::getLevelName() const
{
	return (this->levelname);
}

std::vector<ISocket *>&   Room::getSavedPlayers()
{
    return _savePlayers;
}
