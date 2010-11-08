#include <cstdlib>
#include <iostream>

#include "quicksort.h"
#include "payload.h"
#include "timer.h"
#include "datastructures.h"
#include "shell.h"
#include "radix.h"
#include "psrs.h"

#define MIN_PARTITION 20

#define NUM_THREADS 3


int main();
void doSort(char fn[]);

void tuneQSInsertion(char fn[], int from, int to);
void tuneQSSN(char fn[], int from, int to);
void tuneRadixInsertion(char fn[], int from, int to);
void tuneQSSS(char fn[], int from, int to);
void tuneSplit(char fn[], int from, int to);

void timePartition(char fn[]);
void tunePSRS(char fn[], int from, int to, int alg);


float singleQSITest(char fn[], int thresh);
float singleQSSNTest(char fn[], int thresh);
float singleRadixITest(char fn[], int thresh);
float singleQSSSTest(char fn[], int thresh);
float singleSplitTest(char fn[], int depth, int alg);
float singleRadixOMPTest(char fn[], int p);

void tuneRadixOMP(char fn[], int from, int to);
float singlePartitionTest(char fn[]);
float singleSplitPartitionTest(char fn[], int threads);
float singlePSRS(char fn[], int p, int alg);

float testSTL(char* fn);

static int MAX_THREAD_DEPTH;
static int MAX_THREADS;

int main()
{
	for(MAX_THREADS = 1; MAX_THREADS <= 8; MAX_THREADS++)
	{
		MAX_THREAD_DEPTH = MAX_THREADS;
//		doSort((char*)"keys/dist-normal_stdev-100000000_count-32.0M.bin");
//		doSort((char*)"keys/dist-normal_stdev-100000000_count-0.25M.bin");
//		doSort(NULL);
	}

	tuneRadixOMP(NULL, 1, 16);

	testSTL(NULL);

	tunePSRS(NULL, 1, 10, 1);
        tunePSRS(NULL, 1, 10, 2);
        tunePSRS(NULL, 1, 10, 3);
	
	tunePSRS((char*)"keys/dist-normal_stdev-100000000_count-32.0M.bin", 1, 10, 1);

	timePartition(NULL);

	tuneSplit(NULL, 1, 9);
	

	tuneRadixInsertion(NULL, 4, 16);

	tuneQSInsertion(NULL, 40, 60);
	//tuneQSInsertion((char*)"keys/dist-normal_stdev-100000000_count-32.0M.bin", 40, 60);

	tuneQSSN(NULL, 16, 28);
	tuneQSSS(NULL, 20, 80);
	//tuneSplit(NULL, 1, 9);

	return 0;
}

void doSort(char fn[])
{
	payload* keys;
	
	if(fn != NULL)
		keys = new payload(fn);
	else
		keys = new payload(32*1024*1024);
	timer t; // start a clock

//	split_radix(keys->k, keys->count);
	
//	qs_params qsp = {1, MAX_THREAD_DEPTH, &t, keys->k, keys->k + keys->count};
//	qs_thread((void*)(&qsp));
//	split_quick((void*)(&qsp));

//	radix_thread((void*)(&qsp));
//	split_radix((void*)(&qsp));

//	parallel_partition((void*)(&qsp));
	
//	const int median = median3(keys->k[0], keys->k[keys->count/2], keys->k[keys->count-1]);
//	int* mid = unguarded_partition(keys->k, keys->k + keys->count, median);

//	int test[] = {0,1,3,3,3,3,4,4,5,6,7,7,8,9,9,0,1,2,3,3,3,4,5,6,6,7,7,8,8,9,0,1,2,2,3,3,4,4,5,5,7,7,8,9,9}; 
//	PSRS(&test[0], &test[0] + 45, 8);
//	PSRS(keys->k, keys->k + keys->count, MAX_THREADS, 3);

	float time = t.elapsed();
	printf("%d threads: %.5f sec\n", MAX_THREADS, time);
//	keys->checksorted(true);	// verbose verification
//	keys->print();
	
	delete keys;
//	system("PAUSE");
}

