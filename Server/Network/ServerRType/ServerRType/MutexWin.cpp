#include "MutexWin.h"

#ifdef _WIN32

MutexWin::MutexWin()
{
}

void MutexWin::init()
{
	InitializeCriticalSection(&_mutex);
}

void MutexWin::destroy()
{
	DeleteCriticalSection(&_mutex);
}

void MutexWin::lock()
{
	EnterCriticalSection(&_mutex);
}

bool MutexWin::trylock()
{
	return true;
}

void MutexWin::unlock()
{
	LeaveCriticalSection(&_mutex);
}

CRITICAL_SECTION& MutexWin::getMutex()
{
	return _mutex;
}

#endif