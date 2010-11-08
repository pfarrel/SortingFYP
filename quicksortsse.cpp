#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include "sse.h"
#include "sortingnetwork.h"
#include "insertion.h"
#include "quicksort.h"
#include "quicksortsse.h"
#include "psrs.h"
#include "radix.h"
#include "timer.h"
#include "rsort/rsort_us.h"
#include "rsort/rsort_a.h"
#include <float.h>
#include <stdlib.h>

using namespace std;

int maskLookup[16] = {0, 1, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 4};
int bucketsortThreshold = 1024*32;
int numBuckets = 3;

void bucketsort_Scalar_Lists(float* first, float* last)
{
    int length = last - first;
    int numPivots = numBuckets - 1;
    float* pivots;
    int* counts;

    if (length < bucketsortThreshold)
    {
        quicksortWrapper(first,last);
        return;
    }

    pivots = (float*)malloc(sizeof(float) * numPivots); 
    vector<float>* buckets = new vector<float>[numBuckets];

    // Create buckets and reserve space
    int approxBucketSize = length / numBuckets;    
    for (int i=0; i<numBuckets; i++)
    {
        buckets[i].reserve(approxBucketSize);
    }

    // Select Pivots
    int pivotStep = length / (numBuckets+1);
    for (int i=0; i<numBuckets; i++)
    {
        pivots[i] = first[(i+1)*pivotStep];
    }

    // Sort Pivots
    insertion_sort(pivots, pivots + numBuckets);

    // Find Element destination buckets and add them to the buckets
    for (float* current=first; current < last; current++)
    {
        int index = numPivots;
        float currentItem = *current;
        for (int i=0; i<numPivots; i++)
        {
            if(currentItem <= pivots[i])
            {
                index = i;
                break;
            }
        }
        buckets[index].push_back(currentItem);
    }
    
    float** partitions = new float*[numBuckets+1];
    partitions[0] = first;
    float* current = first;

    // Move buckets back into initial list space
    for (int i=0; i<numBuckets; i++)
    {
        memcpy(current, &(buckets[i][0]), sizeof(float) * buckets[i].size());
        current += buckets[i].size();
        partitions[i+1] = current;
    }    

    delete[] buckets;
    free(pivots);

    // Sort each bucket
    for (int i=0; i<numBuckets; i++)
    {
        bucketsort_Scalar_Lists(partitions[i], partitions[i+1]);
    }
    free(partitions);
    return;
}

void bucketsort_Scalar_Arrays(float* first, float* last)
{
    int length = last - first;
    int numPivots = numBuckets - 1;
    float* pivots;
    int* counts;
    float* workspace;

    if (length < bucketsortThreshold)
    {
        quicksortWrapper(first,last);
        return;
    }

    pivots = (float*)malloc(sizeof(float) * numPivots);
    counts = (int*)calloc(sizeof(int) * numBuckets,sizeof(int)); 
    workspace = (float*)malloc(sizeof(float) * length);

    // Select Pivots
    int pivotStep = length / (numBuckets+1);
    for (int i=0; i<numBuckets; i++)
    {
        pivots[i] = first[(i+1)*pivotStep];
    }

    // Sort Pivots
    insertion_sort(pivots, pivots + numBuckets);

    // Find Element destination buckets and add them to the buckets
    for (float* current=first; current < last; current++)
    {
        int index = numPivots;
        float currentItem = *current;
        for (int i=0; i<numPivots; i++)
        {
            if(currentItem <= pivots[i])
            {
                index = i;
                break;
            }
        }
        counts[index]++;
    }

    /* Setup starting offsets and sentinels */
    float** offsets = (float**)malloc(sizeof(float*) * numBuckets);
    offsets[0] = workspace;
    for (int i=1; i<numBuckets; i++)
    {
        offsets[i] = offsets[i-1] + counts[i-1];
    }

    for (float* current=first; current < last; current++)
    {
        int index = numPivots;
        float currentItem = *current;
        for (int i=0; i<numPivots; i++)
        {
            if(currentItem <= pivots[i])
            {
                index = i;
                break;
            }
        }
        *offsets[index] = currentItem;
        offsets[index]++;
    }

    memcpy(first, workspace, sizeof(float) * length);

    float** partitions = new float*[numBuckets+1];
    partitions[0] = first;
    float* current = first;

    // Move buckets back into initial list space
    for (int i=0; i<numBuckets; i++)
    {
        current += counts[i];
        partitions[i+1] = current;
    }    

    free(workspace);
    free(offsets);
    free(counts);
    free(pivots);

    // Sort each bucket
    for (int i=0; i<numBuckets; i++)
    {
        bucketsort_Scalar_Arrays(partitions[i], partitions[i+1]);
    }

    free(partitions);
    return;
}

