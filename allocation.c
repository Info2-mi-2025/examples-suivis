#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

#define GROWTH_FACTOR 2

int main(){
    // tableau 10 double
    int size = 10;
    double* tab = malloc(sizeof(double) * size);
    if(tab == NULL){
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    // on peut accéder aux éléments du tableau comme un tableau
    tab[0] = 2.3;


    // on stock l'adresse de la nouvelle allocation dans un pointeur temporaire
    // pour ne pas perdre l'adresse de la première allocation en cas d'erreur
    double* tmp = realloc(tab, sizeof(double) * size * GROWTH_FACTOR); // on augmente la taille du tableau
    if( tmp == NULL){
        // tmp == NULL
        // backup de tab 
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }
    size *= GROWTH_FACTOR;
    tab = tmp;
    tmp = NULL;

    // utilisation du tableau
    tab[10] = 3.4;
    tab[0] = 4.5;

    // fin du programme
    free(tab); // on libère la mémoire
    tab = NULL;

    // tableau de structure
    Point* array = malloc(sizeof(Point) * 10);
    
    // on peut accéder aux champs de la structure comme un tableau
    array[0].x = 1;

    free(array);

    return 0;
}