#include <stdio.h>
#include <stdlib.h>
#include "include/Fraction.h"

int main(int argc, char **argv) {

    Fraction f = {.n = 100, .d = 50};
    PrintFraction(f);
    SimplifyFraction(&f);
    PrintFraction(f);

    Fraction g = {.n = 101, .d = 50};
    PrintFraction(g);
    SimplifyFraction(&g);
    PrintFraction(g);

    return EXIT_SUCCESS;
}
