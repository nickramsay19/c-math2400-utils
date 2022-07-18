#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    Fraction f = NewFractionFromFloat(0.5);
    PrintFraction(f);
    f = NewFractionFromFloat(3.21);
    PrintFraction(f);

    // get the recurring position
    int rec_pos = atoi(argv[1]); // add one to skip "./main", another to skip itself

    // get non-recurring part of cont frac
    printf("----------- NON-RECURRING PART -----------\n");
    double *cfn = (double*) malloc(rec_pos * sizeof(double));
    uint32_t cfni = 0;
    for (int i = 2; i < rec_pos+2; i++) {
        cfn[cfni++] = strtod(argv[i], NULL);
    }
    printContFrac(cfn, cfni);

    // eval non-recurring part
    for (int i = cfni-2; i >= 0; i--) {
        printf("%d: %f += 1/%f --> ", i, (double) cfn[i], (double) cfn[i+1]);
        cfn[i] += (double)(1.0/(double)cfn[i+1]);
        printf("%f/1\n", (double) cfn[i]);
    }
    printf(" ==> %lf\n", (double) cfn[0]);


    // now get recurring part
    printf("----------- RECURRING PART -----------\n");
    double *cfr = (double*) calloc(argc - 2, sizeof(double)); // default to 0s
    memset(cfr, (double) 0, rec_pos);
    uint32_t cfri = rec_pos;
    for (int i = rec_pos+2; i < argc; i++) {
        cfr[cfri++] = strtod(argv[i], NULL);
    }

    // print
    printf("let x = ");
    printContFrac(cfr, cfri);

    for (int i = 0; i < cfri; i++) {
        printf("%d", (int) cfr[i]);

        if (i < cfri - 1) {
            printf(" + 1/(");
        } else {
            printf(" + 1/x");
        }
    }
    for (int i = 1; i < cfri; i++) {
        printf(")");
    }
    printf("\n");
    

    free(cfn);
    free(cfr);

    return EXIT_SUCCESS;
}