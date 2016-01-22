//
//  Room.hpp
//  ServerRType
//
//  Created by Julien Athomas on 09/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <vector>
#include <algorithm>
#include <iostream>
#include "ISocket.h"

class Room
{
public:
    Room();
    Room(std::string const& roomName, int const port, ISocket*, int const maxPlayer=4);
    void addPlayer(ISocket*);
    void removePlayer(ISocket*);
    unsigned long getNbPlayer() const;
    int getPort() const;
    std::string& getName();
    int getMaxPlayer() const;
    std::vector<ISocket *>& getPlayers();
    std::string& getMap();
    void setMap(std::string const&);
    bool getStarted() const;
    void setStarted(bool const);
    Room(std::string const& roomName, int const port, ISocket*);
    std::vector<ISocket *>&   getSavedPlayers();

    /**
	 * Défini le nom du niveau (ne pas mettre l'extention)
	 * 
	 * @param value Nom du niveau
	 */
	void			setLevelName(const std::string& value);
	const std::string&		getLevelName() const;
private:
    std::vector<ISocket *>    _savePlayers;
    std::vector<ISocket *>    _players;
    int                         _port;
    std::string                    _name;
    int                     _maxPlayer;
    std::string             _map;
    bool                    _started;
	std::string					levelname;
};

#endif /* Room_hpp */
