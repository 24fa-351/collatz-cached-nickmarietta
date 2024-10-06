#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Wrong amount of arguments...\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int MIN = atoi(argv[2]);
    int MAX = atoi(argv[3]);

    if (N <= 0 || MIN >= MAX) {
        printf(
            "Invalid arguments: N must be positive and MIN must be less than "
            "MAX.\n");
        return 1;
    }

    srand(time(NULL));

    FILE *file = fopen("output.csv", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return 1;
    }

    fprintf(file, "RandomNumber,Steps\n");

    for (int i = 0; i < N; i++) {
        int RN = MIN + rand() % (MAX - MIN + 1);
        int steps = 0;
        int current = RN;

        while (current != 1) {
            if (current % 2 == 0) {
                current /= 2;
            } else {
                current = 3 * current + 1;
            }
            steps++;
        }

        fprintf(file, "%d,%d\n", RN, steps);
    }

    fclose(file);
    printf("Results written to output.csv\n");

    return 0;
}