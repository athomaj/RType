//
//  IMutex.h
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IMutex_h
#define IMutex_h

#ifdef _WIN32
#include <windows.h>
typedef CRITICAL_SECTION mutexType;
#else
#include <pthread.h>
typedef pthread_mutex_t mutexType;
#endif

class IMutex
{
public:
    virtual void init() = 0;
    virtual void destroy() = 0;
    virtual void lock() = 0;
    virtual bool trylock() = 0;
    virtual void unlock() = 0;
    virtual mutexType& getMutex() = 0;
};

#endif /* IMutex_h */
