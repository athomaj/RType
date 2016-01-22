//
//  ServerUDP.hpp
//  ServerRType
//
//  Created by Julien Athomas on 03/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ServerUDP_hpp
#define ServerUDP_hpp

#include "AServer.hpp"

class ServerUDP : public AServer
{
public:
    ServerUDP();
    virtual void broadcast(Packet&);
private:
    virtual void checkFds();
    virtual void setFds();
};


#endif /* ServerUDP_hpp */
