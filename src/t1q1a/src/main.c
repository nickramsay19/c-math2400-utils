#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

// CHANGE THIS
int gcd(int A, int B) {
	int a = A, b = B;
	int q, r = b;
	while (r > 0) {
		if (a % b < 1) {
			return r;
		}

		q = a / b;
		r = a % b;

		a = b;
		b = r;
	}

	return -1;
}

int main(int argc, char **argv) {

	if (argc < 4) {
		printf("Usage: main <low> <high> <coprime>\n");
		return EXIT_SUCCESS;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);

	for (int i = a+1; i < b-1; i++) {
		if (!isPrime(i) && gcd(i, c) == 1) {
			printf("%d\n", i);
		}
	}

	return EXIT_SUCCESS;
}
