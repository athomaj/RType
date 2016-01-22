#include "ThreadWin.h"

#ifdef _WIN32

ThreadWin::ThreadWin()
{
}

ThreadWin::~ThreadWin()
{
}

void ThreadWin::create(void* func, void* param)
{
	_thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(func), param, 0, NULL);
}

void ThreadWin::join()
{
	WaitForSingleObject(_thread, -1);
}

void ThreadWin::exit()
{
	CloseHandle(_thread);
}

void ThreadWin::stop()
{
	CloseHandle(_thread);
}

#endif
