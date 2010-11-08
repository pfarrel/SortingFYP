
#ifdef linux

#include <sys/time.h>

class timer
{
    struct timeval startTime;
public:
    timer();
    float elapsed();
};

#endif

#ifdef WIN32
#include <windows.h>

class timer
{

	LARGE_INTEGER ticksPerSecond;
	LARGE_INTEGER tick;
public:
	timer();
	float elapsed();
};

#endif