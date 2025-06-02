#include <stdio.h>

// gcc tableau_pointeur_structure.c -oapp && ./app

typedef struct {
    int id;
    double value;
} Data;

// Fonction d'initialisation
void init(Data* data_array[], int size) {
    for (int i = 0; i < size; i++) {
        data_array[i]->id = i + 1;
        data_array[i]->value = i*10+2;  // Valeur par défaut
    }
}

int main() {
    // Création de 5 structures Data
    Data d1, d2, d3, d4, d5;

    // Tableau de pointeurs vers ces structures
    Data* data_ptrs[5] = { &d1, &d2, &d3, &d4, &d5 };
    // data_ptrs[0] = &d1;
    // ...

    // Initialisation
    init(data_ptrs, 5);

    // Affichage pour vérification
    for (int i = 0; i < 5; i++) {
        printf("Data %d: id = %d, value = %.2f\n", i, data_ptrs[i]->id, data_ptrs[i]->value);
    }

    return 0;
}