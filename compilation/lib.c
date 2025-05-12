#include <stdio.h>
#include "lib.h"

int count = 0;
int get_count(){
    return count;
}

double compute(int a, int b){
    printf("Super compute function\n");
    return a*2 + b;
}

Point create(){
    Point p = {.a=1, .b=0};
    return p;
}