void bucketsort_Scalar_InPlace(float* first, float* last)
{
    int length = last - first;
    int numPivots = numBuckets - 1;
    float* pivots;
    int* counts;

    if (length < bucketsortThreshold)
    {
        quicksortWrapper(first,last);
        return;
    }

    pivots = (float*)malloc(sizeof(float) * numPivots);
    counts = (int*)calloc(sizeof(int) * numBuckets,sizeof(int)); 

    // Select Pivots
    int pivotStep = length / (numBuckets+1);
    for (int i=0; i<numBuckets; i++)
    {
        pivots[i] = first[(i+1)*pivotStep];
    }

    // Sort Pivots
    insertion_sort(pivots, pivots + numBuckets);

    // Find Element destination buckets and add them to the buckets
    for (float* current=first; current < last; current++)
    {
        int index = numPivots;
        float currentItem = *current;
        for (int i=0; i<numPivots; i++)
        {
            if(currentItem <= pivots[i])
            {
                index = i;
                break;
            }
        }
        counts[index]++;
    }

    /* Setup starting offsets and sentinels */
    float** offsets = (float**)malloc(sizeof(float*) * numBuckets);
    offsets[0] = first;
    for (int i=1; i<numBuckets; i++)
    {
        offsets[i] = offsets[i-1] + counts[i-1];
    }

    float** sentinels = (float**)malloc(sizeof(float*) * numBuckets);
    for (int i=0; i<numBuckets-1; i++)
    {
        sentinels[i] = offsets[i+1];
    }
    sentinels[numBuckets-1] = offsets[numBuckets-1] + counts[numBuckets-1];

    for (int i=0; i<numBuckets; i++)
    {
        float* offset = offsets[i];
        float* sentinel = sentinels[i];
        
        while (offset < sentinel)
        {   
            int current = *offset;
            
            int destination = numPivots;
            for (int j=0; j<numPivots; j++)
            {
                if(current <= pivots[j])
                {
                    destination = j;
                    break;
                }
            }

            if (destination != i)
            {
                float temp = current;
                float temp2;
                float* nextOffset;
                while (destination != i)
                {
                    nextOffset = offsets[destination];

                    current = *nextOffset;
                    *nextOffset = temp;
                    temp = current;

                    nextOffset++;
                    offsets[destination] = nextOffset;

                    destination = numPivots;
                    for (int j=0; j<numPivots; j++)
                    {
                        if(current <= pivots[j])
                        {
                            destination = j;
                            break;
                        }
                    }
                }
                *offset = temp;
            }
            offset++;
        }    
    }

    float** partitions = new float*[numBuckets+1];
    partitions[0] = first;
    float* current = first;

    // Move buckets back into initial list space
    for (int i=0; i<numBuckets; i++)
    {
        current += counts[i];
        partitions[i+1] = current;
    }    

    free(offsets);
    free(counts);
    free(pivots);

    // Sort each bucket
    for (int i=0; i<numBuckets; i++)
    {
        bucketsort_Scalar_InPlace(partitions[i], partitions[i+1]);
    }

    free(partitions);
    return;
}

