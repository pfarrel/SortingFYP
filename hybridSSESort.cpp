#include "hybridSSESort.h"
#include "timer.h"
#include "datastructures.h"
#include "testing.h"
#include "insertion.h"
#include "shell.h"
#include "rsort/masks.h"
#include "rsort/rsort_u.h"
#include "rsort/rsort_a.h"
#include "rsort/rsort_us.h"
#include "rsort/rsort_as.h"
#include "quicksort.h"
#include "quicksortsse.h"
#include "sortingnetwork.h"
#include "sortingnetworkSSE.h"
#include "mergesort.h"
#include "psrs.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <float.h>
using namespace std;

vector<smallAlgorithm> smallAlgorithms;
smallAlgorithm bestSmallAlgorithm;

vector<smallAlgorithm> SSEQuicksorts;
smallAlgorithm bestSSEQuicksort;

extern std::vector<papiCode> papiCodes;

float* workKeys;
float** keys;

int size = 1024*1024*32;
int runs = 10;

int main()
{
    keys = (float**)malloc(sizeof(float*) * runs);
    workKeys = (float*)malloc(sizeof(float)  * (size));

    srand(0);
    
    for (int i=0; i<runs; i++)
    {
        keys[i] = (float*)malloc(sizeof(float) * (size));
    }

    for (int i=0; i < runs; i++)
    {
        for (int j=0; j < size; j++)
        {
            keys[i][j] = (float) (rand() % 100000000);
        }
    }

    setupSmallAlgorithms();
    setupPapiCodes();
    
    generateQuicksort();
    generateSSEQuicksort();
    generateMergesort();
    
    for (int i=0; i<runs; i++)
    {
        free(keys[i]);
    }
    free(workKeys);

}

void generateQuicksort()
{
    long long totalFastestTime = 0xFFFFFFFFFFFFF;
    int totalFastestThresh;
    smallAlgorithm* fastestAlgorithm;

    cout << "Generating Optimal Quicksort" << endl;
    
    for (vector<smallAlgorithm>::iterator it=algorithms.begin(); it != algorithms.end(); ++it)
    {
        long long fastestTime = 0xFFFFFFFFFFFF;
        int fastestThresh;
        cout << (*it).name << endl;
        for (int i=0; i< (*it).maxSize; i++)
        {
            vector<long long> times;
            setupQuicksort(3,1,i,&(*it.function));
            cout << "Threshold: " << i << ",";
            for (int j=0; j<runs; j++)
            {
                    memcpy(workKeys, keys[j], (size + 8) * sizeof(float));
                    clearCache();
                    timer t;
                    t.reset();
                    quicksortWrapper(workKeys, workKeys + size);
                    time.push_back(t.elapsedTicks());
            }
            cout << i << " - " << medianTime(times) << endl;
            if ( medianTime(times) < fastestTime)
            {
                fastestTime = median(times);
                fastestThresh = i;   
            }
       }
        cout << "Fastest: " << fastestTime << " at Threshold: " << fastestThresh << endl;
        if (fastestTime < totalFastestTime)
        {
            totalFastestTime = fastestTime;
            totalFastestThresh = fastestThresh;
            fastestAlgorithm = &(*it)
        }
    }
    cout << "Optimal Quicksort switches to " << fastestAlgorithm->name << " at " << totalFastestThresh << "keys." << endl;
}

void generateSSEQuicksort()
{
    long long fastestTime = 0xFFFFFFFFFFFFF;
    smallAlgorithm* fastestAlgorithm;

    setupQuicksort(3,1,52,rsort_us);

    cout << "Generating Optimal Quicksort" << endl;
    
    for (vector<smallAlgorithm>::iterator it=algorithms.begin(); it != algorithms.end(); ++it)
    {
        cout << (*it).name << endl;
        
        vector<long long> times;
        cout << "Threshold: " << i << ",";
        for (int j=0; j<runs; j++)
        {
            memcpy(workKeys, keys[j], (size + 8) * sizeof(float));
            clearCache();
            timer t;
            t.reset();
            &(*it.function)(workKeys, workKeys + size);
            time.push_back(t.elapsedTicks());
        }
        cout << (*it)->name << " - " << medianTime(times) << endl;
        if ( medianTime(times) < fastestTime)
        {
            fastestTime = median(times);
            fastestAlgorithm = &(*it);   
        }
    }
    
    cout << "Optimal Vectorised Quicksort is " << fastestAlgorithm->name << endl;
}

void generateMergesort()
{
    long long fastestTime = 0xFFFFFFFFFFFFF;
    int fastestBlockSize;
    
    for (int i=64; i<= size; i*=2)
    {
        for (int j=0; j<runs; j++)
        {
            memcpy(workKeys, keys[j], (size + 8) * sizeof(float));
            clearCache();
            timer t;
            t.reset();
            mergeSort_CacheAware(workKeys, workKeys + size, i);
            time.push_back(t.elapsedTicks());
        }
        cout << "Block Size: " << i << " - " << medianTime(times) << endl;
        if ( medianTime(times) < fastestTime)
        {
            fastestTime = median(times);
            fastestBlockSize = i;
        }
    }
    cout << "Optimal Mergesort uses a block size of " << fastestBlockSize << endl;
}

void setupSmallAlgorithms()
{
    smallAlgorithm tmp;
    
    tmp.name = string("Scalar Sorting Networks");
    tmp.function = &fastestnetwork;
    tmp.maxSize = 32;
    tmp.times = vector<long long>(32);
    smallAlgorithms.push_back(tmp);

    tmp.name = string("Scalar SSE Sorting Networks");
    tmp.function = &fastestnetworkSSE;
    tmp.maxSize = 32;
    tmp.times = vector<long long>(32);
    smallAlgorithms.push_back(tmp);

    tmp.name = string("Unaligned Safe Register Sort");
    tmp.function = &rsort_us;
    tmp.maxSize = 52;
    tmp.times = vector<long long>(52);
    smallAlgorithms.push_back(tmp);

    tmp.name = string("Aligned Safe Register Sort");
    tmp.function = &mergeSort_Serial;
    tmp.maxSize = 46;
    tmp.times = vector<long long>(46);
    smallAlgorithms.push_back(tmp);

    tmp.name = string("Insertion Sort");
    tmp.function = &insertion_sort;
    tmp.maxSize = 128;
    tmp.times = vector<long long>(128);
    smallAlgorithms.push_back(tmp);

    tmp.name = string("Two Pass, Single Level Out of Place Partitioning");
    tmp.function = &bucketSort_SIMD_Arrays_Sparse;
    SSEQuicksorts.push_back(tmp);
    
    tmp.name = string("Two Pass, Single Level In Place Partitioning");
    tmp.function = &bucketSort_SIMD_InPlace_Sparse;
    SSEQuicksorts.push_back(tmp);

    tmp.name = string("Two Pass, Multilevel In Place Partitioning");
    tmp.function = &bucketSort_SIMD_Multilevel_InPlace_Lookup;
    SSEQuicksorts.push_back(tmp);
}

