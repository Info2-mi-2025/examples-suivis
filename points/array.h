#pragma once 
#include <stdbool.h>

typedef struct{
    int x;
    int y;
}Point;

typedef struct{
    Point* array; // tableau de point dynamique
    int capacity;
    int nbr_element;
}PointArray;

PointArray* create_array(int capacity);
bool insert_first(PointArray* pa, int x, int y);
Point remove_first(PointArray* pa);
void print_array(PointArray* pa);