#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <float.h>
#include <iostream>
#include "sse.h"
#include "sortingnetwork.h"
#include "rsort/rsort_a.h"
#include "sortingnetworkSSE.h"
#include "insertion.h"
#include "timer.h"
#include "psrs.h"
#include "mergesort.h"

using namespace std;

#define COMP(a, b, t); t=a;a=min(a,b);b=max(t,b);
#define _MM_BLEND(a,b,c,d) d<<3|c<<2|b<<1|a
#define SHUF_REVERSE 0x1B

// No cache awareness
void mergeSort(float* first, float* last)
{
    int length = last - first;

    //printf("%d", length);
    float* buffer = (float*)malloc(sizeof(float) * length);

    for (float* current = first; current < last; current += 32)
    {
        oddEven16(current);
        oddEven16(current + 16);
        bitonicKernel4b4(current);
        bitonicKernel4b4(current + 8);
        bitonicKernel4b4(current + 16);
        bitonicKernel4b4(current + 24);
        bitonicKernel8b8(current);
        bitonicKernel8b8(current + 16); 
    }

    float* input = first;
    float* output = buffer;
    float* temp;
    for (int currentSize = 32; currentSize <= length; currentSize *= 2)
    {
        float* currentInput = input;
        float* currentOutput = output;
        while (currentInput < input + length)
        {
            //printf("\nmerging\n");
            mergeSort_merge(currentOutput, currentInput, currentSize);
            currentInput += currentSize;
            currentOutput += currentSize;
        }

        /* Flip Flop between input and output arrays */
        temp = input;
        input = output;
        output = temp;
    }

    if (output == first)
    {
        memcpy(first,buffer,sizeof(float)*length);
    }
    free(buffer);
    return;
}

// No cache awareness
void mergeSort_rsort(float* first, float* last)
{
    int length = last - first;

    //printf("%d", length);
    float* buffer = (float*)_mm_malloc(sizeof(float) * length,16);

    for (float* current = first; current < last; current += 32)
    {
        rsort_a_8(current);
    }
    
    float* input = first;
    float* output = buffer;
    float* temp;
    for (int currentSize = 64; currentSize <= length; currentSize *= 2)
    {
        float* currentInput = input;
        float* currentOutput = output;
        while (currentInput < input + length)
        {
            //printf("\nmerging\n");
            mergeSort_merge(currentOutput, currentInput, currentSize);
            currentInput += currentSize;
            currentOutput += currentSize;
        }
               
        /* Flip Flop between input and output arrays */
        temp = input;
        input = output;
        output = temp;
    }

    if (output == first)
    {
        //printf("\nOutput was to buffer. memcpying\n");
        memcpy(first,buffer,sizeof(float)*length);
    }
    _mm_free(buffer);
    return;
}

void mergeSort_Serial(float* first, float* last)
{
    int length = last - first;

    //printf("%d", length);
    float* buffer = (float*)_mm_malloc(sizeof(float) * length,16);

    for (float* current = first; current < last; current += 256)
    {
        insertion_sort(current, current+ 256);
    }

    float* input = first;
    float* output = buffer;
    float* temp;
    for (int currentSize = 512; currentSize <= length; currentSize *= 2)
    {
        float* currentInput = input;
        float* currentOutput = output;
        while (currentInput < input + length)
        {
            //printf("\nmerging\n");
            mergeSort_mergeSerial(currentOutput, currentInput, currentSize);
            currentInput += currentSize;
            currentOutput += currentSize;
        }

        /* Flip Flop between input and output arrays */
        temp = input;
        input = output;
        output = temp;
    }

    if (output == first)
    {
        //printf("\nOutput was to buffer. memcpying\n");
        memcpy(first,buffer,sizeof(float)*length);
    }
    _mm_free(buffer);
    return;
}

