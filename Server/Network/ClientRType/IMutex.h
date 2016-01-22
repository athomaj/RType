//
//  IMutex.h
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IMutex_h
#define IMutex_h

#include <pthread.h>

class IMutex
{
public:
    virtual void init() = 0;
    virtual void destroy() = 0;
    virtual void lock() = 0;
    virtual bool trylock() = 0;
    virtual void unlock() = 0;
    virtual pthread_mutex_t& getMutex() = 0;
};

#endif /* IMutex_h */
