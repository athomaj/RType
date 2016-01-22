//
//  ISocket.h
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ISocket_h
#define ISocket_h

#include <stdexcept>
#include <stdlib.h>
#include <string.h>
#ifndef _WIN32
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#endif
#include <sys/types.h>
#include "circular_buffer.hh"
#include "Packet.hpp"

#ifdef _WIN32
	#include <winsock.h>
    typedef SOCKET socketType;
#else
    typedef int socketType;
#endif

class ISocket
{
public:
    virtual socketType& getFd() = 0;
    virtual int readData() = 0;
    virtual void writeData() = 0;
    virtual void writeUdpData(struct sockaddr_in&) = 0;
    virtual bool dataToWrite() = 0;
    virtual std::string& getName() = 0;
    virtual std::vector<struct sockaddr_in>& getUdpClients() = 0;
    virtual int getScore() const = 0;
    virtual void incScore() = 0;
    virtual void resetScore() = 0;

};

#endif /* ISocket_h */
