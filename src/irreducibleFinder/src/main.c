#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: main <num>\n");
		return EXIT_SUCCESS;
	}

	bool foundZero = false;	

	int a = atoi(argv[1]);
	for (int i = 1; i < a; i++) {
		foundZero = false;
		for (int j = 1; j < a; j++) {
			if ((i*j) % a == 0) {
				foundZero = true;
				break;
			}
		}

		if (!foundZero) {

			printf("%d\n", i);
		}
	}

	return EXIT_SUCCESS;
}
