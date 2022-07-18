#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000000

// CHANGE THIS
int expr(int p) {
	return 15*p + 4;
}

int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int isPerfectSquare(int n) {
	for (int i = 1; i < 3162; i++) {
		if (i*i == n) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char **argv) {

	for (int i = 2; i < MAX; i++) {
		if (isPrime(i) && isPerfectSquare(expr(i))) {
			printf("%d\n", i);
		}
	}
	return EXIT_SUCCESS;
}
