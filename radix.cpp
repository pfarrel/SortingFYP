#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "radix.h"
#include "insertion.h"
#include "quicksort.h" // partitioning etc
#include "datastructures.h"

//#define MAX_THREAD_DEPTH 3

void radix_int_thresh2_recurse(int* a, int n, int bit_depth)
{
	int count[256];
	/*unsigned*/ int pile_idx[256];
	memset(count, 0, 256 * sizeof(int));	// set all counts to 0

	// count how many elements fall into each pile
	for(int i = 0; i < n; i++)
	{
		count[(a[i] >> bit_depth) & 0xFF]++;
	}

	// set pile boundaries relative to the beginning of the array
	int j = 0;
	for(int i = 0; i < 256; i++)
	{
		j += count[i];
		pile_idx[i] = j;
	}

	// core of the algorithm. continuously swap keys into their
	// destination pile. if the starting pile fills up, move
	// onto the next and start there. piles fill from the top
	// downwards with correct values.
	for(int i = 0; i < n; i += count[j])
	{
		int r = a[i];	// start with a key from the top of the current pile

		// decrement the "free space" counter for the appropriate pile
		// and save that location for later swapping into
		while(--pile_idx[j = (r >> bit_depth) & 0xFF] > i)
		{
			// swap the curr key into its destination pile
			int tmp = a[pile_idx[j]];
			a[pile_idx[j]] = r;
			r = tmp;
		}
		a[i] = r;
	}

	// if the bit mask now comprises the whole key, the array
	// is completely sorted. return.
	if(!bit_depth)
		return;
	

	//TODO	
	j = 0;
	int i = 0;
	while(i < 256)
	{
		if(count[i] >= 20)
		{
			radix_int_thresh2_recurse(a + j, count[i], bit_depth - 8);
			j += count[i];
		}	
		else
		{
			insertion_sort(a+j, a+j+count[i]);
			j += count[i];

		}	
		i++;
	}
	return;
}

// wrapper function
void radix_int_thresh2(int* a, int n)
{
	radix_int_thresh2_recurse(a, n, (sizeof(int) - 1) << 3);
	return;
}


void* split_radix(void* qsp1)
{
        qs_params* qsp = (qs_params*)qsp1;

	// check if we are allowed to spawn off another level of threads	
	if(qsp->thread_depth < qsp->MAX_THREAD_DEPTH)
	{
	        // find a pivot using median of 3
/*	        const int& pivot = median3      (       *(qsp->first),
	                                                *(qsp->first + (qsp->last - qsp->first) / 2),
	                                                *(qsp->last - 1)
	                                        );
*/
		const int pivot = medianX(qsp->first, qsp->last, 27);

	        // partition around the pivot
	        int* pivot2 = unguarded_partition(qsp->first, qsp->last, pivot);

	        qs_params qsp_worker[2] = {{qsp->thread_depth+1, qsp->MAX_THREAD_DEPTH, NULL, qsp->first, pivot2},{qsp->thread_depth+1, qsp->MAX_THREAD_DEPTH, NULL, pivot2, qsp->last}};

	        pthread_t pth[2];

//                long long total = qsp->last-qsp->first;
//                long long left = qsp_worker[0].last-qsp_worker[0].first;
//                long long right = qsp_worker[1].last-qsp_worker[1].first;
//                printf("Splitting %llu into %llu and %llu partitions\t\t(%.2f%% / %.2f%%)\n",
//                        total, left, right, ((float)(left*100)/total), ((float)(right*100)/total));

                pthread_create(&pth[0], NULL, &split_radix, (void*)&qsp_worker[0]);
                pthread_create(&pth[1], NULL, &split_radix, (void*)&qsp_worker[1]);
                pthread_join(pth[0], NULL);
                pthread_join(pth[1], NULL);
        }

        // otherwise sort the two partitions in the current thread
        else if(qsp->first != qsp->last)
        {
//		radix_int_thresh2(qsp->first, qsp->last-qsp->first);
		radix_thread(qsp1);
        }

	return NULL;
}


