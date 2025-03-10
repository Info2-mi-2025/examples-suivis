#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_FILE 1

typedef struct{
    int id;
    double value;
} Measure;

int main(int argc, char *argv[])
{
    FILE* f = fopen("fichier", "w");
    if( f == NULL )
        return ERROR_FILE;

    // ecriture d'un tableau dans un fichier binaire
    int c[] = {12, 345};
    const size_t nb = sizeof(c) / sizeof(c[0]);
    fwrite(c, sizeof(int), nb, f);

    char* txt = "Hello";
    fwrite(txt, sizeof(char), 5, f); // identique
    fprintf(f, "%s", txt);
    fclose(f);

    f = fopen("fichier", "r");
    if( f == NULL )
        return ERROR_FILE;

    // lecture d'un tableau d'entier
    // attention il faut impérativement donner la taille
    int tab[2];
    size_t nb_read = fread(tab, sizeof(int), 2, f);
    if( nb_read == 2 ){
        printf("Val 1 : %d  Val 2 : %d", tab[0], tab[1]);
    }
    fclose(f);

    // structure
    // grâce à fwrite, il est possible d'écrire et lire directement
    // une structure.
    Measure m = {.id=1, .value=12.3};
    f = fopen("fichier", "w");
    if( f == NULL )
        return ERROR_FILE;
    fwrite(&m, sizeof(Measure), 1, f);
    fclose(f);

    Measure mr;
    f = fopen("fichier", "r");
    if( f == NULL )
        return ERROR_FILE;
    fread(&mr, sizeof(Measure), 1, f);
    fclose(f);

    printf("\nid : %d   -  val : %lf", mr.id, mr.value);

    return 0;
}