// Out of place, 5 partitions, sparse destination lists
void bucketsort_SIMD_Lists_Sparse(float* first, float* last)
{
    int length = last - first;
    float* pivots;
    __m128 pivotsS;
    
    if ( length < bucketsortThreshold )
    {
        quicksortWrapper(first,last);
        return;
    }

    pivots = (float*)malloc(sizeof(float) * 4);

    int pivotStep = length / (numBuckets+1);
    for (int i=0; i<numBuckets; i++)
    {
        pivots[i] = first[(i+1)*pivotStep];
    }

    vector<float>* buckets = new vector<float>[16];
    buckets[0].reserve(length/3);
    buckets[1].reserve(length/3);
    buckets[3].reserve(length/3);
    buckets[7].reserve(length/3);
    buckets[15].reserve(length/3);

    // Sort Pivots
    insertion_sort(pivots, pivots + 4);
    pivotsS = load(pivots);
    
    float* currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, pivotsS);
            
        int mask = _mm_movemask_ps(comparison);
        buckets[mask].push_back(*currentSource);
        currentSource++;
    }
    
    float** partitions = (float**)malloc(sizeof(float*) * 6);
    float* current = first;
    partitions[0] = first;

    memcpy(current, &(buckets[0][0]), sizeof(float)*buckets[0].size());
    current += buckets[0].size();
    partitions[1] = current;

    memcpy(current, &(buckets[1][0]), sizeof(float)*buckets[1].size());
    current += buckets[1].size();
    partitions[2] = current;

    memcpy(current, &(buckets[3][0]), sizeof(float)*buckets[3].size());
    current += buckets[3].size();
    partitions[3] = current;

    memcpy(current, &(buckets[7][0]), sizeof(float)*buckets[7].size());
    current += buckets[7].size();
    partitions[4] = current;

    memcpy(current, &(buckets[15][0]), sizeof(float)*buckets[15].size());
    current += buckets[15].size();
    partitions[5] = current;

    free(pivots);
    delete[] buckets;
    
    for (int i=0; i<5; i++)
    {
        bucketsort_SIMD_Lists_Sparse(partitions[i], partitions[i+1]);
    }
    free(partitions);

    return;
}

// Out of place, 5 partitions, sparse destination arrays so no mask conversion
void bucketsort_SIMD_Arrays_Sparse(float* first, float* last)
{
    int length = last - first;
    int* counts;
    float* pivots;
    float* workspace;
    __m128 pivotsS;
    
    if ( length < bucketsortThreshold )
    {
        quicksortWrapper(first,last);
        return;
    }

    pivots = (float*)malloc(sizeof(float) * 4);
    workspace = (float*)malloc(sizeof(float) * length);
    counts = (int*)calloc(sizeof(int) * 16,sizeof(int));

    int pivotStep = length / (numBuckets+1);
    for (int i=0; i<numBuckets; i++)
    {
        pivots[i] = first[(i+1)*pivotStep];
    }

    // Sort Pivots
    insertion_sort(pivots, pivots + 4);
    pivotsS = load(pivots);
    
    float* currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, pivotsS);
            
        int mask = _mm_movemask_ps(comparison);
        counts[mask]++;
        currentSource++;
    }
        
    float** offsets = (float**)malloc(sizeof(float*) * 16);
    offsets[0] = workspace;
    offsets[1] = offsets[0] + counts[0];
    offsets[3] = offsets[1] + counts[1];
    offsets[7] = offsets[3] + counts[3];
    offsets[15] = offsets[7] + counts[7]; 
    
    currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, pivotsS);

        int mask = _mm_movemask_ps(comparison);

        *(offsets[mask]) = *currentSource;
        offsets[mask]++;
        currentSource++;
    }

    memcpy(first, workspace, sizeof(float)*length);
    free(workspace);
    free(pivots);
    free(offsets);

    float* current = first;
    
    bucketsort_SIMD_Arrays_Sparse(current, current + counts[0]);
    current += counts[0];
    bucketsort_SIMD_Arrays_Sparse(current, current + counts[1]);
    current += counts[1];
    bucketsort_SIMD_Arrays_Sparse(current, current + counts[3]);
    current += counts[3];
    bucketsort_SIMD_Arrays_Sparse(current, current + counts[7]);
    current += counts[7];
    bucketsort_SIMD_Arrays_Sparse(current, current + counts[15]);
    current += counts[15];

    free(counts);

    return;
}