void* radix_thread(void* qsp1)
{
	qs_params* qsp = (qs_params*)qsp1;
	
	if(qsp->first != qsp->last)
	{	
		radix_int_thresh2(qsp->first, qsp->last-qsp->first);
	}
	return NULL;
}

void radix_4(int* a, int n, int bit_depth)
{
        int count[16];
        /*unsigned*/ int pile_idx[16];
        memset(count, 0, 16 * sizeof(int));    // set all counts to 0

        // count how many elements fall into each pile
        for(int i = 0; i < n; i++)
        {
                count[(a[i] >> bit_depth) & 0xF]++;
        }

        // set pile boundaries relative to the beginning of the array
        int j = 0;
        for(int i = 0; i < 16; i++)
        {
                j += count[i];
                pile_idx[i] = j;
        }

        // core of the algorithm. continuously swap keys into their
        // destination pile. if the starting pile fills up, move
        // onto the next and start there. piles fill from the top
        // downwards with correct values.
        for(int i = 0; i < n; i += count[j])
        {
                int r = a[i];   // start with a key from the top of the current pile

                // decrement the "free space" counter for the appropriate pile
                // and save that location for later swapping into
                while(--pile_idx[j = (r >> bit_depth) & 0xF] > i)
                {
                        // swap the curr key into its destination pile
                        int tmp = a[pile_idx[j]];
                        a[pile_idx[j]] = r;
                        r = tmp;
                }
                a[i] = r;
        }

        // if the bit mask now comprises the whole key, the array
        // is completely sorted. return.
        if(!bit_depth)
                return;


        //TODO
        j = 0;
        int i = 0;
        while(i < 16)
        {
                if(count[i] >= 20)
                {
                        radix_4(a + j, count[i], bit_depth - 4);
                        j += count[i];
                }
                else
                {
                        insertion_sort(a+j, a+j+count[i]);
                        j += count[i];

                }
                i++;
        }
        return;
}

void radix_8(int* a, int n, int bit_depth)
{
        int count[256];
        /*unsigned*/ int pile_idx[256];
        memset(count, 0, 256 * sizeof(int));    // set all counts to 0

        // count how many elements fall into each pile
        for(int i = 0; i < n; i++)
        {
                count[(a[i] >> bit_depth) & 0xFF]++;
        }

        // set pile boundaries relative to the beginning of the array
        int j = 0;
        for(int i = 0; i < 256; i++)
        {
                j += count[i];
                pile_idx[i] = j;
        }

        // core of the algorithm. continuously swap keys into their
        // destination pile. if the starting pile fills up, move
        // onto the next and start there. piles fill from the top
        // downwards with correct values.
        for(int i = 0; i < n; i += count[j])
        {
                int r = a[i];   // start with a key from the top of the current pile

                // decrement the "free space" counter for the appropriate pile
                // and save that location for later swapping into
                while(--pile_idx[j = (r >> bit_depth) & 0xFF] > i)
                {
                        // swap the curr key into its destination pile
                        int tmp = a[pile_idx[j]];
                        a[pile_idx[j]] = r;
                        r = tmp;
                }
                a[i] = r;
        }

        // if the bit mask now comprises the whole key, the array
        // is completely sorted. return.
        if(!bit_depth)
                return;


        //TODO
        j = 0;
        int i = 0;
        while(i < 256)
        {
                if(count[i] >= 20)
                {
                        radix_8(a + j, count[i], bit_depth - 8);
                        j += count[i];
                }
                else
                {
                        insertion_sort(a+j, a+j+count[i]);
                        j += count[i];

                }
                i++;
        }
        return;
}

