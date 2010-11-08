#ifndef MASKS_H
#define MASKS_H

#include <float.h>
#include <stdint.h>

__declspec(align(16)) uint32_t startMask[16] =
                     {0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
                      0,0,0,0xFFFFFFFF,
                      0,0,0xFFFFFFFF,0xFFFFFFFF,
                      0,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF};

__declspec(align(16)) uint32_t endMask[16] =
                     {0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
                      0xFFFFFFFF,0,0,0,
                      0xFFFFFFFF,0xFFFFFFFF,0,0,
                      0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0};

__declspec(align(16)) uint32_t startBlendMask[16] =
                     {0,0,0,0,
                      0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0,
                      0xFFFFFFFF,0xFFFFFFFF,0,0,
                      0xFFFFFFFF,0,0,0};

__declspec(align(16)) uint32_t endBlendMask[16] =
                     {0,0,0,0,
                      0,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
                      0,0,0xFFFFFFFF,0xFFFFFFFF,
                      0,0,0,0xFFFFFFFF};

__m128 plusInf = _mm_set1_ps(FLT_MAX);
__m128 minusInf = _mm_set1_ps(FLT_MIN);
#endif
