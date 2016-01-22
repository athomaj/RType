#pragma once

#include "../IMutex.h"

#ifdef _WIN32

class MutexWin : public IMutex
{
public:
	MutexWin();
	virtual void init();
	virtual void destroy();
	virtual void lock();
	virtual bool trylock();
	virtual void unlock();
	virtual CRITICAL_SECTION& getMutex();
private:
	CRITICAL_SECTION _mutex;
};

#endif