void radix_16(int* a, int n, int bit_depth)
{
        int count[65536];
        /*unsigned*/ int pile_idx[65536];
        memset(count, 0, 65536 * sizeof(int));    // set all counts to 0

        // count how many elements fall into each pile
        for(int i = 0; i < n; i++)
        {
                count[(a[i] >> bit_depth) & 0xFFFF]++;
        }

        // set pile boundaries relative to the beginning of the array
        int j = 0;
        for(int i = 0; i < 65536; i++)
        {
                j += count[i];
                pile_idx[i] = j;
        }

        // core of the algorithm. continuously swap keys into their
        // destination pile. if the starting pile fills up, move
        // onto the next and start there. piles fill from the top
        // downwards with correct values.
        for(int i = 0; i < n; i += count[j])
        {
                int r = a[i];   // start with a key from the top of the current pile

                // decrement the "free space" counter for the appropriate pile
                // and save that location for later swapping into
                while(--pile_idx[j = (r >> bit_depth) & 0xFFFF] > i)
                {
                        // swap the curr key into its destination pile
                        int tmp = a[pile_idx[j]];
                        a[pile_idx[j]] = r;
                        r = tmp;
                }
                a[i] = r;
        }

        // if the bit mask now comprises the whole key, the array
        // is completely sorted. return.
        if(!bit_depth)
                return;


        //TODO
        j = 0;
        int i = 0;
        while(i < 65536)
        {
                if(count[i] >= 20)
                {
                        radix_16(a + j, count[i], bit_depth - 16);
                        j += count[i];
                }
                else
                {
                        insertion_sort(a+j, a+j+count[i]);
                        j += count[i];

                }
                i++;
        }
        return;
}

void radix_int_thresh2_omp(int* a, int n, int p)
{
        radix_int_thresh2_recurse_omp(a, n, (sizeof(int) - 1) << 3, p);
        return;
}


void radix_int_thresh2_recurse_omp(int* a, int n, int bit_depth, int p)
{
        int count[256];
        /*unsigned*/ int pile_idx[256];
        memset(count, 0, 256 * sizeof(int));    // set all counts to 0

        // count how many elements fall into each pile
        for(int i = 0; i < n; i++)
        {
                count[(a[i] >> bit_depth) & 0xFF]++;
        }

        // set pile boundaries relative to the beginning of the array
        int j = 0;
        for(int i = 0; i < 256; i++)
        {
                j += count[i];
                pile_idx[i] = j;
        }

        // core of the algorithm. continuously swap keys into their
        // destination pile. if the starting pile fills up, move
        // onto the next and start there. piles fill from the top
        // downwards with correct values.
        for(int i = 0; i < n; i += count[j])
        {
                int r = a[i];   // start with a key from the top of the current pile

                // decrement the "free space" counter for the appropriate pile
                // and save that location for later swapping into
                while(--pile_idx[j = (r >> bit_depth) & 0xFF] > i)
                {
                        // swap the curr key into its destination pile
                        int tmp = a[pile_idx[j]];
                        a[pile_idx[j]] = r;
                        r = tmp;
                }
                a[i] = r;
        }

        // if the bit mask now comprises the whole key, the array
        // is completely sorted. return.
        if(!bit_depth)
                return;


        //TODO
        j = 0;
	int k[256];
	k[0] = 0;
	for(int i = 0; i < 255; i++)
	{
		k[i+1] = k[i] + count[i];
	}
//      printf("test: %d\n",  
	#pragma omp parallel for num_threads(p) schedule(static, 4)
	for(int i = 0; i < 256; i++)
        {
//		if((sizeof(int) - 1) << 3 == bit_depth)printf("here j is %d, k is %d\n",j,k[i]);
                if(count[i] >= 20)
                {
                        radix_int_thresh2_recurse_omp(a + k[i], count[i], bit_depth - 8, p);
                }
                else
                {
                        insertion_sort(a+k[i], a+k[i]+count[i]);

                }
		
		j += count[i];
        }
        return;
}

