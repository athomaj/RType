//
//  Thread.cpp
//  ServerRType
//
//  Created by Julien Athomas on 03/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "Thread.hpp"

#ifndef _WIN32

Thread::Thread()
{
}

Thread::~Thread()
{
}

void Thread::create(void *func, void*param)
{
    pthread_create(&_thread, NULL, reinterpret_cast<void* (*)(void *)>(func), param);
}

void Thread::join()
{
    pthread_join(_thread, NULL);
}

void Thread::stop()
{
    pthread_cancel(_thread);
}

void Thread::exit()
{
    pthread_exit(NULL);
}

#endif