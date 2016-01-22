//
//  Mutex.cpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "Mutex.hpp"

Mutex::Mutex()
{
}

void Mutex::init()
{
    pthread_mutex_init(&_mutex, NULL);
}

void Mutex::destroy()
{
    pthread_mutex_destroy(&_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&_mutex);
}

bool Mutex::trylock()
{
    if (pthread_mutex_trylock(&_mutex) == 0)
        return false;
    return true;
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&_mutex);
}

pthread_mutex_t& Mutex::getMutex()
{
    return (_mutex);
}
