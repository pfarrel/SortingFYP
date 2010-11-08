#ifndef TIMER_H
#define TIMER_H
#define CLOCK_SPEED 2.666666666d

class timer
{
    long int startTime;
public:
    timer();
    void reset();
    long int elapsedTicks();
	long int elapsedSeconds();
};
#endif
