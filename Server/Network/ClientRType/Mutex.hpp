//
//  Mutex.hpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef Mutex_hpp
#define Mutex_hpp

#include "IMutex.h"

class Mutex : public IMutex
{
public:
    Mutex();
    virtual void init();
    virtual void destroy();
    virtual void lock();
    virtual bool trylock();
    virtual void unlock();
    virtual pthread_mutex_t& getMutex();
private:
    pthread_mutex_t _mutex;
};


#endif /* Mutex_hpp */