float testSTL(char fn[])
{
	payload* keys;

	if(fn != NULL)
		keys = new payload(fn);
	else
		keys = new payload(32*1024*1024);

	timer t;
	std::sort(keys->k, keys->k + keys->count);

	float time = t.elapsed();
	printf("STL: %.6f\n", time);

	return time;
}

float singlePartitionTest(char fn[])
{
        float times[9];

        for(int i = 0; i < 9; i++)
        {
                payload* keys;

                if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;

		const int& pivot = median3      (       *(keys->k),
                                *(keys->k + (keys->count / 2)),
                                *(keys->k + keys->count - 1)
                                );

		unguarded_partition(keys->k, keys->k + keys->count, pivot);


//              keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
        }

        // take the average of the desired runs
        std::sort(times, times+9);
        float result = 0.0f;
        for(int i = 3; i < 6; i++)
                result += times[i];

        result = result / 3;
        return result;

}

float singleSplitPartitionTest(char fn[], int optimised)
{
        float times[9];

        for(int i = 0; i < 9; i++)
        {
                payload* keys;

                if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;

                qs_params qsp = {optimised, 1, &t, keys->k, keys->k + keys->count};
		parallel_partition((void*)&qsp);

//              keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
        }

        // take the average of the desired runs
        std::sort(times, times+9);
        float result = 0.0f;
        for(int i = 3; i < 6; i++)
                result += times[i];

        result = result / 3;
        return result;

}


float singleSplitTest(char fn[], int depth, int alg)
{
	float times[9];

	for(int i = 0; i < 9; i++)
	{
		payload* keys;
	
		if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;


        	qs_params qsp = {1, depth, &t, keys->k, keys->k + keys->count};
		
		if(alg == 0)
			split_quick((void*)(&qsp));
		else if(alg == 1)
	        	split_radix((void*)(&qsp));


//              keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
	}

        // take the average of the desired runs
        std::sort(times, times+9);
        float result = 0.0f;
        for(int i = 3; i < 6; i++)
                result += times[i];

        result = result / 3;
        return result;

}

float singleQSITest(char fn[], int thresh)
{

	float times[5];

	// run the test X times
	for(int i = 0; i < 5; i++)
        {
		payload* keys;

		if(fn != NULL)
	      		keys = new payload(fn);
                else
			keys = new payload(32*1024*1024);
                timer t;

                qs_in_wrapper(keys->k, keys->k + keys->count, thresh);
//              keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
	}

	// take the average of the desired runs
	std::sort(times, times+5);
	float result = 0.0f;
	for(int i = 1; i < 4; i++)
		result += times[i];

	result = result / 3;
	return result;
}

float singleRadixOMPTest(char fn[], int p)
{

        float times[5];

        // run the test X times
        for(int i = 0; i < 5; i++)
        {
                payload* keys;

                if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;

		radix_int_thresh2_omp(keys->k, keys->count, p);
//		radix_int_thresh2(keys->k, keys->count);
//              keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
        }

        // take the average of the desired runs
        std::sort(times, times+5);
        float result = 0.0f;
        for(int i = 1; i < 4; i++)
                result += times[i];

        result = result / 3;
        return result;
}


float singleQSSNTest(char fn[], int thresh)
{

        float times[5];

        // run the test X times
        for(int i = 0; i < 5; i++)
        {
                payload* keys;

                if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;

                qs_sn_wrapper(keys->k, keys->k + keys->count, thresh);
//              keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
        }

        // take the average of the desired runs
        std::sort(times, times+5);
        float result = 0.0f;
        for(int i = 1; i < 4; i++)
                result += times[i];

        result = result / 3;
        return result;
}


