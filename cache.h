#include <stdint.h>

typedef struct {
    int key;
    int value;
} CacheNotry;
// Node + Entry = Notry (im a genius)

typedef struct {
    CacheNotry *cacheNotries;
    unsigned long long int size;
    int current;
    int hits;
    int misses;
} Cache;

Cache* cache_init(unsigned long long int size);

unsigned long long int lookup(Cache* cache, int key, int steps);

void insert(Cache* cache, int key, int steps);

