//
//  AClient.hpp
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef AClient_hpp
#define AClient_hpp

#include "IClient.h"

class AClient : public IClient
{
public:
    AClient(int const, int const, ISocket *, clientType);
    virtual void run(std::string const&, int const);
    virtual void setMenuWindow(MenuWindow*);
    virtual ISocket* getSocket();
    virtual IMutex* getMutex();
    //    virtual void initMutex() = 0;
    //    virtual std::pair<ISocket*, std::string>* getActions() = 0;
    //    virtual pthread_cond_t& getCond() = 0;
    //    virtual void broadcast(std::string const&) = 0;
protected:
    virtual void socket();
    virtual void connect();
    virtual void select();
    virtual void checkFds() = 0;
    virtual void resetFds();
    virtual void setFds() = 0;
    virtual void close(socketType const);
protected:
    ISocket               *_fd;
    struct protoent       *_pe;
    struct sockaddr_in    _sIn;
    fd_set                fdRead;
    fd_set                fdWrite;
    int                   _protoType;
    int                   _sockType;
    clientType              _clientType;
    int                   maxFd;
    MenuWindow*           _win;
    IMutex*                _mutex;
};

#endif /* AClient_hpp */
