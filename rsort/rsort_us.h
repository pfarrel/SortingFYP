// Copyright 2007, Tim Furtak
// Distributed under the GNU Lesser General Public License

#ifndef RSORT_US_H
#define RSORT_US_H

#include <xmmintrin.h>
#include <stdio.h>
#include <stdint.h>

typedef void(*RegSort_UnalignedSmart_FuncPtr)(float* first, int lastVectorCount);

extern RegSort_UnalignedSmart_FuncPtr rsort_us_ptrs[13];

extern uint32_t startMask[16];
extern uint32_t endMask[16];
extern uint32_t startBlendMask[16];
extern uint32_t endBlendMask[16];
extern __m128 plusInf; 
extern __m128 minusInf;

inline void rsort_us(float* first, float* last)
{
	int length = last - first;
	if (length <= 1)
		return;
	
	// (Length - 1) -> 1,2,3,4 map to rsort_1
	rsort_us_ptrs[(length - 1) / 4](first, length);
    return;
}

#endif
