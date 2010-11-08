#include "timer.h"
timer::timer()
{
    //startTime = __rdtsc();
    return;
}

void timer::reset()
{
    unsigned long lo,hi;
    __asm__ __volatile__("xorl %%eax,%%eax\n\
    cpuid\n\
    rdtsc" : "=a" (lo), "=d" (hi) : : "ebx", "ecx" );
    startTime = ((unsigned long long)lo) + (unsigned long long)(hi<<32ULL);
}

long int timer::elapsedTicks()
{
    long int endTime;
    unsigned long lo,hi;
    __asm__ __volatile__("xorl %%eax,%%eax\n\
    cpuid\n\
    rdtsc" : "=a" (lo), "=d" (hi) : : "ebx", "ecx" );
    endTime = ((unsigned long long)lo) + (unsigned long long)(hi<<32ULL);
    return  endTime - startTime;
}

long int timer::elapsedSeconds()
{
	long int ticks = (double)this->elapsedTicks();
	return ticks / 2666666666L;
}
