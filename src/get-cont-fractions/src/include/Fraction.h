#ifndef FRACTION_H
#define FRACTION_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct FractionStruct {
    uint32_t n, d;
    bool neg;
} Fraction;

int SimplifyFraction(Fraction *f);

int PrintFraction(Fraction f);

Fraction GetInverseFraction(Fraction f);

Fraction NewFraction(int n, int d);

Fraction NewFractionFromDouble(double v);

int GetFractionComponents(Fraction f, int *i, Fraction *r);

#endif
