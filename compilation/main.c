// compilation : 
// gcc -std=c99 -Wall -Wextra -Wpedantic -o app main.c algo.c lib.c -lm
// - Wall : all warnings
// - Wextra : extra warnings
// - Wpedantic : strict ISO C compliance
// -lm : link with the math library
// -o : output file name
// -std=c99 : use C99 standard

#include <stdio.h>

int afficher();

#include "lib.h"
//double compute(int a, int b);

int main() {
    Point p;
    printf("Hello World\n");
    int res = compute(1, 2);
    printf("Result: %d\n", res);
    afficher();
    return 0;
}

