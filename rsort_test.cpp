#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include "sse.h"
#include "sortingnetwork.h"
#include "insertion.h"
#include "timer.h"
//#include "rsort/rsort_u.h"
//#include "rsort/rsort_us.h"
#include "rsort/rsort_a.h"
//#include "rsort/rsort_as.h"
#include "sortingnetworkSSE.h"
#include "sortingnetwork.h"

int main()
{
	double sseTime, otherTime;
	float* data = (float*)malloc(sizeof(float*) * 52 * 1024 * 1024);
    float* data2 = (float*)malloc(sizeof(float*) * 52 * 1024 * 1024);
	float* keys =  (float*) malloc(sizeof(float) * 52 * 1024 * 1024);    

    srand(time(NULL));
    for (int i=0; i<52*1024*1024; i++)
    {
        keys[i] = (float) rand();
    }

    memcpy(data,keys,sizeof(float) * 52 * 1024 * 1024);
    memcpy(data2, keys, sizeof(float) * 52 * 1024 * 1024);
    free(keys);

    timer t1;
    float* curr = data;
	for (int i = 0; i <1024*1024; i++)
    {
        //fastestnetwork(curr, curr + 32);
        //std::sort(curr, curr+32);
        rsort_a(curr,8);
        curr += 32;
    }
    long int time1 = t1.elapsedTicks();
    printf("\nSSE: %lu\n",time1);

    timer t2;
    curr = data2;
    for (int i = 0; i < 1024*1024; i++)
    {
        fastestnetworkSSE(curr, curr + 32);
        curr += 32;
    }
    long int time2 = t2.elapsedTicks();

    printf("Scalar: %lu\n",time2);
    printf("Factor: %lf\n", (double)time2/(double)time1);	
    //boseNelson32inRegister(data[0]);
    printf("After:\n");
	return 0;
}
