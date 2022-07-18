#ifndef FRACTION_H
#define FRACTION_H

typedef struct FractionStruct {
    int n, d;
} Fraction;

int SimplifyFraction(Fraction *f);

int PrintFraction(Fraction f);

#endif
