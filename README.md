# MATH2400 Utilities
> Nicholas Ramsay

A suite of C programs useful for completing MATH2400 at UNSW, or for finite mathematics generally. Currently completed are:

1. `gcd <A> <B>` - Greatest common denominator using the Euclidean algorithm, with working.
2. `egcd <A> <B>` - Extended Euclidean algorithm, with working.
3. `inverseFinder <X> <N>` - Find the inverse of X, X^(-1) in Z_N if it exists.
4. `powerModFinder <a> <p> <N>` - Finds a k < p such that a^k = 1 in Z_N.
5. `divmod <A> <B>` - Simply calculates A/B and A%B, for convenient command line usage.


## Usage
1. Simply use `make`.
2. Add the dist directory to `$PATH`.

## Backlog
* Continued fractions utilities
    * With functions on roots representations.
* Fractional base conversion utilities
    * Basic integer conversion tools are abundant, my tools will produce floating point number representations.