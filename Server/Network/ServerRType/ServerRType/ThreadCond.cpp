//
//  ThreadCond.cpp
//  ServerRType
//
//  Created by Julien Athomas on 10/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include <stdio.h>
#include "ThreadCond.hpp"

#ifndef _WIN32

ThreadCond::ThreadCond() :
    _mutex(new Mutex()), _waiting(false)
{
    _mutex->init();
}

void ThreadCond::init()
{
    pthread_cond_init(&_cond, NULL);
}

void ThreadCond::wait()
{
    _waiting = true;
    pthread_cond_wait(&_cond, &(_mutex->getMutex()));
}

void ThreadCond::signal()
{
    _waiting = false;
    pthread_cond_signal(&_cond);
}

bool ThreadCond::getWaiting() const
{
    return (_waiting);
}

#endif