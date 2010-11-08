#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "datastructures.h"

void setupQuicksort(int numPivots, int maxThreadDepth, int threshold, Sort_FuncPtr sortfunc);

void quicksortWrapper(float*, float*);
void quicksortLoop(float*, float*);

static inline const float& median3(const float&, const float&, const float&);
static inline void qsSwap(float*, float*);
float* unguardedPartition(float*, float*, const float);

int checkPartitioned(const float*, const float*, const float*, float);
float* parallelPartition(void* qsp1);
void* partitionThread(void* pp1);
float medianX(const float*,const float* last, const int num);

void* splitQuick(void* qsp1);
void* qsThread(void* qsp1);
#endif
