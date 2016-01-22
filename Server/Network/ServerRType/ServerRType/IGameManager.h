//
//  IManageClient.h
//  ServerRType
//
//  Created by Julien Athomas on 09/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IManageClient_h
#define IManageClient_h

#include "IMutex.h"
#include "IServer.h"
#include "Room.hpp"

class IServer;

class IGameManager
{
public:
    virtual void run() = 0;
    virtual void addRoom(std::string const&, int const, ISocket*) = 0;
    virtual std::vector<Room *>::iterator removeRoom(std::string const&) = 0;
    virtual void removeFromRoom(std::string const& roomName, ISocket*) = 0;
    virtual void addToRoom(std::string const& roomName, ISocket*) = 0;
    virtual unsigned long getRoomSize(std::string const& roomName) const = 0;
    virtual int getAvailablePort() = 0;
    virtual void setAvailablePort(int const) = 0;
    virtual void sendRooms() = 0;
    virtual IServer* getServ() = 0;
    virtual void checkDeadClients() = 0;
    virtual std::vector<Room *>& getRooms() = 0;
    virtual void launchGame(Room *) = 0;

private:
    virtual void launchAction(std::pair<ISocket*, Packet*>&) = 0;
};

#include "IServer.h"


#endif /* IManageClient_h */
