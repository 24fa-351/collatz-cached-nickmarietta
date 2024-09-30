#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// main function takes:
/*

1. Number of values to test N
2. Smallest value to test (MIN)
3. Largest value to test (MAX)

THEN:
    perform this for N random numbers (use rand())
    Exercise time command and large enough N to be interesting (100, 1000, 1M) to report in 
    one tab of a GSheet and estimate the mean time for each number to be processed
    given the MIN and MAX

*/
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



}