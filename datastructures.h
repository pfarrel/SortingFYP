#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include "timer.h"
#include <string>
#include <vector>

struct qs_params
{
	int thread_depth;
	int MAX_THREAD_DEPTH;
	timer* t;
	float* first;
	float* last;
};

struct partition_params
{
	float* first;
	float* last;
	float pivot;
	float* mid;
};

struct merge_params
{
	int from;
	int to;
	int* sslength;
	float** bound;
	float* moffsets;
	float* out;
	int p;
	int threadnum;
};

typedef void(*Sort_FuncPtr)(float*,float*);

struct smallAlgorithm
{
    Sort_FuncPtr function;
    int maxSize;
    std::string name;
    std::vector<long long> times;
};

#endif
