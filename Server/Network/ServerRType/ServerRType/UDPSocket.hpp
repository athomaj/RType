//
//  UDPSocket.hpp
//  ServerRType
//
//  Created by Julien Athomas on 03/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef UDPSocket_hpp
#define UDPSocket_hpp

#include <sys/types.h>
#ifndef _WIN32
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#endif
#include "ASocket.hpp"

class UDPSocket : public ASocket
{
public:
    UDPSocket(socketType const socket=0, std::string const& ip="", int const port=0);
    virtual int readData();
    virtual void writeData();
    void addClientData(struct sockaddr_in*);
};

#endif /* UDPSocket_hpp */