// In place, 5 partitions
void bucketSort_SIMD_InPlace_Sparse(float* first, float* last)
{
    int length = last - first;
    int* counts;
    float* pivots;
    __m128 pivotsS;

    if ( length < bucketsortThreshold )
    {
        quicksortWrapper(first,last);
        return;
    }

    pivots = (float*)malloc(sizeof(float) * 4);
    counts = (int*)calloc(sizeof(int) * 16,sizeof(int));

    int pivotStep = length / (numBuckets+1);
    for (int i=0; i<numBuckets; i++)
    {
        pivots[i] = first[(i+1)*pivotStep];
    }

    // Sort Pivots
    insertion_sort(pivots, pivots + 4);
    pivotsS = load(pivots);
 
    float* currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, pivotsS);
            
        int mask = _mm_movemask_ps(comparison);
        counts[mask]++;

        currentSource++;
    }
    
    
    float* offsets[16];
    offsets[0] = first;
    offsets[1] = offsets[0] + counts[0];
    offsets[3] = offsets[1] + counts[1];
    offsets[7] = offsets[3] + counts[3];
    offsets[15] = offsets[7] + counts[7]; 

    float* sentinels[16];
    sentinels[0] = offsets[1];
    sentinels[1] = offsets[3];
    sentinels[3] = offsets[7];
    sentinels[7] = offsets[15];
    sentinels[15] = offsets[15] + counts[15];

    for (int i=0; i<8; i=(i*2)+1)
    {        
        float* sentinel = sentinels[i];
        float* offset = offsets[i];

        while (offset < sentinel)
        {
            __m128 current = _mm_load1_ps(offset);
            __m128 comparison = _mm_cmpgt_ps(current, pivotsS);
            int mask = _mm_movemask_ps(comparison);

            if (mask != i)
            {
                float temp = *offset;
                float temp2;
                float* nextOffset;
                while (mask != i)
                {
                    nextOffset = offsets[mask];

                    current = _mm_load1_ps(nextOffset);
                    temp2 = *nextOffset;
                    *nextOffset = temp;
                    temp = temp2;
                    
                    comparison = _mm_cmpgt_ps(current, pivotsS);
 
                    nextOffset++;
                    offsets[mask] = nextOffset;

                    mask = _mm_movemask_ps(comparison);
                }
                *offset = temp;
            }
            offset++;
        }
    }

    float* current = first;

    bucketSort_SIMD_InPlace_Sparse(current, current + counts[0]);
    current += counts[0];
    bucketSort_SIMD_InPlace_Sparse(current, current + counts[1]);
    current += counts[1];
    bucketSort_SIMD_InPlace_Sparse(current, current + counts[3]);
    current += counts[3];
    bucketSort_SIMD_InPlace_Sparse(current, current + counts[7]);
    current += counts[7];
    bucketSort_SIMD_InPlace_Sparse(current, current + counts[15]);
    
    return;
}

