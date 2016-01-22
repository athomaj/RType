//
//  TCPSocket.hpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef TCPSocket_hpp
#define TCPSocket_hpp

#include "ASocket.hpp"

class TCPSocket : public ASocket
{
public:
    TCPSocket(socketType const socket=0);
    virtual int readData();
    virtual void writeData();
};

#endif /* TCPSocket_hpp */
