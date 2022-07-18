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
    printf("%d/%d", f.n, f.d);
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

Fraction NewFractionFromDouble(double _v) {

	// find sign
	double v;
	bool neg;
	if (_v < 0) {
		v = -_v;
		neg = true;
	} else {
		v = _v;
		neg = false;
	}

	// make another copy of v
	double V = v;

	// multiplier
	double m = 1.0;

	// while not an integer
	// limit to 50 (<53) decimal places, then just force to int
	while (V - (double)(int)V != 0 && m < 100000000000000) {
		m *= 10;
		V = v*m;
		printf("%lf\n", V);
	}

	// simplify then return
	return (Fraction) {.n = (uint32_t) V, .d = m, .neg = neg};
}

// TODO: negs
int GetFractionComponents(Fraction f, int *i, Fraction *r) {
	*i = f.n / f.d;
	*r = (Fraction) {.n = f.n % f.d, f.d, .neg = f.neg};

	//*i = (f.n - f.d)/f.d;
	//*r = (Fraction) {.n = f.n - *i*(f.d), .d = f.d, .neg = f.neg};
	return EXIT_SUCCESS;
}