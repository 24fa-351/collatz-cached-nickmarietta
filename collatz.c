#include "collatz.h"

unsigned long long int collatz(unsigned long long int N) {
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