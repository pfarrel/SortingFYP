#include "psrs.h"
#include "datastructures.h"
#include "quicksort.h"

void PSRS(float* first, float* last, const int p)
{
        int size = last - first;
        int i,j;
        float* left[p];
        float* right[p];
        int per_thread = size/p;

        for(i = 0; i < p; i++)
        {
                left[i] = first + i*(size/p);
                right[i] = first + (i+1)*(size/p);
        }
        right[p-1] = last;      // account for unevenly sized arrays

        // sort the thread partitions
#pragma omp parallel for num_threads(p) schedule(static, 1)
        for(i = 0; i < p; i++)
        {
            quicksortWrapper(left[i], right[i]);
        } // HARD BARRIER


        float* temp = (float*)malloc((last-first) * sizeof(float));

        // evenly spaced samples from the sorted segments
        float samples[p*p*2];
        for(i = 0; i < p*p*2; i++)
                samples[i] = -1;

//#pragma omp parallel for num_threads(p) schedule(static, 1)
        for(i = 0; i < p; i++)
        {
                // first and last of the partition associated with the current processor
                // again this is necessary for dealing with irrelgularly sized payloads
                samples[i*p*2] = left[i][0];
                samples[(i+1)*p*2 - 1] = left[i][per_thread-1];

                // evenly spaced pivots before and after ideal partition boundaries within the processor's partition
                for(j = 1; j < p; j++)
                {
                        samples[i*p*2 + j*2 - 1] = left[i][(per_thread/p)*j - 1];
                        samples[i*p*2 + j*2] = left[i][(per_thread/p)*j];
                }
        }

        insertion_sort(&samples[0], &samples[0] + (p*p*2));


        // Select evenly spaced pivots from the sorted sample
        float pivots[p-1];

        for(i = 0; i < p-1; i++)
                pivots[i] = samples[(i+1)*p*2-1];

//        for(i = 0; i < p-1; i++)
//                printf("%d, ", pivots[i]);
//        printf(" (pivots)\n\n");


        float* bound[p*(p+1)];

        // locate boundaries
//#pragma omp parallel for num_threads(p)  schedule(static, 1)
        for(i = 0; i < p; i++)
        {
                // fill in first and last
                bound[i*(p+1)] = left[i];
                bound[(i+1)*(p+1) - 1] = right[i];

                int size = right[i] - left[i];

                for(j = 0; j < p-1; j++)
                {
                        // guess where the pivot might go
                        float* loc = left[i] + ((size*j) / p);

                        // sweep around until actual point is found
                        while(*loc > pivots[j] && loc > left[i])
                                loc--;
                        while(*loc <= pivots[j] && loc < right[i])
                                loc++;

                        bound[i*(p+1) + j + 1] = loc;
                }
        }


        // we now have each thread's partition bounded by left[threadnum] and right[threadnum]
        // and itself partitioned around num_threads-1 pivots, boundaries stored in
        // bound[num_threads*threadnum] to bound[(num_threads+1) * threadnum - 1]

        // merging range offsets, and subsection lengths
        int moffsets[p+1];
        int sslength[p*p];

        // calculate writeback offsets for merge
//#pragma omp parallel for num_threads(p) schedule(static, 1)
        for(i = 0; i < p+1; i++)        // each thread
        {
                moffsets[i] = 0;
                for(j = 0; j < p; j++) // section inside thread
                {
                        moffsets[i] += (bound[j*(p+1) + i] - bound[j*(p+1)]);

                        if(i < p)
                                sslength[i*p + j] = bound[i*(p+1) + j + 1] - bound[i*(p+1) + j];
                }
        }


        merge_params mp[p];
        pthread_t pth[p];

        // thread creation
        for(i = 0; i < p; i++)
        {
                mp[i].out = temp + moffsets[i];
                mp[i].from = moffsets[i];
                mp[i].to = moffsets[i+1];
                mp[i].bound = bound;
                mp[i].threadnum = i;
                mp[i].p = p;
                mp[i].sslength = (int*)malloc(sizeof(int)*p);
                mp[i].bound = (float**)malloc(sizeof(float*)*p*(p+1));
                for(j = 0; j < p; j++)
                        mp[i].sslength[j] = sslength[j*p + i];
                for(j = 0; j < p*(p+1); j++)
                        mp[i].bound[j] = bound[j];

                pthread_create(&pth[i], NULL, &mergefunc, (void*)&mp[i]);
        }

        for(i = 0; i < p; i++)
                pthread_join(pth[i], NULL);

// merge subsections
// thread n merges subsection n from each processor's allocated section


        memcpy(first, temp, size*sizeof(int));
        free(temp);
}


void* mergefunc(void* mp1)
{
        merge_params* mp = (merge_params*)mp1;

        // copying these variables results in a small speedup due to caching behaviour
        // on many machines
        int outindex;
        float* out = mp->out;
        int outcount = 0;
        float** bound = mp->bound;
        int sslength[mp->p] __attribute__((aligned(16)));
    
        for(int z = 0; z < mp->p; z++)
            sslength[z]  = mp->sslength[z];

        int p = mp->p;
        int i = mp->threadnum;

        for(outindex = mp->from; outindex < mp->to; outindex++)
        {
                int k = 0;          // which thread is the key getting taken from?
                int smallest = 0;   // smallest key so far

                // take the first from first non empty list
                while(k < p)
                {
                        if(sslength[k] > 0)
                        {
                                smallest = k++;
                                break;
                        }
                        k++;
                }

                // compare to all following ones
                while(k < p)
                {
                        if(sslength[k] > 0)
                                if(*bound[k*(p+1) + i] < *bound[smallest*(p+1) + i])
                                        smallest = k;

                        k++;
                }

                out[outcount++] = *bound[smallest*(p+1)+i]++;
                sslength[smallest]--;
        }

    return NULL;
}
