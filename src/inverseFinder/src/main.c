#include <stdlib.h>
#include <stdio.h>

uint16_t inverse(x, zn) {
    for (uint16_t i = 1; i < zn; i++) {
        if ((x*i) % zn == 1) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: inverseFinder <X> <N>\nWhere X*X^(-1) = 1 in Z_N.\n");
        return EXIT_SUCCESS;
    } else {
        uint16_t x = atoi(argv[1]);
        uint16_t n = atoi(argv[2]);
        uint16_t i = inverse(x, n);

        if (i < 0) {
            printf("Failed.\n %d might not have an inverse in Z_%d.\n", x, n);
            return EXIT_SUCCESS;
        } else {
            printf("%d\n", i);
        }
        
    }
}