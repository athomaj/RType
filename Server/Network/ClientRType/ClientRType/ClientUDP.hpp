//
//  ClientUDP.hpp
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ClientUDP_hpp
#define ClientUDP_hpp

#include "AClient.hpp"

class ClientUDP : public AClient
{
public:
    ClientUDP();
    ClientUDP(std::string const&, int const);
private:
    virtual void checkFds();
    virtual void setFds();
};

#endif /* ClientUDP_hpp */
