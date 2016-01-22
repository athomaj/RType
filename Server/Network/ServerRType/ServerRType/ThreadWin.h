#pragma once
#include "IThread.h"

#ifdef _WIN32
#include <windows.h>

class ThreadWin : public IThread
{
public:
	ThreadWin();
	virtual ~ThreadWin();
	virtual void create(void*, void*);
	virtual void join();
	virtual void exit();
	virtual void stop();
private:
	HANDLE _thread;
};

#endif