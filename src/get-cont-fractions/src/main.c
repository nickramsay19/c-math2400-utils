#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // sqrt
#include "include/Fraction.h"

int printContFrac(double* nums, int count) {
    printf("[");
    for (int i = 0; i < count; i++) {
        printf("%d", (int) nums[i]);

        // print the correct separator
        if (i == count - 1) {
            printf("]\n");
        } else if (i == 0) {
            printf("; ");
        } else {
            printf(", ");
        }
    }

    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: main <num> [--sqrt]\n");
        return EXIT_SUCCESS;
    }

    double v = strtod(argv[1], NULL);
    printf("%lf\n", v);
    if (argc > 2 && strcmp(argv[2], "--sqrt") == 0) {
        v = sqrt(v);
    }
    printf("%lf\n", v);
    Fraction f = NewFractionFromDouble(v);
    PrintFraction(f);
    Fraction fr = {.n = 1, .d = 0, .neg = false}; // default (but set .n to 1 to force loop to start)
    int I;
    
    int c = 20;

    while (fr.n != 0 && c-- > 0) {
        GetFractionComponents(f, &I, &fr);
        PrintFraction(f);
        printf(" = %d + ", I);
        PrintFraction(fr);
        printf("\n");

        // set next values
        f = GetInverseFraction(fr);
    }

    return EXIT_SUCCESS;
    
}