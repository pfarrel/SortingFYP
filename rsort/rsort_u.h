// Copyright 2007, Tim Furtak
// Distributed under the GNU Lesser General Public License

#ifndef RSORT_U_H
#define RSORT_U_H

#include <xmmintrin.h>

typedef void(*RegSort_Unaligned_FuncPtr)(float*);

extern RegSort_Unaligned_FuncPtr rsort_u_ptrs[13]; 

inline void rsort_u(float* first, float* last)
{
    int length = last - first;
    if (length <= 1)
        return;
    length = (length - 1) / 4;
    rsort_u_ptrs[length](first);
}

void rsort_u_1(float* first);
void rsort_u_2(float* first);
void rsort_u_3(float* first);
void rsort_u_4(float* first);
void rsort_u_5(float* first);
void rsort_u_6(float* first);
void rsort_u_7(float* first);
void rsort_u_8(float* first);
void rsort_u_9(float* first);
void rsort_u_10(float* first);
void rsort_u_11(float* first);
void rsort_u_12(float* first);
void rsort_u_13(float* first);

#endif
