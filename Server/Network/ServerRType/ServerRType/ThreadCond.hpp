//
//  ThreadCond.hpp
//  ServerRType
//
//  Created by Julien Athomas on 10/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ThreadCond_hpp
#define ThreadCond_hpp

#ifndef _WIN32

#include <pthread.h>
#include <iostream>
#include "Mutex.hpp"
#include "IThreadCond.h"

class ThreadCond : public IThreadCond
{
public:
    ThreadCond();
    virtual void init();
    virtual void wait();
    virtual void signal();
    virtual bool getWaiting() const;
private:
    pthread_cond_t _cond;
    IMutex* _mutex;
    bool _waiting;
};

#endif
#endif /* ThreadCond_hpp */
