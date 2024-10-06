#include "main_functions.h"

#include "fifo_cache.h"
#include "global_var.h"
#include "lru_cache.h"

unsigned long long collatz(unsigned long long int N) {
    unsigned long long int amt_steps = 0;
    unsigned long long int newN;
    if (N == 1) {
        return amt_steps;
    }
    while (N != 1) {
        if (N % 2 == 0) {
            newN = N / 2;
        } else {
            newN = 3 * N + 1;
        }
        amt_steps++;
    }
    return newN;
}

unsigned long long randomNumGen(unsigned long long MIN, unsigned long long MAX) {
    unsigned long long randomNum = MIN + (rand() % (MAX - MIN + 1));
    return randomNum;
}

unsigned long long run_lru_collatz(LRUCache* cache, unsigned long long N,
                                   unsigned long long MIN,
                                   unsigned long long MAX) {
    unsigned long long randomNum = MIN + (rand() % (MAX - MIN + 1));
    for (unsigned long long ix = 0; ix < N; ix++) {
        unsigned long long value = LRU_lookup(cache, randomNum);
        if (value == -1) {
            value = collatz(randomNum);
            LRU_insert(cache, randomNum, value);
        }
    }
    unsigned long long amt_steps = collatz(randomNum);
    print_cache_ratio(hits, misses);  // Use global hits and misses
    return amt_steps;
}

void print_cache_ratio(unsigned long long hits, unsigned long long misses) {
    if (hits == 0 && misses == 0) {
        printf("No cache hits or misses\n");
        return;
    }
    unsigned long long total = hits + misses;
    double ratio = (double)hits / total;  // Corrected ratio calculation
    printf("Cache hits: %llu\n", hits);
    printf("Cache misses: %llu\n", misses);
    printf("Cache hit ratio: %.2f\n", ratio);  // Corrected format specifier
}