#include <stdio.h>
#include <stdlib.h>

#include "payload.h"

//void destroypayload(struct payload* pl);
//struct payload* readFile(char fn[]);
//struct payload* readFile2(char fn[]);
/*
class payload
{
	public:
		int* k;
		int count;

		payload();
		payload(char fn[]);
		payload(int s);
		~payload();
		void readFile(char fn[]);
		void readFile2(char fn[]);
		void print();
		bool checksorted(bool verbose);
};
*/

// simply create an empty payload
payload::payload()
{
	k = NULL;
	count = 0;
}

// create a preallocated payload
payload::payload(int s)
{
	count = s;
	k = (int*)malloc(4*count);
	srand(0);
	int i;
	for(i = 0; i < count; i++)
		k[i] = random();
//		k[i] = rand();
}

// create a payload, but then read from a file
payload::payload(char fn[])
{
	readFile(fn);
}

// destructor
payload::~payload()
{
	free(k);
}

void payload::readFile(char fn[])
{
	FILE* bfile = fopen(fn, "rb");
    if(bfile == NULL)
    {
    	printf("Could not open file, aborting...\n");
        exit(1);
    }

    // get the key count and malloc the keys array
    k = (int*)malloc(sizeof(int));
    int val = fread(k, 4, 1, bfile);
    count = *k;
    free(k);
//    printf("keys = %d\n", count);

    // read the file into memory
    k = (int*)malloc(sizeof(int)*count);
    val = fread(k, sizeof(int), count, bfile);

    fclose(bfile);
}

// some test values, useful for debugging
void payload::readFile2(char fn[])
{
        count = 32;

        // read the file into memory
        k = (int*)malloc(sizeof(int)*count);

   //   int k1[] = {-1,-2,-3,9,8,7,6,5,4,3,2,1,-4,-5,-6,-7};
    int k1[] = {1,3,5,7,9,11,13,15,2,4,6,8,10,12,14,16,1,3,5,7,9,11,13,15,2,4,6,8,10,12,14,16};
   // int k1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

        for(int i = 0; i < count; i++)
        	k[i] = k1[i];
}

bool payload::checksorted(bool verbose)
{
	int i;
	for(i = 0; i < count - 1; i++)
		if(k[i] > k[i+1])
		{
			if(verbose)
			{
				printf("Keys sorted: No\n");
				printf("tested: %d -> %d > %d -> %d\n", i, k[i], i+1, k[i+1]);
				
//				if(i >= 5 && i+10 < count)
//					for(j = i-5; j<i+10; j++)
//						printf("%d -> %d\n", j, k[j]);
			}
			return false;
		}
	if(verbose)
		printf("Keys sorted: Yes\n");
	return true;
}

void payload::print()
{
	int i;
	for(i = 0; i  < count; i++)
//	if(k[i] < 0)
		printf("key %d -> %d\n", i, k[i]);
}

