//
//  IClient.h
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IClient_h
#define IClient_h

#include "IMutex.h"
#include "../../ServerRType/ServerRType/ISocket.h"

class MenuWindow;
class TCPSocket;
class UDPSocket;

enum clientType
{
    TCP,
    UDP
};

class IClient
{
public:
    virtual void run(std::string const&, int const) = 0;
    virtual void setMenuWindow(MenuWindow*) = 0;
    virtual ISocket* getSocket() = 0;
    virtual IMutex* getMutex() = 0;
//    virtual void initMutex() = 0;
//    virtual std::pair<ISocket*, std::string>* getActions() = 0;
//    virtual pthread_cond_t& getCond() = 0;
//    virtual void broadcast(std::string const&) = 0;
protected:
    virtual void socket() = 0;
    virtual void connect() = 0;
    virtual void select() = 0;
    virtual void checkFds() = 0;
    virtual void resetFds() = 0;
    virtual void setFds() = 0;
    virtual void close(socketType const) = 0;
};

#include "TCPSocket.hpp"
#include "UDPSocket.hpp"
#include "menuWindow.hh"

#endif /* IClient_h */
