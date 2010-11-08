#ifndef TESTING_H
#define TESTING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <xmmintrin.h>
#include "papitesting.h"

void clearCache();
void reset();
void setupPapiCodes();
long long medianTime(std::vector<long long>);

struct papiCode
{
    int code;
    std::string name;
};

#endif
