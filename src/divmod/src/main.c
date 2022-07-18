#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: main <num1> <num2>\n");
        return EXIT_SUCCESS;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // print one per line
    printf("%d\n", a / b);
    printf("%d\n", a % b);

    return EXIT_SUCCESS;
}