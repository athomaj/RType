//
//  Thread.hpp
//  ServerRType
//
//  Created by Julien Athomas on 03/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef Thread_hpp
#define Thread_hpp

#ifndef _WIN32
#include "IThread.h"
#include <pthread.h>

class Thread : public IThread
{
public:
    Thread();
    virtual ~Thread();
    virtual void create(void*, void*);
    virtual void join();
    virtual void exit();
    virtual void stop();

private:
    pthread_t _thread;
};

#endif
#endif /* Thread_hpp */
