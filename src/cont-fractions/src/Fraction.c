#include "include/Fraction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int gcd(uint32_t _a, uint32_t _b) {
	uint32_t a = _a, b = _b;

	// store quotient and remainder, and keep track of last remainder before 0
	// let r default to the second divisor, b
	uint32_t q, r = b, last_r;
	
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
	if (f.neg) {
		printf("-");
	}
    printf("%d/%d\n", f.n, f.d);
    return EXIT_SUCCESS;
}

Fraction GetInverseFraction(Fraction f) {
	return (Fraction) {.n = f.d, .d = f.n};
}

Fraction NewFraction(int n, int d) {
	if(n < 0 && d < 0) {
		return (Fraction) {.n = (uint32_t) -n, .d = (uint32_t) -d, .neg = false};
	} else if (n < 0) {
		return (Fraction) {.n = (uint32_t) -n, .d = (uint32_t) d, .neg = true};
	} else if (d < 0) {
		return (Fraction) {.n = (uint32_t) n, .d = (uint32_t) -d, .neg = true};
	} else {
		return (Fraction) {.n = (uint32_t) n, .d = (uint32_t) d, .neg = false};
	}
}

Fraction NewFractionFromFloat(float _v) {

	// find sign
	float v;
	bool neg;
	if (_v < 0) {
		v = -_v;
		neg = true;
	} else {
		v = _v;
		neg = false;
	}

	// make another copy of v
	float V = v;

	// multiplier
	float m = 1.0;

	// while not an integer
	while (V - (float)(int)V != 0) {
		m *= 10.0;
		V = m*v;
	}

	// simplify then return
	return (Fraction) {.n = V, .d = m, .neg = neg};
}