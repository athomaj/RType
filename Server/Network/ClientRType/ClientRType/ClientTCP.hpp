//
//  ClientTCP.hpp
//  ClientRType
//
//  Created by Julien Athomas on 12/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ClientTCP_hpp
#define ClientTCP_hpp

#include "AClient.hpp"

class ClientTCP : public AClient
{
public:
    ClientTCP();
private:
    virtual void checkFds();
    virtual void setFds();
};

#endif /* ClientTCP_hpp */