// Works in blockSize number of key chunks at a time for cache awareness
void mergeSort_CacheAware(float* first, float* last, int blockSize)
{
    int length = last - first;

    float* buffer = (float*)_mm_malloc(sizeof(float) * length,16);

    blockSize = blockSize < length ? blockSize : length;

    float* input = first;
    float* output = buffer;
    float* temp;
    int inPlace;

    while (input < last)
    {
        for (float* current = input; current < input + blockSize; current += 32)
        {
            //printf("Doing a 32 element Reg Sort\n");
            rsort_a_8(current);
        }
        inPlace = mergeSortInner(input, input+ blockSize, output, 64);
        input += blockSize;
        output += blockSize;
    }

    if (blockSize < length)
    {
        if (inPlace)
        {
            //printf("Doing final merge + memcpy\n");
            mergeSortInner(first, last, buffer, blockSize);
            memcpy(first,buffer,sizeof(float) * length);
        }
        else
        {
            //printf("Doing final merge\n");
            mergeSortInner(buffer, buffer+length, first, blockSize);
        }
    }
    else if (!inPlace)
    {
        //printf("Copying from buffer to memory");
        memcpy(first,buffer, sizeof(float) * length);
    }
    _mm_free(buffer);
    return;
}

/* Merge lists arranged sequentially in memory, from size startSize and up */
int mergeSortInner(float* first, float* last, float* dest, int startSize)
{
    int length = last - first;

    float* input = first;
    float* output = dest;
    float* temp;
    for (int currentSize = startSize; currentSize <= length; currentSize *= 2)
    {
        float* currentInput = input;
        float* currentOutput = output;
        while (currentInput < input + length)
        {
            //printf("\nmerging\n");
            //printf("Merging from %d, size %d\n",currentInput, currentSize);
            mergeSort_merge16(currentOutput, currentInput, currentSize);
            currentInput += currentSize;
            currentOutput += currentSize;
        }

        /* Flip Flop between input and output arrays */
        temp = input;
        input = output;
        output = temp;
    }

    // If output is now pointing at first, then output is in the buffer */
    if (output != first)
        return 1;
    else    
        return 0;
}

// Works in blockSize number of key chunks at a time for cache awareness
/*void mergeSort_Parallel(float* first, float* last, int blockSize)
{
    int length = last - first;

    float* buffer = (float*)_mm_malloc(sizeof(float) * length,16);

    blockSize = blockSize < length ? blockSize : length;

    float* input = first;
    float* output = buffer;
    float* temp;
    int inPlace;

    for(int i=0; i<length; i+= blockSize)
    {
        for (int j=0; float* current = &input[i]; current < input + blockSize; current += 32)
        {
            rsort_a_8(current);
        }
        inPlace = mergeSortInner(input, input+ blockSize, output, 64);
        input += blockSize;
        output += blockSize;
    }

    if (blockSize < length)
    {
        if (inPlace)
        {
            mergeSortInner(first, last, buffer, blockSize);
            memcpy(first,buffer,sizeof(float) * length);
        }
        else
        {
            mergeSortInner(buffer, buffer+length, first, blockSize);
        }
    }
    else if (!inPlace)
    {
        memcpy(first,buffer, sizeof(float) * length);
    }
    _mm_free(buffer);
    return;
}
*/


static void oddEven16(float* keys)
{
	__m128 a,b,c,d;
	a = load(keys);
	b = load(&keys[4]);
	c = load(&keys[8]);
	d = load(&keys[12]);

    oddEven16(&a,&b,&c,&d);

	store(keys,a);
	store(&keys[4],b);
	store(&keys[8],c);
	store(&keys[12],d);
}

static void inline oddEven16(__m128 *a, __m128 *b, __m128 *c, __m128 *d)
{
	__m128 t1,t2;
    
    t1 = *a;
	*a = min(*a,*b);
	*b = max(t1,*b);
	
    t2 = *c;
    *c = min(*c,*d);
    *d = max(t2,*d);

    t1 = *a;
	*a = min(*a,*c);
	*c = max(t1,*c);

    t2 = *b;
	*b = min(*b,*d);
	*d = max(t2,*d);

    t1 = *b;
	*b = min(*b,*c);
	*c = max(t1,*c);
    transpose(*a,*b,*c,*d);
}

static void bitonicKernel4b4(float* keys)
{
	__m128 a,b;
	a = load(keys);
	b = load(&keys[4]);
	
    bitonicKernel4b4(&a, &b);	

	store(keys,a);
	store(&keys[4],b);
}

static void inline bitonicKernel4b4(__m128 *a, __m128 *b)
{
	__m128 t1;
	//Level 1
	*b = shuffle(*b,*b,SHUFFLE(3,2,1,0));

	t1 = min(*a,*b);
	*b = max(*a,*b);

	//Level 2
	*a = movelh(t1,*b);
	*b = movehl(*b,t1);

	t1 = min(*a,*b);
	*b = max(*a,*b);

	//Level 3
	
	*a = blend(t1,*b,BLEND(0,1,0,1));
	*b = blend(t1,*b,BLEND(1,0,1,0));
	*b = shuffle(*b,*b,SHUFFLE(1,0,3,2));

	t1 = min(*a,*b);
	*b = max(*a,*b);
		
	//Final
	*a = unpacklo(t1,*b);
	*b = unpackhi(t1,*b);
}

