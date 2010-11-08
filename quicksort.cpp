#include <iostream>
#include <algorithm>
#include <string.h>

#include "quicksort.h"
#include "insertion.h"
#include "shell.h"
#include "datastructures.h"
#include "sortingnetwork.h"
#include <pthread.h>

int qsNumPivots = 21;
int qsMaxThreadDepth = 1;
int qsThreshold = 32;
Sort_FuncPtr smallSort = &insertion_sort;

void setupQuicksort(int numPivots, int maxThreadDepth, int threshold, Sort_FuncPtr sortfunc)
{
    qsNumPivots = numPivots;
    qsMaxThreadDepth = maxThreadDepth;
    qsThreshold = threshold;
    smallSort = sortfunc;
}

void quicksortWrapper(float* first, float* last)
{
    if (first != last)
    {
        quicksortLoop(first, last);
    }
}

void quicksortLoop(float* first, float* last)
{
    while (last - first > qsThreshold)
    {
        const float& pivot = median3(*first, *(first + (last - first) / 2), *(last - 1));
        
        float* pivot2 = unguardedPartition(first, last, pivot);

        quicksortLoop(pivot2, last);
        last = pivot2;
    }
    smallSort(first, last);
}

float* unguardedPartition(float* first, float* last, const float pivot)
{
    while (true)
    {
	    // skip over elements which do not need swapping in the left partition
        while (*first < pivot)
            ++first;

        --last;

		// skip over elements which do not need swapping in the right partition
        while (pivot < *last)
            --last;

		// return if pointers cross over (i.e. partitioning finished)
        if (!(first < last))
            return first;

        qsSwap(first, last);

        ++first;
    }
}

static inline const float& median3(const float& a, const float& b, const float& c)
{
    if (a < b)
		if (b < c)
			return b;
		else if (a < c)
			return c;
		else
			return a;
	else if (a < c)
		return a;
	else if (b < c)
		return c;
	else
		return b;
}

float medianX(float* first, float* last, const int num)
{
	float* values = new float[num];
	int i;
	for(i = 0; i < num; i++)
		values[i] = first[((last-first)/num)*i];
	insertion_sort(values, values+num);
	
//	delete values; // oops :)

	return values[num/2];
}


static inline void qsSwap(float* a, float* b)
{
        float tmp = *a;
        *a = *b;
        *b = tmp;
}

int checkPartitioned(float* first, float* mid, float* last, float pivot)
{
	int result = 1;
	float* i;

	//printf("%p, %p, %p\n", first, pivot, last);

	// left partition
	for(i = first; i < mid; i++)
		if(!(*i <= pivot))
			result = 0;

	// right partition
	for(i = mid; i < last; i++)
		if(!(*i >= pivot))
			result = 0;
			//printf("rp fail: %d > %d\n", *i, *pivot);

	if(result)
		printf("Partitioned: Yes\n");
	else
		printf("Partitioned: No\n");
	return result;
}

float* parallelPartition(void* qsp1)
{
	qs_params* qsp = (qs_params*)qsp1;
	float* mid = qsp->first + (qsp->last - qsp->first) / 2;
	int size = qsp->last - qsp->first;

	float pivot = medianX(qsp->first, qsp->last, qsNumPivots);

	partition_params ppleft = {qsp->first, mid, pivot, NULL};
	partition_params ppright = {mid, qsp->last, pivot, NULL};
	pthread_t pth[2];

	pthread_create(&pth[0], NULL, &partitionThread, (void*)&ppleft);
	pthread_create(&pth[1], NULL, &partitionThread, (void*)&ppright);
	pthread_join(pth[0], NULL);
	pthread_join(pth[1], NULL);

	int sizes[4] = {ppleft.mid - ppleft.first, ppleft.last - ppleft.mid, ppright.mid - ppright.first, ppright.last - ppright.mid};

	float* midMiddle = NULL;

	// do we run the memcpy version of mid partitioning?
	if(qsp->thread_depth == 1)
	{
		// if the right partition of the left half is 	
		if(sizes[1] > sizes[2])
		{
			float* tmp1 = new float[sizes[2]];
			memcpy(&tmp1, ppleft.first + sizes[0], sizes[2]*sizeof(float));		// copy the left size of the right partition of the left half to temp
			memcpy(ppleft.first + sizes[0], ppright.first, sizes[2]*sizeof(float));	// copy all of the left partition of the right half over
			memcpy(ppright.first, &tmp1, sizes[2]*sizeof(float));			// copy the temp into the left partition of the right half
			delete tmp1;
			midMiddle = ppleft.last;
		}

		else
		{
			float* tmp1 = new float[sizes[1]];
			memcpy(tmp1, ppleft.first + sizes[0], sizes[1]*sizeof(float));           // copy the left size of the right partition of the left half to temp
			memcpy(ppleft.first + sizes[0], ppleft.first + sizes[0] + sizes[2], sizes[1]*sizeof(float));   // copy all of the left partition of the right half over
			memcpy(ppleft.first + sizes[0] + sizes[2], tmp1, sizes[1]*sizeof(float));                     // copy the temp into the left partition of the right half
			delete tmp1;
			midMiddle = ppleft.first + sizes[0] + sizes[2];
		}
	}

	else
	{
		//middle
		midMiddle = unguardedPartition(ppleft.mid, ppright.mid, pivot);
	}

    //	checkPartitioned(qsp->first, midMiddle, qsp->last, m[2]);
	return midMiddle;
}

void* partitionThread(void* pp1)
{
	partition_params* pp = (partition_params*)pp1;
	pp->mid = unguardedPartition(pp->first, pp->last, pp->pivot);

	return NULL;
}


void* splitQuick(void* qsp1)
{
	qs_params* qsp = (qs_params*)qsp1;

	const float pivot = medianX(qsp->first, qsp->last, qsNumPivots);
        
	// partition around the pivot
    float* pivot2 = unguardedPartition(qsp->first, qsp->last, pivot);

	qs_params qsp_worker[2] = {{qsp->thread_depth+1, qsp->MAX_THREAD_DEPTH, NULL, qsp->first, pivot2},{qsp->thread_depth+1, qsp->MAX_THREAD_DEPTH, NULL, pivot2, qsp->last}};

	pthread_t pth[2];

	// check if we are allowed to spawn off another level of threads
	if(qsp->thread_depth < qsp->MAX_THREAD_DEPTH)
	{
		pthread_create(&pth[0], NULL, &splitQuick, (void*)&qsp_worker[0]);
		pthread_create(&pth[1], NULL, &splitQuick, (void*)&qsp_worker[1]);
		pthread_join(pth[0], NULL);
	        pthread_join(pth[1], NULL);
	}

	// otherwise sort the two partitions in the current thread
	else if(qsp->first != qsp->last)
	{
//		printf("thread at depth %d sorting...\n", qsp->thread_depth);
		qsThread((void*)&qsp_worker[0]);
		qsThread((void*)&qsp_worker[1]);
//		new_quicksort_loop(qsp->first, qsp->last);
//		insertion_sort(qsp->first, qsp->last);
	}
	
	return NULL;	
}

// worker thread function
void* qsThread(void* qsp1)
{
	qs_params* qsp = (qs_params*)qsp1;

	if(qsp->first != qsp->last)
    {
        quicksortWrapper(qsp->first, qsp->last);
    }
        return NULL;
}


