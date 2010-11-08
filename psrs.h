#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <algorithm>
#include "insertion.h"

void PSRS(float* first, float* last, const int p);
void* mergefunc(void* mp1);