// In place, 25 partitions, lookup table for mask conversion
void bucketSort_SIMD_Multilevel_InPlace_Lookup(float* first, float* last)
{
    int length = last - first;
    
    if ( length < bucketsortThreshold )
    {
        quicksortWrapper(first,last);
        return;
    }

    float* pivotsF = (float*)_mm_malloc(sizeof(float) * 24, 16);
    float* mainPivotsF = (float*)_mm_malloc(sizeof(float) * 4, 16);
    __m128 mainPivots;
    __m128 subPivots[5];
    __m128 tmp;    

    int* counts = (int*)malloc(sizeof(int) * 25);
    memset(counts, 0, sizeof(int) * 25);

    int pivotStep = length / 24;

    for (int i=0; i<24; i++)
    {
        pivotsF[i] = first[pivotStep*i];
    }

    insertion_sort(pivotsF, pivotsF + 24);

    mainPivotsF[0] = pivotsF[4];
    mainPivotsF[1] = pivotsF[9];
    mainPivotsF[2] = pivotsF[14];
    mainPivotsF[3] = pivotsF[19];

    pivotsF[4] = FLT_MAX;
    pivotsF[9] = FLT_MAX;
    pivotsF[14] = FLT_MAX;
    pivotsF[19] = FLT_MAX;
    
    insertion_sort(pivotsF, pivotsF + 24);

    mainPivots = _mm_load_ps(mainPivotsF);
    
    subPivots[0] = _mm_load_ps(pivotsF);
    subPivots[1] = _mm_load_ps(pivotsF + 4);
    subPivots[2] = _mm_load_ps(pivotsF + 8);
    subPivots[3] = _mm_load_ps(pivotsF + 12);
    subPivots[4] = _mm_load_ps(pivotsF + 16);
    
    /* First pass, count number of elements that will be in each section */
    float* currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, mainPivots);
        int mask = maskLookup[_mm_movemask_ps(comparison)];

        __m128 tmpSubPivot = subPivots[mask];
        comparison = _mm_cmpgt_ps(current, tmpSubPivot);
        mask = mask*5 + maskLookup[_mm_movemask_ps(comparison)];

        counts[mask]++;

        currentSource++;
    }
    
   
    /* Setup starting offsets and sentinels */ 
    float** offsets = (float**)malloc(sizeof(float*) * 25);
    offsets[0] = first;
    for (int i=1; i<25; i++)
    { 
        offsets[i] = offsets[i-1] + counts[i-1];
    }

    float** sentinels = (float**)malloc(sizeof(float*) * 25);
    for (int i=0; i<24; i++)
    {
        sentinels[i] = offsets[i+1];
    }
    sentinels[24] = offsets[24] + counts[24];    

    /* Second pass. Use Cycle Chasing to put items in their correct position */
    for (int i=0; i<25; i++)
    {
        float* sentinel = sentinels[i];
        float* offset = offsets[i];

        while (offset < sentinel)
            {
                __m128 current = _mm_load1_ps(offset);
                __m128 comparison = _mm_cmpgt_ps(current, mainPivots);
                int mask = maskLookup[_mm_movemask_ps(comparison)];
    
                __m128 tmpSubPivot = subPivots[mask];
                comparison = _mm_cmpgt_ps(current, tmpSubPivot);
                mask = mask*5 + maskLookup[_mm_movemask_ps(comparison)];

                if (mask != i)
                {
                    float temp = *offset;
                    float temp2;
                    float* nextOffset;
                    while (mask != i)
                    {
                        nextOffset = offsets[mask];
    
                        current = _mm_load1_ps(nextOffset);
                        temp2 = *nextOffset;
                        *nextOffset = temp;
                        temp = temp2;
                        
                        nextOffset++;
                        offsets[mask] = nextOffset;
                        
                        comparison = _mm_cmpgt_ps(current, mainPivots);
                        mask = maskLookup[_mm_movemask_ps(comparison)];
                        tmpSubPivot = subPivots[mask];
                        comparison = _mm_cmpgt_ps(current, tmpSubPivot);
                        mask = mask*5 + maskLookup[_mm_movemask_ps(comparison)];
                    }
                    *offset = temp;
                }      
                offset++;
            }
    }
    
    _mm_free(pivotsF);
    _mm_free(mainPivotsF);
    free(offsets);
    float* current = first;
    //quicksortWrapper(current,sentinels[0]);
    bucketSort_SIMD_Multilevel_InPlace_Lookup(current, sentinels[0]);
    for (int i=1; i<25; i++)
    {
        //quicksortWrapper(sentinels[i-1], sentinels[i]);
        bucketSort_SIMD_Multilevel_InPlace_Lookup(sentinels[i-1], sentinels[i]);
    }
    free(sentinels);

    
    return;
}
// Out of place with arrays, 25 partitions, lookup table for mask conversion
void bucketSort_SIMD_Multilevel_Arrays_Lookup(float* first, float* last)
{
    int length = last - first;
    
    if ( length < bucketsortThreshold )
    {
        quicksortWrapper(first,last);
        return;
    }

    float* workspace = (float*)_mm_malloc(sizeof(float) * length, 16);
    float* pivotsF = (float*)_mm_malloc(sizeof(float) * 24, 16);
    float* mainPivotsF = (float*)_mm_malloc(sizeof(float) * 4, 16);
    __m128 mainPivots;
    __m128 subPivots[5];

    int* counts = (int*)malloc(sizeof(int) * 25);
    memset(counts, 0, sizeof(int) * 25);

    int pivotStep = length / 24;

    for (int i=0; i<24; i++)
    {
        pivotsF[i] = first[pivotStep*i];
    }

    insertion_sort(pivotsF, pivotsF + 24);

    mainPivotsF[0] = pivotsF[4];
    mainPivotsF[1] = pivotsF[9];
    mainPivotsF[2] = pivotsF[14];
    mainPivotsF[3] = pivotsF[19];

    pivotsF[4] = FLT_MAX;
    pivotsF[9] = FLT_MAX;
    pivotsF[14] = FLT_MAX;
    pivotsF[19] = FLT_MAX;
    
    insertion_sort(pivotsF, pivotsF + 24);

    mainPivots = _mm_load_ps(mainPivotsF);
    
    subPivots[0] = _mm_load_ps(pivotsF);
    subPivots[1] = _mm_load_ps(pivotsF + 4);
    subPivots[2] = _mm_load_ps(pivotsF + 8);
    subPivots[3] = _mm_load_ps(pivotsF + 12);
    subPivots[4] = _mm_load_ps(pivotsF + 16);
    
    /* First pass, count number of elements that will be in each section */
    float* currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, mainPivots);
        int mask = maskLookup[_mm_movemask_ps(comparison)];

        __m128 tmpSubPivot = subPivots[mask];
        comparison = _mm_cmpgt_ps(current, tmpSubPivot);
        mask = mask*5 + maskLookup[_mm_movemask_ps(comparison)];

        counts[mask]++;
        currentSource++;
    }
    
   
    /* Setup starting offsets and sentinels */ 
    float** offsets = (float**)malloc(sizeof(float*) * 25);
    offsets[0] = workspace;
    for (int i=1; i<25; i++)
    { 
        offsets[i] = offsets[i-1] + counts[i-1];
    }

    float** partitions = (float**)malloc(sizeof(float*) * 26);
    partitions[0] = first;
    for (int i=1; i<25; i++)
    {
        partitions[i] = partitions[i-1] + counts[i-1];
    }
    partitions[25] = last;

    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, mainPivots);
        int mask = maskLookup[_mm_movemask_ps(comparison)];
        
        __m128 tmpSubPivot = subPivots[mask];
        comparison = _mm_cmpgt_ps(current, tmpSubPivot);
        mask = mask*5 + maskLookup[_mm_movemask_ps(comparison)];

        *(offsets[mask]) = *currentSource;
        offsets[mask]++;
        currentSource++;
    }

    memcpy(first, workspace, sizeof(float)*length);

    _mm_free(workspace);
    _mm_free(pivotsF);
    _mm_free(mainPivotsF);
    free(offsets);

    for (int i=0; i<25; i++)
    {
        //bucketSort_SIMD_Multilevel_Arrays_Lookup(partitions[i], partitions[i+1]);
    }
    free(partitions);
    
    return;
}

