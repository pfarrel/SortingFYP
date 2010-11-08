// Copyright 2007, Tim Furtak
// Distributed under the GNU Lesser General Public License

#ifndef RSORT_A_H
#define RSORT_A_H

#include <xmmintrin.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef void(*RegSort_Aligned_FuncPtr)(float* first);

extern RegSort_Aligned_FuncPtr rsort_a_ptrs[13];

inline void rsort_a(float *first, float* last)
{
    if (last - first <= 1)
        return;
    first =  reinterpret_cast<float*>((long)first & 0xFFFFFFFFFFFFFFF0);
    last = reinterpret_cast<float*>((long)(last + 3) & 0xFFFFFFFFFFFFFFF0);
    int length = (last - first - 1) / 4;
    rsort_a_ptrs[length](first);
}

void rsort_a_1 (float* first);
void rsort_a_2 (float* first);
void rsort_a_3 (float* first);
void rsort_a_4 (float* first);
void rsort_a_5 (float* first);
void rsort_a_6 (float* first);
void rsort_a_7 (float* first);
void rsort_a_8 (float* first);
void rsort_a_9 (float* first);
void rsort_a_10 (float* first);
void rsort_a_11 (float* first);
void rsort_a_12 (float* first);
void rsort_a_13 (float* first);

#endif
