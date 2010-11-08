// Copyright 2007, Tim Furtak
// Distributed under the GNU Lesser General Public License

#ifndef RSORT_AS_H
#define RSORT_AS_H

#include <xmmintrin.h>
#include <stdio.h>
#include <stdint.h>

typedef void(*RegSort_AlignedSmart_FuncPtr)(float* first, int firstElements, int lastElements);

extern RegSort_AlignedSmart_FuncPtr rsort_as_ptrs[13]; 

extern uint32_t startMask[16];
extern uint32_t endMask[16];
extern uint32_t startBlendMask[16];
extern uint32_t endBlendMask[16];
extern __m128 plusInf;
extern __m128 minusInf;

inline void rsort_as(float* first, float* last)
{
	int length = last - first;
	if (length <= 1)
		return;
	
	// (Length - 1) -> 1,2,3,4 map to rsort_1
	float* alignedFirst = reinterpret_cast<float*>((long)first & 0xFFFFFFFFFFFFFFF0);
	float* alignedLast = reinterpret_cast<float*>((long)(last + 3) & 0xFFFFFFFFFFFFFFF0);
	int firstElements = (alignedFirst + 4) - first;
	int lastElements = (last - (alignedLast - 4)) % 4;

	rsort_as_ptrs[((alignedLast - alignedFirst) - 4) / 4](alignedFirst, firstElements, lastElements);
    return;
}

#endif