float singleQSSSTest(char fn[], int thresh)
{

        float times[5];

        // run the test X times
        for(int i = 0; i < 5; i++)
        {
                payload* keys;

                if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;

                qs_ss_wrapper(keys->k, keys->k + keys->count, thresh);
//              keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
        }

        // take the average of the desired runs
        std::sort(times, times+5);
        float result = 0.0f;
        for(int i = 1; i < 4; i++)
                result += times[i];

        result = result / 3;
        return result;
}


float singleRadixITest(char fn[], int thresh)
{

        float times[5];

        // run the test X times
        for(int i = 0; i < 5; i++)
        {
                payload* keys;

                if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;

//		radix_int_thresh2(keys->k, keys->count, thresh);
		if(thresh == 4)
			radix_4(keys->k, keys->count, 28);
		else if(thresh == 8)
			radix_8(keys->k, keys->count, 24);
		else if(thresh == 16)
			radix_16(keys->k, keys->count, 16);
	
	//	keys->checksorted(true);
                times[i] = t.elapsed();
                delete keys;
        }

        // take the average of the desired runs
        std::sort(times, times+5);
        float result = 0.0f;
        for(int i = 1; i < 4; i++)
                result += times[i];

        result = result / 3;
        return result;
}

void tunePSRS(char fn[], int from, int to, int alg)
{
        float times[to+1];
        for(int i = from; i <= to; i++)
        {
                times[i] = singlePSRS(fn, i, alg);
                printf("PSRS: %d threads - %f\n", i, times[i]);

        }

        int bestIndex;
        float bestVal = 1000000000.0f;
        for(int i = from; i <= to; i++)
        {
                if(times[i] < bestVal)
                {
                        bestVal = times[i];
                        bestIndex = i;
                }
        }

	if(fn == NULL)
	        printf("\e[32mOptimum PSRS thread count for algorithm %d, evenly distributed keys: %d\e[m\n", alg, bestIndex);
	else
		printf("\e[32mOptimum PSRS thread count for algorithm %d, keyset %s: %d\e[m\n",alg, fn, bestIndex);
}

float singlePSRS(char fn[], int p, int alg)
{
        float times[15];
        for(int i = 0; i < 15; i++)
        {
                payload* keys;

                if(fn != NULL)
                        keys = new payload(fn);
                else
                        keys = new payload(32*1024*1024);
                timer t;

                PSRS(keys->k, keys->k + keys->count, p, alg);
                times[i] = t.elapsed();
//		printf("%d single PSRS %d threads alg %d:%f\n",i,p,alg,times[i]);

		delete keys;

        }

	std::sort(times, times+15);
	float total = 0.0f;

        for(int i = 5; i < 10; i++)
		total += times[i];
	total = total/5;

	return total;
}


void timePartition(char fn[])
{
	float sPT = singlePartitionTest(fn);
	float sSPTUO = singleSplitPartitionTest(fn, 0);
	float sSPTO = singleSplitPartitionTest(fn, 1);

	printf("Standard partition: %.4f\nSplit partition: %.4f\nSplit partition memcpy: %.4f\n", sPT, sSPTUO, sSPTO);

	if(sPT < sSPTUO && sPT < sSPTO)
		printf("\e[32mFastest partitioning method: Standard partition (%.4f)\e[m\n", sPT);
	else if(sSPTUO < sPT && sSPTUO < sSPTO)
		printf("\e[32mFastest partitioning method: Split partition(%.4f)\e[m\n", sSPTUO);
	else if(sSPTO < sPT && sSPTO < sSPTUO)
		printf("\e[32mFastest partitioning method: Split partition (memcpy) (%.4f)\e[m\n", sSPTO);
	
}

