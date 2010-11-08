#include <string.h>		// for memmove
#include "insertion.h"

void insertion_sort(float* first, float* last)
{
        if (last - first <= 1)
                return;

        for (float* i = first + 1; i != last; ++i)
        {
                float val = *i;

                // if i needs to be inserted at the beginning, ripple
                // already sorted values 1 to the right
                if (val < *first)
                {
                        const int Num = i - first;
                        memmove(i+1 - Num, first, sizeof(float) * Num);

                        *first = val;
                }
                else
                {
                        float* last2 = i;

                        float* next = last2;
                        --next;
                        while (val < *next)
                        {
                                *last2 = *next;
                                last2 = next;
                                --next;
                        }
                        *last2 = val;
                }
        }
}

void insertion_sort2(float* first, float* last)
{
	int i, j, index;

	for (i=1; i < last - first; i++)
	{
		index = first[i];
		j = i;
		while ((j > 0) && (first[j-1] > index))
		{
			first[j] = first[j-1];
			j = j - 1;
		}
		first[j] = index;
	}
}

