#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_TERMS_SIZE 2048

typedef struct TermStruct {
	int c; // coefficient
	int ri; // the ith remainder's value
} Term;

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Usage: main <num1> <num2>\n");
		return EXIT_SUCCESS;
	}

	// collect first two "remainders" as params
	int r0 = atoi(argv[1]);
	int r1 = atoi(argv[2]);

	// create an array of terms
	Term* terms = (Term*) malloc(DEF_TERMS_SIZE * sizeof(struct TermStruct));
	uint16_t terms_size = 0;
	uint16_t terms_cap = DEF_TERMS_SIZE;

	// add the terms to total r0	
	terms[terms_size++] = { .c = (r0/r1), .ri = r1 }; // q[3]*r[1]
	terms[terms_size++] = { .c = 1, .ri = r0%r1 }; // + 1*r[2]

	while (terms[terms_size].ri > 0) {
		

	// instead of creating a second terms array buffer to store changes, since all additions are added to the end
	// and only the current term per iteration will be changed, we can instead store the size of the array before every outer loop
	// and make the elements outside of the loop space the "buffer" array
	Term* terms_buf;

	



