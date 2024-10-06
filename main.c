#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "fifo_cache.h"
#include "lru_cache.h"
#include "main_functions.h"
#include "global_var.h"

unsigned long long hits = 0;
unsigned long long misses = 0;

int main(int argc, char* argv[]) {
    if (argc != 6) {
        printf("Wrong amount of arguments...\n");
        return 1;
    }

    unsigned long long N = atoi(argv[1]);
    unsigned long long MIN = atoi(argv[2]);
    unsigned long long MAX = atoi(argv[3]);
    // assign cachetype to the 4th argument
    char cacheType = argv[4][0];
    unsigned long long cacheSize = atoi(argv[5]);

    if (N <= 0 || MIN >= MAX) {
        printf(
            "Invalid arguments: N must be positive and MIN must be less than "
            "MAX.\n");
        return 1;
    }

    srand(time(NULL));

    // prompt user for cache type
    if (tolower(cacheType) == 'f') {
        printf("This is the FIFO Cache\n");
    } else if (cacheType == 'l') {
        printf("This is the LRU Cache\n");
        LRUCache* tempCache = lru_cache_init(cacheSize);
        print_LRU(tempCache);
        free(tempCache);
    } else {
        printf("Invalid cache type...\n");
        return 1;
    }

    print_cache_ratio(hits, misses);

    
}