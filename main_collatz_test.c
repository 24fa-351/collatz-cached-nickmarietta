#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "collatz.c"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Wrong amount of arguments...");
        return 1;
    }

    int N = atoi(argv[1]);
    int MIN = atoi(argv[2]);
    int MAX = atoi(argv[3]);

    if (N > MAX || N < MIN) {
        printf("The number is not between the min and max: %d", N);
        return 0;
    }

    for (unsigned long long int ix = 0; ix < N; ++ix) {
        int num = rand() % (MAX - MIN + 1) + MIN;
    }

    
}