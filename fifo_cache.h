#ifndef FIFO_CACHE_H
#define FIFO_CACHE_H

extern unsigned long long hits;
extern unsigned long long misses;

typedef struct {
    unsigned long long key;
    unsigned long long value;
} FIFOCacheNotry;
// Node + Entry = Notry (im a genius)

typedef struct {
    FIFOCacheNotry* cacheNotries;
    unsigned long long size;
    unsigned long long current;
    unsigned long long hits;
    unsigned long long misses;
} FIFOCache;

FIFOCache* fifo_cache_init(unsigned long long size);

unsigned long long lookup(FIFOCache* cache, unsigned long long key);

void insert(FIFOCache* cache, unsigned long long key, unsigned long long value);

void countOfEntries(FIFOCache* cache);

void pop(FIFOCache* cache);

void freeFIFOCache(FIFOCache* cache);

#endif