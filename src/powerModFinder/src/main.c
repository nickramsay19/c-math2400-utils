#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint64_t ipow(uint64_t _a, uint64_t p) {

    if (p == 0) {
        return 1;
    }
    uint64_t a = (uint64_t) _a;

    for (uint64_t i = 1; i < p; i++) {
        a *= _a;
    }

    return a;
}

int main(int argc, char **argv) {

    if (argc < 4) {
        printf("Usage: powerModFinder <a> <p> <m>\n");
        return EXIT_SUCCESS;
    }

    // collect params
    uint64_t a = atoi(argv[1]);
    uint64_t p = atoi(argv[2]);
    uint64_t m = atoi(argv[3]);

    bool found_one = false;

    for (uint64_t i = 1; i < p; i++) { 
        // +1
        if (ipow(a, i) % m == 1) {
            printf("a^%llu = 1 (mod %llu)\n", i, m);
            found_one = true;
        }

        // -1
        if (ipow(a, i) % m == m-1) {
            printf("a^%llu = -1 (mod %llu)\n", i, m);
            found_one = true;
        }
    }

    if (!found_one) {
        printf("Failed.\n");
    }

    return EXIT_SUCCESS;
};