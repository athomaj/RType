//
//  IServer.h
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IServer_h
#define IServer_h

#include <vector>
#include <iostream>
#include "Mutex.hpp"
#include "TCPSocket.hpp"
#include "UDPSocket.hpp"
#include "Packet.hpp"
#include "IGameManager.h"
#include "IThreadCond.h"

/*#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#endif*/

#ifdef _WIN32
#pragma comment(lib, "Ws2_32.lib")
#endif

enum servType
{
    TCP,
    UDP
};

class IGameManager;
class GameEngine;

class IServer
{
public:
    virtual void run(int const) = 0;
    virtual void initMutex() = 0;
    virtual std::pair<ISocket*, Packet*>* getActions() = 0;
    virtual IThreadCond* getCond() = 0;
    virtual void broadcast(Packet&) = 0;
    virtual std::vector<ISocket *>& getClients() = 0;
    virtual IMutex* getMutex() = 0;
    virtual void close(socketType const) = 0;
    virtual void setGameManager(IGameManager*) = 0;
    virtual Packet* getUdpAction() = 0;
    virtual void closeOwnFd() = 0;
    virtual void setGameEngine(GameEngine *) = 0;
protected:
    virtual void socket() = 0;
    virtual void bind() = 0;
    virtual void listen(int const nbClient=50) = 0;
    virtual void select() = 0;
    virtual int accept() = 0;
    virtual void addClient() = 0;
    virtual void checkFds() = 0;
    virtual void resetFds() = 0;
    virtual void setFds() = 0;
};

#endif /* IServer_h */
