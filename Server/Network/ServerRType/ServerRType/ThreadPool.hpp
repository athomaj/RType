//
//  ThreadPool.hpp
//  ServerRType
//
//  Created by Julien Athomas on 10/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ThreadPool_hpp
#define ThreadPool_hpp

#include <vector>
#include "Thread.hpp"
#include "GameEngine.hh"
//#include "GameEngine.hpp"

class ThreadPool
{
public:
    ThreadPool(int const nbThread=10);
    ~ThreadPool();
    std::pair<IThread *, GameEngine *>& getAvailableThread();
    void releaseThread(std::string const&);
private:
    std::vector< std::pair<IThread *, GameEngine *> > _pool;
};

#endif /* ThreadPool_hpp */
