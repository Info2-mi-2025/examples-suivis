#include <stdio.h>


typedef enum {LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE} Jour;

void print_jour(Jour j){ // paramètre de type Jour
    switch (j) {
        case LUNDI: printf("Lundi\n"); break;
        case MARDI: printf("Mardi\n"); break;
        case MERCREDI: printf("Mercredi\n"); break;
        case JEUDI: printf("Jeudi\n"); break;
        case VENDREDI: printf("Vendredi\n"); break;
        case SAMEDI: printf("Samedi\n"); break;
        case DIMANCHE: printf("Dimanche\n"); break;
        default: printf("Numéro invalide\n"); break;
    }
}

int main() {

    Jour jour = MARDI;
    print_jour(jour);

    return 0;
}