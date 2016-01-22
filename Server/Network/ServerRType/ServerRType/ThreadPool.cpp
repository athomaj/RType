//
//  ThreadPool.cpp
//  ServerRType
//
//  Created by Julien Athomas on 10/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ThreadPool.hpp"

void* launchGameEngine(void *param)
{
    GameEngine* engine = reinterpret_cast<GameEngine *>(param);

    while (1)
    {
        engine->getThreadCond()->wait();
        std::cout << "endWait" << std::endl;
        engine->launch();
    }
    return (NULL);
}

ThreadPool::ThreadPool(int const nbThread)
{
    IThread *thread;
    for (unsigned int i=0; i < nbThread; ++i)
    {
#ifdef _WIN32
		thread = new ThreadWin();
#else
		thread = new Thread();
#endif
        GameEngine *engine = new GameEngine();
        thread->create(reinterpret_cast<void *>(&launchGameEngine), engine);
        _pool.push_back(std::pair<IThread*, GameEngine *>(thread, engine));
    }
}

ThreadPool::~ThreadPool()
{
    for (unsigned int i=0; i<_pool.size(); ++i)
    {
        delete(_pool[i].first);
        delete(_pool[i].second);
    }
    _pool.clear();
}

std::pair<IThread *, GameEngine *>& ThreadPool::getAvailableThread()
{
    for (unsigned int i=0; i<_pool.size(); ++i)
    {
        if (_pool[i].second->getThreadCond()->getWaiting() == true)
            return (_pool[i]);
    }
    throw std::runtime_error("No threads available");
    return (_pool[0]);
}

void ThreadPool::releaseThread(std::string const& roomName)
{
    for (unsigned int i=0; i<_pool.size(); ++i)
    {
        if (_pool[i].second->getRoom() && _pool[i].second->getRoom()->getName() == roomName)
        {
//            _pool[i].first->stop();
            delete (_pool[i].first);
            _pool[i].second->getServer()->closeOwnFd();
            auto mutex = _pool[i].second->getServer()->getMutex();
            mutex->lock();
            _pool[i].second->setServerUdp(NULL);
            mutex->unlock();
#ifdef _WIN32
			_pool[i].first = new ThreadWin();
#else
			_pool[i].first = new Thread();
#endif
            _pool[i].second = new GameEngine();
            _pool[i].first->create(reinterpret_cast<void *>(&launchGameEngine), _pool[i].second);
            return ;
        }
    }
}
