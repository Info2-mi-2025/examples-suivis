#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int tab[2] = {1,2};
    int* p = &a;
    int* ptab = tab; // &tab[0]
    int* ptab1 = &tab[1];
    printf("a = %d\n", a); // Affichage de la valeur de a
    printf("p = %p\n", p); // Affichage de l'adresse de a
    printf("*p = %d\n", *p); // Affichage de la valeur pointée par p
    
    // tableau
    printf("ptab = %p\n", ptab); // Affichage de l'adresse de a
    ptab++;
    printf("ptab1 = %p\n", ptab); // Affichage de l'adresse de a
    
    
    char* txt = "Bonjour"; // pointeur sur chaîne de caractères
    char* pc = txt; // &txt[0]
    pc += 3;
    printf("%s", pc); // jour, pc adresse de départ -> \0

    return 0;
}