void tuneSplit(char fn[], int from, int to)
{
        float times[to+1];
        for(int i = from; i <= to; i++)
        {
                times[i] = singleSplitTest(NULL, i, 0);
                printf("QS_split: %d - %f\n", i, times[i]);

        }

        int bestIndex;
        float bestVal = 1000000000.0f;
        for(int i = from; i <= to; i++)
        {
                if(times[i] < bestVal)
                {
                        bestVal = times[i];
                        bestIndex = i;
                }
        }

        printf("\e[32mOptimum QS_split thread depth: %d\e[m\n", bestIndex);

	for(int i = from; i <= to; i++)
        {
                times[i] = singleSplitTest(NULL, i, 1);
                printf("Radix_split: %d - %f\n", i, times[i]);

        }

        bestVal = 1000000000.0f;
        for(int i = from; i <= to; i++)
        {
                if(times[i] < bestVal)
                {
                        bestVal = times[i];
                        bestIndex = i;
                }
        }

        printf("\e[32mOptimum QS_split thread depth: %d\e[m\n", bestIndex);


}

void tuneQSInsertion(char fn[], int from, int to)
{
	float times[to+1];
	for(int i = from; i <= to; i++)
	{
		times[i] = singleQSITest(NULL, i);
		printf("QSI: %d - %f\n", i, times[i]);
			
	}

	int bestIndex;
	float bestVal = 1000000000.0f;
	for(int i = from; i <= to; i++)
	{
		if(times[i] < bestVal)
		{
			bestVal = times[i];
			bestIndex = i;
		}
	}

	printf("\e[32mOptimum QS to Insertion sort switch threshold: %d\e[m\n", bestIndex);

}

void tuneQSSN(char fn[], int from, int to)
{
	float times[to+1];
	for(int i = from; i <= to; i++)
	{
		times[i] = singleQSSNTest(NULL, i);
		printf("QSSN: %d - %f\n", i, times[i]);
	}

	int bestIndex;
        float bestVal = 1000000000.0f;
        for(int i = from; i <= to; i++)
        {
                if(times[i] < bestVal)
                {
                        bestVal = times[i];
                        bestIndex = i;
                }
        }

        printf("\e[32mOptimum QS to SN switch threshold: %d\e[m\n", bestIndex);

}



void tuneRadixInsertion(char fn[], int from, int to)
{
	float times[to+1];
        for(int i = from; i <= to; i *= 2)
        {
                times[i] = singleRadixITest(NULL, i);
                printf("RadixI: %d - %f\n", i, times[i]);

        }

        int bestIndex;
        float bestVal = 1000000000.0f;
        for(int i = from; i <= to; i *= 2)
        {
                if(times[i] < bestVal)
                {
                        bestVal = times[i];
                        bestIndex = i;
                }
        }

        printf("\e[32mOptimum Radix digits per pass: %d (%.3f)\e[m\n", bestIndex, bestVal);
	
}

void tuneQSSS(char fn[], int from, int to)
{
        float times[to+1];
        for(int i = from; i <= to; i++)
        {
                times[i] = singleQSSSTest(NULL, i);
                printf("QSShell: %d - %f\n", i, times[i]);
        }

        int bestIndex;
        float bestVal = 1000000000.0f;
        for(int i = from; i <= to; i++)
        {
                if(times[i] < bestVal)
                {
                        bestVal = times[i];
                        bestIndex = i;
                }
        }

        printf("\e[32mOptimum QS to SS switch threshold: %d\e[m\n", bestIndex);

}


void tuneRadixOMP(char fn[], int from, int to)
{
        float times[to+1];
        for(int i = from; i <= to; i++)
        {
                times[i] = singleRadixOMPTest(NULL, i);
                printf("RadixOMP: %d - %f\n", i, times[i]);
        }

        int bestIndex;
        float bestVal = 1000000000.0f;
        for(int i = from; i <= to; i++)
        {
                if(times[i] < bestVal)
                {
                        bestVal = times[i];
                        bestIndex = i;
                }
        }

        printf("\e[32mOptimum Radix OMP thread count: %d\e[m\n", bestIndex);

}

