#include "include/Fraction.h"
#include <stdio.h>
#include <stdlib.h>

int gcd(int _a, int _b) {
	int a = _a, b = _b;

	// store quotient and remainder, and keep track of last remainder before 0
	// let r default to the second divisor, b
	int q, r = b, last_r;
	
	while (r > 0) {

		// keep track of the previous remainder before we change it
		last_r = r;
	
		// calculate the quotient and remainder
		q = a / b;
		r = a % b;

		// get the next line's values
		a = b;
		b = r;
	}

	// print the last remainder before 0
	return last_r;
}

int SimplifyFraction(Fraction *f) {
    int nd_gcd = gcd(f->n, f->d);
    if (nd_gcd > 1) {
        f->n /= nd_gcd;
        f->d /= nd_gcd;
    }

    return EXIT_SUCCESS;
}

int PrintFraction(Fraction f) {
    printf("%d/%d\n", f.n, f.d);
    return EXIT_SUCCESS;
}