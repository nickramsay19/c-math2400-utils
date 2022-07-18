#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int printhr() {
	printf("#");
	for (int i = 0; i < 14 + 5*5; i++) {
		printf("-");
	}
	printf("#\n");

	return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Usage: main <num1> <num2>\n");
		return EXIT_SUCCESS;
	}

	int A = atoi(argv[1]);
	int B = atoi(argv[2]);
	int a = A, b = B;

	// estimate a maximum step count
	size_t max_steps = max(a, b) / 2;

	// create the step arrs
	int *q = (int*) calloc(max_steps, sizeof(int));
	int *r = (int*) calloc(max_steps, sizeof(int));
	int *x = (int*) calloc(max_steps, sizeof(int));
	int *y = (int*) calloc(max_steps, sizeof(int));
	// counters
	uint8_t i = 2;

	// initialise values
	r[0] = a; 
	r[1] = b;
	x[0] = 1;
	x[1] = 0;
	y[0] = 0;
	y[1] = 1;
	
	do {
		q[i] = a / b;
		r[i] = a % b;
		x[i] = x[i-2] - q[i]*x[i-1];
		y[i] = y[i-2] - q[i]*y[i-1];

		a = b;
		b = r[i];

	} while (r[i++] > 0);

	// print
	printhr();
	printf("| i |");
	for (int k = 0; k < i; k++) {
		printf(" %-4d|", k);
	}
	printf("\n");
	printhr();
	printf("| q |");
	for (int k = 0; k < i; k++) {
		printf(" %-4d|", q[k]);
	}
	printf("\n| y |");
	for (int k = 0; k < i; k++) {
		printf(" %-4d|", r[k]);
	}
	printf("\n| x |");
	for (int k = 0; k < i; k++) {
		printf(" %-4d|", x[k]);
	}
	printf("\n| y |");
	for (int k = 0; k < i; k++) {
		printf(" %-4d|", y[k]);
	}
	printf("\n");
	printhr();

	// free memory
	free(q);
	free(r);
	free(x);
	free(y);

	return EXIT_SUCCESS;
}
