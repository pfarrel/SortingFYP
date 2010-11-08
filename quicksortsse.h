#ifndef QUICKSORTSSE_H
#define QUICKSORTSSE_H

void bucketsort_Scalar_Lists(float*, float*);
void bucketsort_Scalar_Arrays(float*, float*);
void bucketsort_Scalar_InPlace(float*, float*);
void bucketsort_SIMD_Arrays_Sparse(float*, float*);
void bucketsort_SIMD_Lists_Sparse(float*, float*);
void bucketSort_SIMD_InPlace_Sparse(float*, float*);
void bucketSort_SIMD_Multilevel_InPlace_Lookup(float*, float*);
void bucketSort_SIMD_Multilevel_Lists_Lookup(float*, float*);
void bucketSort_SIMD_Multilevel_Arrays_Lookup(float*, float*);
void bucketSort6(float*, float*);
bool isSorted(float* const, float* const);
bool compareArray(float* const, int* const, int);
void setupBucketSort(int);
void setupScalarBucketSort(int);
static inline int convertMask(int);

#endif
