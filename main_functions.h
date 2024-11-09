#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H
#include "fifo_cache.h"
#include "lru_cache.h"


unsigned long long collatz(unsigned long long int N);

unsigned long long randomNumGen(unsigned long long MIN, unsigned long long MAX);

unsigned long long run_lru_collatz(LRUCache* cache, unsigned long long N,
                                   unsigned long long MIN,
                                   unsigned long long MAX);

void output_lru(LRUCache* cache, unsigned long long N, unsigned long long MIN,
                unsigned long long MAX);

unsigned long long run_FIFO_collatz(FIFOCache* cache,
                                    unsigned long long randomNum);

void output_FIFO(FIFOCache* cache, unsigned long long N, unsigned long long MIN,
                 unsigned long long MAX);

void print_cache_ratio(unsigned long long hits, unsigned long long misses);

#endif