#include "shell.h"

void shell_sort(int* first, int* last)
{
	int i, j, increment, temp;
	int count = last-first;
	increment = count / 2;	// initial increment is half the length of the array

	while (increment > 0)
	{
		for (i = increment; i < count; i++) 
		{
			j = i;
			temp = first[i];
			while ((j >= increment) && (first[j-increment] > temp)) 
			{
				first[j] = first[j - increment];
				j -= increment;
			}
			first[j] = temp;
		}

		// essentially falling back to standard insertion sort
		if (increment == 2)
			increment = 1;

		// reduce increment by a factor of X each time
		else 
			increment = (int)(increment / 2.2);
	}
}

void shell_sort2(int* first, int* last)
{
	int l = 0;
	int r = last-first-1;
	int i, h; 

	for (h = r-l+1; h > 0; h = ((h > 1) && (h < 5)) ? 1 : 5*h/11)
	{
		for (i = l+h; i <= r; i++)
		{
			int j = i; 
			int v = first[i]; 
			while (j >= l+h && (v < first[j-h]))
			{ 
				first[j] = first[j-h]; 
				j -= h; 
			}
			first[j] = v; 
		}
	}
}

void shell_sort3(int* first, int* last)
{
	if (last - first <= 1)
        return;
    int i, h,min, bound; 
	int N = last - first;

	for (h = 5*N/11; h >= 5; h = 5*h/11)
	{
		for (i = h; i <= N-1; i++)
		{
			int j = i; 
			int v = first[i]; 
			while (j >= h && v < first[j-h])
			{ 
				first[j] = first[j-h]; 
				j -= h; 
			}
			first[j] = v; 
		}
	}

	/* put a sentinel in place */
	/* the sentinel will be in the first h positions */
	/* for h to be below 5, it must have been less than 11 beforehand */
	min = 0;
	bound = 11;
	if (N < bound) bound = N;

	for(i = 1; i < bound; i++)
	{
		if(first[i] < first[min])
		{
			min = i;
		}
	}
	
	int temp = first[0];
	first[0] = first[min];
	first[min] = temp;


	for(i = 1; i < N; i++)
	{
		int j = i;
		int v = first[i];

		while(v < first[j-1])
		{
			first[j] = first[j-1];
			j--;
		}
		first[j] = v;
	}
}

