#include <stdio.h>
#include <stdlib.h>
#include "array.h"

PointArray* create_array(int capacity){
    if( capacity < 1 ){
        return NULL;
    }

    // on crée le tableau dynamique de points
    Point* tmp = malloc(sizeof(Point) * capacity);
    if( tmp == NULL )
        return NULL;

    // on crée la strucutre pour gèrer les points
    PointArray* array = malloc(sizeof(PointArray));
    if( array == NULL ){
        free(tmp);
        return NULL;
    }

    array->array = tmp;
    array->capacity = capacity;
    array->nbr_element = 0;
    return array;
}

void print_array(PointArray* pa){
    if( pa == NULL || pa->array == NULL )
        return;

    for(size_t n=0; n < pa->nbr_element; n++){
        printf("Point %d : x=%d  y=%d\n", 
            n, pa->array[n].x, pa->array[n].y);
    }
}

bool insert_first(PointArray* pa, int x, int y){
    if( pa == NULL || pa->array == NULL )
        return false;

    // controle de la capacité (min une place vide)
    if( pa->nbr_element >= pa->capacity-1){
        printf("Le tableau est plein\n");
        return false;
    }
        
    // décalage du tableau
    for(size_t k=pa->nbr_element; k>0; k--){
        pa->array[k] = pa->array[k-1];
    }

    pa->array[0].x = x;
    pa->array[0].y = y;
}

Point remove_first(PointArray* pa){
    if( pa == NULL || pa->array == NULL )
        exit(1);

    // controle de la capacité (min un point)
    if( pa->nbr_element >= 1){
        printf("Le tableau est vide\n");
        exit(1);
    }
        
    // décalage du tableau
    for(size_t k=pa->nbr_element; k>0; k--){
        pa->array[k] = pa->array[k-1];
    }

    Point p = pa->array[0];

    pa->array[0].x = x;
    pa->array[0].y = y;
}