// Out of place with arrays, 25 partitions, lookup table for mask conversion
void bucketSort_SIMD_Multilevel_Lists_Lookup(float* first, float* last)
{
    int length = last - first;
    
    if ( length < bucketsortThreshold )
    {
        quicksortWrapper(first,last);
        return;
    }

    vector<float>* buckets = new vector<float>[25];
    for (int i=0; i<25; i++)
    {
        buckets[i].reserve(length/20);
    }

    float* pivotsF = (float*)_mm_malloc(sizeof(float) * 24, 16);
    float* mainPivotsF = (float*)_mm_malloc(sizeof(float) * 4, 16);
    __m128 mainPivots;
    __m128 subPivots[5];

    int pivotStep = length / 24;

    for (int i=0; i<24; i++)
    {
        pivotsF[i] = first[pivotStep*i];
    }

    insertion_sort(pivotsF, pivotsF + 24);

    mainPivotsF[0] = pivotsF[4];
    mainPivotsF[1] = pivotsF[9];
    mainPivotsF[2] = pivotsF[14];
    mainPivotsF[3] = pivotsF[19];

    pivotsF[4] = FLT_MAX;
    pivotsF[9] = FLT_MAX;
    pivotsF[14] = FLT_MAX;
    pivotsF[19] = FLT_MAX;
    
    insertion_sort(pivotsF, pivotsF + 24);

    mainPivots = _mm_load_ps(mainPivotsF);
    
    subPivots[0] = _mm_load_ps(pivotsF);
    subPivots[1] = _mm_load_ps(pivotsF + 4);
    subPivots[2] = _mm_load_ps(pivotsF + 8);
    subPivots[3] = _mm_load_ps(pivotsF + 12);
    subPivots[4] = _mm_load_ps(pivotsF + 16);
    
    /* First pass, count number of elements that will be in each section */
    float* currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, mainPivots);
        int mask = maskLookup[_mm_movemask_ps(comparison)];

        __m128 tmpSubPivot = subPivots[mask];
        comparison = _mm_cmpgt_ps(current, tmpSubPivot);
        mask = mask*5 + maskLookup[_mm_movemask_ps(comparison)];

        buckets[mask].push_back(*currentSource);
        currentSource++;
    }
    
    float** partitions = (float**)malloc(sizeof(float*) * 26);
    partitions[0] = first;
    float* current;
    for (int i=0; i<25; i++)
    {
        memcpy(current, &(buckets[i][0]), sizeof(float)*buckets[i].size());
        current += buckets[i].size();
        partitions[i+1] = current;
    }

    delete[] buckets;
    _mm_free(pivotsF);
    _mm_free(mainPivotsF);

    for (int i=0; i<25; i++)
    {
        bucketSort_SIMD_Multilevel_Lists_Lookup(partitions[i], partitions[i+1]);
    }
    free(partitions);
    
    return;
}


