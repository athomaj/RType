//
//  IThread.h
//  ServerRType
//
//  Created by Julien Athomas on 03/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IThread_h
#define IThread_h

#include "ServerTCP.hpp"
#include <iostream>

class IThread
{
public:
    virtual ~IThread() {};
    virtual void create(void*, void*) = 0;
    virtual void join() = 0;
    virtual void exit() = 0;
    virtual void stop() = 0;
};

#endif /* IThread_h */
