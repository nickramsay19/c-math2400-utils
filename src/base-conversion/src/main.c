#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_REMAINDERS_SEEN 255

int main(int argc, char **argv) {

	// handle args
	if (argc < 4) {
		printf("Error: Usage main <num> <base_from> <base_to>\n");
		return EXIT_SUCCESS;
	}

	float x = strtof(argv[1], NULL);
	int n = (int) x; // get the integer component of x
	float f = x - (float) n; // get the fractional component of x
	int bf = atoi(argv[2]); // base from
	int bt = atoi(argv[3]); // base to

	// make space for the final string
	// estimate that the final string wont be longer than n*b^2 chars
	char* res = (char*) calloc(strlen(argv[1]*bt*bt, sizeof(char));
	int curr_chr = 0;

	// check if we need to convert num to base 10 first
	if (bf != 10) {
		printf("---------- CONVERT TO BASE 10 -----------\n");
		printf("ERROR: NOT IMPLEMENTED, PLEASE USE BASE 10\n");
		return EXIT_SUCCESS;
	}
		
	printf("---------- INTEGER PART -----------\n");
	// define q[n], q[n-1], d[n]
	// set qn to -1 to ensure entry to while loop
	// set qn_m1 to its initial value, n
	int qn = -1, qn_m1 = n, dn; 

	while (qn != 0) {

		// qn_m1 = qn * b + dn
		qn = qn_m1 / bt;
		dn = qn_m1 % bt;
	
		printf("%d = %d * %d + %d\n", qn, qn_m1, bt, dn);

		// next iteration
		qn_m1 = qn;
	}

	printf("---------- FRACTIONAL PART -----------\n");
	float rn = -1.0;	// r[n]
	float rn_m1 = f; // r[n-1]
	int dmn; // d[-n]

	// keep track of which digits we have seen
	int* remainders_seen = (int*) calloc(MAX_REMAINDERS_SEEN, sizeof(int)); // default to 0's won't matter, since rn == 0 will exit loop anyway
	int curr_rem_seen = 0;
	int start_recur; // for later, if we find a point from which the number recurs

	bool done = false;
	while (!done) {
		// b * r[n-1] = d[-n] + r[n]
		// --> d[-n] = floor(b * r[n-1])
		// 	&  r[n]   = frac(b * r[n-1])
		dmn = (int) (bt * rn_m1);
		rn = (((float) bt) * (rn_m1)) - dmn; // subtract dmn which is the integer part to get only the fractional part

		// print current step
		printf("%d * %f = %d + %f\n", bt, rn_m1, dmn, rn);

		// check if we are done
		if (rn == 0) {
			done = true;
		}	

		// otherwise, check if we can detect a recurring pattern
		// in which case, store where the recurring starts and stop the loop (from repeating forever)
		for (int i = 0; i < curr_rem_seen; i++) {
			if (remainders_seen[i] == rn) {
				// store the remainder from which the number begins to recur
				start_recur = rn;

				// finish the main loop
				done = true;
				
				// skip the rest of the for loop
				break;
			}

			// we didn't find a matching pre-occuring remainder
			// add the current one to the array
			remainders_seen[curr_rem_seen++] = rn;
		}

		// setup next iter
		rn_m1 = rn;
	}

	printf("---------- COMBINE BOTH PARTS -----------\n");
	printf("(%d)_%d ===> (%d.%d)_%d\n", x, bf, 
	

	return EXIT_SUCCESS;
}