// In place, 25 partitions, function for mask conversion
void bucketSort6(float* first, float* last)
{
    int length = last - first;
    
    if ( length < bucketsortThreshold )
    {
        quicksortWrapper(first,last);
        return;
    }

    float* pivotsF = (float*)_mm_malloc(sizeof(float) * 24, 16);
    float* mainPivotsF = (float*)_mm_malloc(sizeof(float) * 4, 16);
    __m128 mainPivots;
    __m128 subPivots[5];
    __m128 tmp;    

    int* counts = (int*)malloc(sizeof(int) * 25);
    memset(counts, 0, sizeof(int) * 25);

    int pivotStep = length / 24;

    for (int i=0; i<24; i++)
    {
        pivotsF[i] = first[pivotStep*i];
    }

    insertion_sort(pivotsF, pivotsF + 24);

    mainPivotsF[0] = pivotsF[4];
    mainPivotsF[1] = pivotsF[9];
    mainPivotsF[2] = pivotsF[14];
    mainPivotsF[3] = pivotsF[19];

    pivotsF[4] = FLT_MAX;
    pivotsF[9] = FLT_MAX;
    pivotsF[14] = FLT_MAX;
    pivotsF[19] = FLT_MAX;
    
    insertion_sort(pivotsF, pivotsF + 24);

    mainPivots = _mm_load_ps(mainPivotsF);
    
    subPivots[0] = _mm_load_ps(pivotsF);
    subPivots[1] = _mm_load_ps(pivotsF + 4);
    subPivots[2] = _mm_load_ps(pivotsF + 8);
    subPivots[3] = _mm_load_ps(pivotsF + 12);
    subPivots[4] = _mm_load_ps(pivotsF + 16);
    
    /* First pass, count number of elements that will be in each section */
    float* currentSource = first;
    while (currentSource < last)
    {
        __m128 current = _mm_load1_ps(currentSource);
        __m128 comparison = _mm_cmpgt_ps(current, mainPivots);
        int mask = convertMask(_mm_movemask_ps(comparison));

        __m128 tmpSubPivot = subPivots[mask];
        comparison = _mm_cmpgt_ps(current, tmpSubPivot);
        mask = mask*5 + convertMask(_mm_movemask_ps(comparison));

        counts[mask]++;

        currentSource++;
    }
    
   
    /* Setup starting offsets and sentinels */ 
    float** offsets = (float**)malloc(sizeof(float*) * 25);
    offsets[0] = first;
    for (int i=1; i<25; i++)
    { 
        offsets[i] = offsets[i-1] + counts[i-1];
    }

    float** sentinels = (float**)malloc(sizeof(float*) * 25);
    for (int i=0; i<24; i++)
    {
        sentinels[i] = offsets[i+1];
    }
    sentinels[24] = offsets[24] + counts[24];    

    /* Second pass. Use Cycle Chasing to put items in their correct position */
    for (int i=0; i<25; i++)
    {
        float* sentinel = sentinels[i];
        float* offset = offsets[i];

        while (offset < sentinel)
            {
                __m128 current = _mm_load1_ps(offset);
                __m128 comparison = _mm_cmpgt_ps(current, mainPivots);
                int mask = convertMask(_mm_movemask_ps(comparison));
    
                __m128 tmpSubPivot = subPivots[mask];
                comparison = _mm_cmpgt_ps(current, tmpSubPivot);
                mask = mask*5 + convertMask(_mm_movemask_ps(comparison));

                if (mask != i)
                {
                    float temp = *offset;
                    float temp2;
                    float* nextOffset;
                    while (mask != i)
                    {
                        nextOffset = offsets[mask];
    
                        current = _mm_load1_ps(nextOffset);
                        temp2 = *nextOffset;
                        *nextOffset = temp;
                        temp = temp2;
                        
                        nextOffset++;
                        offsets[mask] = nextOffset;
                        
                        comparison = _mm_cmpgt_ps(current, mainPivots);
                        mask = convertMask(_mm_movemask_ps(comparison));
                        tmpSubPivot = subPivots[mask];
                        comparison = _mm_cmpgt_ps(current, tmpSubPivot);
                        mask = mask*5 + convertMask(_mm_movemask_ps(comparison));
                    }
                    *offset = temp;
                }      
                offset++;
            }
    }
    
    _mm_free(pivotsF);
    _mm_free(mainPivotsF);
    free(offsets);
    float* current = first;
    //quicksortWrapper(current,sentinels[0]);
    bucketSort6(current, sentinels[0]);
    for (int i=1; i<25; i++)
    {
        //quicksortWrapper(sentinels[i-1], sentinels[i]);
        bucketSort6(sentinels[i-1], sentinels[i]);
    }
    free(sentinels);

    
    return;
}

static inline int convertMask(int mask)
{
    int a = mask & 1;
    int b = (mask >> 1) & 1;
    int c = (mask >> 2) & 1;
    int d = (mask >> 3) & 1;
    return a + b + c + d;
}


bool isSorted(float* const first, float* const last)
{
    int length = last - first;
    for (int i=0; i<length-1; i++)
    {
        if (first[i] > first[i+1])
        {
            printf("%f > %f", first[i], first[i+1]);
            return false;
        }
    }
    return true;
}

bool compareArray(float* const first, int* const second, int size)
{
    for (int i=0; i<size; i++)
    {
        if (first[i] != (float)second[i])
        {
            printf("Element %d: %f != %f", i, first[i], (float)second[i]);
            return false;
        }
    }
    return true;
}

void setupBucketSort(int thresh)
{
    bucketsortThreshold = thresh;
}
void setupScalarBucketSort(int pivots)
{
    numBuckets = pivots + 1;
}
