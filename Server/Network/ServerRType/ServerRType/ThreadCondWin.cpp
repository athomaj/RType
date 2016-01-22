#include "ThreadCondWin.h"

#ifdef _WIN32

ThreadCondWin::ThreadCondWin() :
	_mutex(new MutexWin()), _waiting(false)
{
	_mutex->init();
}

void ThreadCondWin::init()
{
	InitializeConditionVariable(&_cond);
}

void ThreadCondWin::wait()
{
	_waiting = true;
	SleepConditionVariableCS(&_cond, &(_mutex->getMutex()), INFINITE);
}

void ThreadCondWin::signal()
{
	_waiting = false;
	WakeConditionVariable(&_cond);
}

bool ThreadCondWin::getWaiting() const
{
	return (_waiting);
}

#endif