#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned long long hits;
extern unsigned long long misses;

typedef struct {
    unsigned long long key;
    unsigned long long value;
} CacheNotry;

typedef struct {
    CacheNotry* cacheNotries;
    unsigned long long capacity;
    unsigned long long size;
} LRUCache;

LRUCache* lru_cache_init(unsigned long long size);

unsigned long long LRU_get(LRUCache* cache, unsigned long long key);

void LRU_insert(LRUCache* cache, unsigned long long key,
                unsigned long long value);

void LRU_free(LRUCache* cache);

void LRU_capacity_full(LRUCache* cache);

void print_LRU(LRUCache* cache);

#endif