#pragma once

#ifdef _WIN32

#include "MutexWin.h"
#include "IThreadCond.h"

class ThreadCondWin : public IThreadCond
{
public:
	ThreadCondWin();
	virtual void init();
	virtual void wait();
	virtual void signal();
	virtual bool getWaiting() const;
private:
	CONDITION_VARIABLE _cond;
	IMutex* _mutex;
	bool _waiting;
};

#endif