/* Don't reverse second list first */
static void inline bitonicKernel4b4nr(__m128 *a, __m128 *b)
{
    __m128 t1;
    //Level 1
    
    t1 = min(*a,*b);
    *b = max(*a,*b);

    //Level 2
    *a = movelh(t1,*b);
    *b = movehl(*b,t1);

    t1 = min(*a,*b);
    *b = max(*a,*b);
    
    //Level 3
    *a = blend(t1,*b,BLEND(0,1,0,1));
    *b = blend(t1,*b,BLEND(1,0,1,0));
    *b = shuffle(*b,*b,SHUFFLE(1,0,3,2));

    t1 = min(*a,*b);
    *b = max(*a,*b);
    *a = t1;
    //Final
    *a = unpacklo(t1,*b);
    *b = unpackhi(t1,*b);
}


/* Merge two sorted 8 element lists positioned sequenitally in memory */
void bitonicKernel8b8(float* keys)
{
	__m128 a,b,c,d,t1,t2;
    a = load(keys);
    b = load(&keys[4]);
    c = load(&keys[8]);
    d = load(&keys[12]);

    bitonicKernel8b8(&a,&b,&c,&d);	

	store(keys,a);
    store(&keys[4],b);
	store(&keys[8],c);
	store(&keys[12],d);
}

/* Merge two sorted 8 element lists */
void bitonicKernel8b8(__m128 *a, __m128 *b, __m128 *c, __m128 *d)
{
    __m128 t1,t2;

    //Level 1
    *c = shuffle(*c,*c,SHUFFLE(3,2,1,0));
    *d = shuffle(*d,*d,SHUFFLE(3,2,1,0));

    // c and d reversed by shuffle above
    COMP(*a,*d,t1);
    COMP(*b,*c,t2);

    bitonicKernel4b4nr(a,c);
    bitonicKernel4b4nr(c,d);
}  

/* Reverse the 4 parameters */
static void reverse4regs(__m128 &a, __m128 &b, __m128 &c, __m128 &d)
{
    a = shuffle(a,a,SHUF_REVERSE);
    b = shuffle(b,b,SHUF_REVERSE);
    c = shuffle(c,c,SHUF_REVERSE);
    d = shuffle(d,d,SHUF_REVERSE);
}

/* Merge two sorted 16 element lists, positioned sequentially in memory */
static void bitonicKernel16b16(float *keys)
{
    __m128 a,b,c,d,e,f,g,h;
    a = load(keys);
    b = load(keys + 4);
    c = load(keys + 8);
    d = load(keys + 12);
    e = load(keys + 16);
    f = load(keys + 20);
    g = load(keys + 24);
    h = load(keys + 28);
    
    /* Reverse the registers, then call with first list reversed */
    reverse4regs(a,b,c,d);
    
    bitonicKernel16b16nr(d,c,b,a,e,f,g,h);

    /* Write back d,c,b,a because they are reversed */
    store(keys, d);
    store(keys + 4, c);
    store(keys + 8, b);
    store(keys + 12, a);
    store(keys + 16, e);
    store(keys + 20, f);
    store(keys + 24, g);
    store(keys + 28, h);
}


/* Merge two sorted 16 element lists. One list must be in reverse order */
static void bitonicKernel16b16nr(__m128 &a, __m128 &b, __m128 &c, __m128 &d,
                        __m128 &e, __m128 &f, __m128 &g, __m128 &h)
{
    __m128 t1,t2,t3,t4;

    /* Level 1 */
    COMP(a,e,t1);
    COMP(b,f,t2);
    COMP(c,g,t3);
    COMP(d,h,t4);

    /* Level 2*/
    COMP(a,c,t1);
    COMP(b,d,t2);
    COMP(e,g,t3);
    COMP(f,h,t4);

    /* Simply 4 4x4 merges */
    bitonicKernel4b4nr(&a,&b);
    bitonicKernel4b4nr(&c,&d);
    bitonicKernel4b4nr(&e,&f);
    bitonicKernel4b4nr(&g,&h);
}

