#ifndef __MISC_RADIX_H

#define __MISC_RADIX_H

void radix_int_thresh2(int* a, int n);
void radix_int_thresh2_omp(int* a, int n, int p);
void radix_int_thresh2_recurse(int* a, int n, int bit_depth);
void radix_int_thresh2_recurse_omp(int* a, int n, int bit_depth, int p);

void radix_4(int* a, int n, int bit_depth);
void radix_8(int* a, int n, int bit_depth);
void radix_16(int* a, int n, int bit_depth);

void* split_radix(void* qsp1);
void* radix_thread(void* qsp1);

#endif
