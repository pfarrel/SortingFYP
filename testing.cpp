#include "testing.h"
#include "sortingnetwork.h"
#include "sortingnetworkSSE.h"
#include <algorithm>
#include <vector>

const int size = 1024*1024*64;
const int runs = 5;

std::vector<papiCode> papiCodes;

void clearCache()
{
    char* a = (char*)_mm_malloc(sizeof(char) * 1024 * 1024 * 16,16);
    char* b = (char*)_mm_malloc(sizeof(char) * 1024 * 1024 * 16,16);

    memcpy(a,b,sizeof(char)*1024*1024*16);
    memcpy(b,a,sizeof(char)*1024*1024*16);
    _mm_free(a);
    _mm_free(b);
}

void reset()
{
    //memcpy(workKeys, keys, sizeof(float) * size);
    clearCache();
}

long long medianTime(std::vector<long long> times)
{
    std::sort(times.begin(), times.end());
    return times[times.size() / 2];
}

void setupPapiCodes()
{
    papiCode tmp;
    tmp.code = 0x80000000;
    tmp.name = std::string("L1 Data Cache Misses");
    papiCodes.push_back(tmp);

    tmp.code = 0x80000002;
    tmp.name = std::string("L2 Data Cache Misses");
    papiCodes.push_back(tmp);

    tmp.code = 0x80000001;
    tmp.name = std::string("L1 Instruction Cache Misses");
    papiCodes.push_back(tmp);

    tmp.code = 0x80000003;
    tmp.name = std::string("L2 Instruction Cache Misses");
    papiCodes.push_back(tmp);

    tmp.code = 0x8000002b;
    tmp.name = std::string("Conditional Branches");
    papiCodes.push_back(tmp);

    tmp.code = 0x8000002e;
    tmp.name = std::string("Mispredicted Brances");
    papiCodes.push_back(tmp);

    tmp.code = 0x80000031;
    tmp.name = std::string("Instructions Issued");
    papiCodes.push_back(tmp);

    tmp.code = 0x80000032;
    tmp.name = std::string("Instructions Completed");
    papiCodes.push_back(tmp);

    tmp.code = 0x80000039;
    tmp.name = std::string("Cycles Stalled");
    papiCodes.push_back(tmp);

    tmp.code = 0x8000003b;
    tmp.name = std::string("Total Cycles");
    papiCodes.push_back(tmp);
    

}