static void mergeSort_merge(float* output, float *input, int length)
{
    int half;
    float *halfptr;
    float *sentinelptr;

    half = length / 2;
    halfptr = input + half;
    sentinelptr = input + length;

    __m128 x, y, z;
    float *list1 = input;
    float *list2 = halfptr;
    x = load(list1);
    y = load(list2);
    list1 += 4;
    list2 += 4;
    bitonicKernel4b4(&x, &y);
    store(output, x);
    output += 4;
    
    while ((list1 < halfptr) && (list2 < sentinelptr))
    {
        if (*list1 < *list2)
        {
            x = load(list1);
            list1 += 4;
        }
        else
        {
            x = load(list2);
            list2 += 4;
        }
        bitonicKernel4b4(&x, &y);
        store(output, x);
        output += 4;
    }
    while (list1 < halfptr)
    {
        x = load(list1);
        list1 += 4;
        bitonicKernel4b4(&x, &y);
        store(output, x);
        output += 4;
    }
    while (list2 < sentinelptr)
    {
        x = load(list2);
        list2 += 4;
        bitonicKernel4b4(&x, &y);
        store(output, x);
        output += 4;
    }
    store(output, y);
}

static void mergeSort_merge16(float* output, float* input, int length)
{
    float *halfptr;
    float *sentinelptr;

    halfptr = input + (length/2);
    sentinelptr = input + length;

    __m128 a,b,c,d,e,f,g,h;

    float *list1 = input;
    float *list2 = halfptr;
    
    d = load(list1);
    c = load(list1 + 4);
    b = load(list1 + 8);
    a = load(list1 + 12);
    list1 += 16;
    
    e = load(list2);
    f = load(list2 + 4);
    g = load(list2 + 8);
    h = load(list2 + 12);
    list2 += 16;

    reverse4regs(a,b,c,d);
    bitonicKernel16b16nr(a,b,c,d,e,f,g,h);
    store(output, a);
    store(output + 4, b);
    store(output + 8, c);
    store(output + 12, d);
    output += 16;

    while ((list1 < halfptr) && (list2 < sentinelptr))
    {
        if (*list1 < *list2)
        {
            //printf("Going first list\n%f < %f\n",*list1, *list2);
            d = load(list1);
            c = load(list1 + 4);
            b = load(list1 + 8);
            a = load(list1 + 12);
            list1 += 16;
        }
        else
        {
            //printf("Going second list\n");
            d = load(list2);
            c = load(list2 + 4);
            b = load(list2 + 8);
            a = load(list2 + 12);
            list2 += 16;
        }
        reverse4regs(a,b,c,d);
        bitonicKernel16b16nr(a,b,c,d,e,f,g,h);
        store(output, a);
        store(output + 4, b);
        store(output + 8, c);
        store(output + 12, d);
        output += 16;
    }
    while (list1 < halfptr)
    {
        //printf("Finishing first list\n");
        d = load(list1);
        c = load(list1 + 4);
        b = load(list1 + 8);
        a = load(list1 + 12);
        list1 += 16;

        reverse4regs(a,b,c,d);
        bitonicKernel16b16nr(a,b,c,d,e,f,g,h);
        store(output, a);
        store(output + 4, b);
        store(output + 8, c);
        store(output + 12, d);
        output += 16;
    }
    while (list2 < sentinelptr)
    {
        //printf("Finishing second list\n");
        d = load(list2);
        c = load(list2 + 4);
        b = load(list2 + 8);
        a = load(list2 + 12);
        list2 += 16;

        reverse4regs(a,b,c,d);
        bitonicKernel16b16nr(a,b,c,d,e,f,g,h);
        store(output, a);
        store(output + 4, b);
        store(output + 8, c);
        store(output + 12, d);
        output += 16;
    }
    store(output, e);
    store(output + 4, f);
    store(output + 8, g);
    store(output + 12, h);
}

void mergeSort_mergeSerial(float* output, float* input, int length)
{
    int half = length /2;
    float* halfptr = input + half;
    float* sentinel = input + length;

    float* list1 = input;
    float* list2 = halfptr;

    while ((list1 < halfptr) && list2 < sentinel)
    {
        if (*list1 < *list2)
        {
            *output++ = *list1++;
        }
        else
        {
            *output++ = *list2++;
        }
    }
    while (list1 < halfptr)
    {
        *output++ = *list1++;
    }
    while (list2 < sentinel)
    {
        *output++ = *list2++;
    }
}
