//
//  AServer.hpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef AServer_hpp
#define AServer_hpp

#include "IServer.h"
#include "Packet.hpp"
#include "MutexWin.h"
#include "ThreadCond.hpp"

class AServer : public IServer
{
public:
    AServer(int const, int const, ISocket *, servType);
    virtual void run(int const);
    virtual void initMutex();
    virtual std::pair<ISocket*, Packet *>* getActions();
    virtual IThreadCond* getCond();
    virtual void broadcast(Packet&);
    virtual std::vector<ISocket *>& getClients();
    virtual IMutex* getMutex();
    virtual void close(socketType const);
    virtual void setGameManager(IGameManager*);
    virtual Packet* getUdpAction();
    virtual void closeOwnFd();
    virtual void setGameEngine(GameEngine *);
protected:
    virtual void socket();
    virtual void bind();
    virtual void listen(int const nbClient=50);
    virtual void select();
    virtual int accept();
    virtual void addClient();
    virtual void checkFds() = 0;
    virtual void resetFds();
    virtual void setFds() = 0;
protected:
    ISocket               *_fd;
    struct protoent       *_pe;
    struct sockaddr_in    _sIn;
    fd_set                fdRead;
    fd_set                fdWrite;
    int                   _protoType;
    int                   _sockType;
    servType              _serverType;
    int                   maxFd;
    std::vector<ISocket *>     clients;
    IMutex                  *_mutex;
//    std::vector<std::string> actions;
    std::vector< std::pair<ISocket*, Packet*> > actions;
    IThreadCond              *_cond;
    IGameManager             *_gameManager;
    std::vector<Packet *>    _udpActions;
    GameEngine*               _gameEngine;
};

#include "GameEngine.hh"


#endif /* AServer_hpp */
