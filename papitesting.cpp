#include "papitesting.h"
#include "sortingnetwork.h"
#include "sortingnetworkSSE.h"
#include "timer.h"

void initPapi(int eventCode)
{
    if (PAPI_start_counters(&eventCode, 1) != PAPI_OK)
    {
        fprintf(stderr,"Cannot start counters\n");
        exit(1);
    }
    return;
}

void stopPapi(long long* results)
{
    if (PAPI_stop_counters(results, 1) != PAPI_OK)
    {
        fprintf(stderr,"Cannot read counters\n");
        exit(1);
    }
    return;
}

