#include <stdio.h>

int main() {
    int a = 5;
    int b = 12;

    int* p_int = &a;

    int* ptab[] = {&a, NULL};

    (ptab[0]); // -> adresse de a

    // ptab1 -> pointer sur b
    ptab[1] = &b;
    // -> ptab double la valeur de b
    *(ptab[1]) *= 2;
    
    int * p = ptab[0]; // corect ?
}