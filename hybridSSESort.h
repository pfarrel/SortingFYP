#ifndef HYBRIDSSESORT_H
#define HYBRIDSSESORT_H
#include <vector>
#include "datastructures.h"

void generateQuicksort();
void generateSSEQuicksort();

void tuneSplit();
void tunePSRS(Sort_FuncPtr);

float singleSplitTest(char fn[], int depth, int alg);
float singlePSRS(char fn[], int p, int alg);

void setupSmalllgorithms();
#endif
