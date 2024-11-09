#include "lru_cache.h"
#include "global_var.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LRUCache* lru_cache_init(unsigned long long size) {
    LRUCache* cache = malloc(sizeof(LRUCache));
    cache->cacheNotries = (CacheNotry*)malloc(sizeof(CacheNotry) * size);
    cache->capacity = size;
    cache->size = 0;
    return cache;
}

unsigned long long LRU_get(LRUCache* cache, unsigned long long key) {
    for (unsigned long long ix = 0; ix < cache->size; ix++) {
        if (cache->cacheNotries[ix].key == key) {
            unsigned long long value = cache->cacheNotries[ix].value;

            // move the found entry to the front to update its priority
            CacheNotry temp = cache->cacheNotries[ix];
            for (unsigned long long j = ix; j > 0; j--) {
                cache->cacheNotries[j] = cache->cacheNotries[j - 1];
            }
            cache->cacheNotries[0] = temp;
            hits++;
            return value;
        }
    }  // if not found return -1
    misses++;
    return -1;
}

void LRU_insert(LRUCache* cache, unsigned long long key,
                unsigned long long value) {
    if (cache->size == cache->capacity) {
        // evict the least recently used entry & call to function capacity_full
        LRU_capacity_full(cache);
        cache->cacheNotries[0].key = key;
        cache->cacheNotries[0].value = value;
    } else {
        // insert the new entry at the front
        for (unsigned long long ix = cache->size; ix > 0; ix--) {
            cache->cacheNotries[ix] = cache->cacheNotries[ix - 1];
        }
        cache->cacheNotries[0].key = key;
        cache->cacheNotries[0].value = value;
        cache->size++;
    }
}

void LRU_free(LRUCache* cache) {
    free(cache->cacheNotries);
    free(cache);
}

void LRU_capacity_full(LRUCache* cache) {
    // evict the LRU entry
    for (unsigned long long ix = cache->size - 1; ix > 0; ix--) {
        cache->cacheNotries[ix] = cache->cacheNotries[ix - 1];
    }
}

void print_LRU(LRUCache* cache) {
    for (unsigned long long ix = 0; ix < cache->size; ix++) {
        printf("Key: %llu, Value: %llu\n", cache->cacheNotries[ix].key,
               cache->cacheNotries[ix].value);
    }
}