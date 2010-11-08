#include "timer.h"
#include <cstdlib>

#ifdef linux

timer::timer()
{
    gettimeofday(&startTime, NULL);
    return;
}

float timer::elapsed()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec - startTime.tv_sec + (t.tv_usec - startTime.tv_usec) / 1.e6;
}

#endif


#ifdef WIN32

timer::timer()
{
	QueryPerformanceFrequency(&ticksPerSecond);
	QueryPerformanceCounter(&tick);
}

float timer::elapsed()
{
	LARGE_INTEGER last_tick;
	QueryPerformanceCounter(&last_tick);

	float res = ((float)last_tick.QuadPart - (float)tick.QuadPart) / ticksPerSecond.QuadPart;
	return res;
}

#endif
