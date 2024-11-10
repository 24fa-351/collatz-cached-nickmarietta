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
        // reupdate the value of N
        N = newN;
        amt_steps++;
    }
    return amt_steps;
}

// function to get easy random num
unsigned long long randomNumGen(unsigned long long MIN,
                                unsigned long long MAX) {
    unsigned long long randomNum = MIN + (rand() % (MAX - MIN + 1));
    return randomNum;
}

// helper function called in main.c to run LRU cache
unsigned long long run_lru_collatz(LRUCache* cache, unsigned long long N,
                                   unsigned long long MIN,
                                   unsigned long long MAX) {
    for (unsigned long long ix = MIN; ix <= MAX && ix < N; ix++) {
        unsigned long long value = collatz(ix);
        LRU_insert(cache, ix, value);
    }
    for (unsigned long long ix = 0; ix < N; ix++) {
        // make a new random number for each iteration
        unsigned long long randomNum = randomNumGen(MIN, MAX);
        unsigned long long value = LRU_get(cache, randomNum);
        if (value == -1) {
            // Calculate Collatz steps if not found in cache
            value = collatz(randomNum);
            LRU_insert(cache, randomNum, value);
        }
        printf("Number: %llu, Collatz steps: %llu\n", randomNum, value);
    }

    // print cache hit ratio
    print_cache_ratio(hits, misses);

    return 0;
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