#include "fifo_cache.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global_var.h"

FIFOCache* fifo_cache_init(unsigned long long size) {
    FIFOCache* cache = malloc(sizeof(FIFOCache));
    cache->cacheNotries =
        (FIFOCacheNotry*)malloc(sizeof(FIFOCacheNotry) * size);
    cache->size = size;
    cache->current = 0;
    return cache;
}

unsigned long long FIFO_get(FIFOCache* cache, unsigned long long key) {
    for (unsigned long long ix = 0; ix < cache->size; ix++) {
        if (cache->cacheNotries[ix].key == key) {
            hits++;
            return cache->cacheNotries[ix].value;
        }
    }
    misses++;
    return -1;
}

void FIFO_insert(FIFOCache* cache, unsigned long long key,
                 unsigned long long value) {
    if (cache->current == cache->size) {
        pop(cache);
    }
    cache->cacheNotries[cache->current].key = key;
    cache->cacheNotries[cache->current].value = value;
    cache->current++;
}

void countOfEntries(FIFOCache* cache) {
    printf("Cache has %llu entries\n", cache->current);
}

void pop(FIFOCache* cache) {
    for (unsigned long long ix = 0; ix < cache->size - 1; ix++) {
        cache->cacheNotries[ix] = cache->cacheNotries[ix + 1];
    }
    cache->current--;
}

void freeFIFOCache(FIFOCache* cache) {
    free(cache->cacheNotries);
    free(cache);
}