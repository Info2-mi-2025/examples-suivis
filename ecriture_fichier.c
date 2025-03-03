#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_FILE 1

typedef struct{
    int a;
    int b;
} TestStruct;

void print_help(FILE* f){
    char* msg = "L'aide du programme";
    fprintf(f, "%s", msg);
}

void saveStruct(TestStruct* ps, FILE* f){
    fputs("\nLa structure\n", f);
    fprintf(f, "%d,%d\n", ps->a, ps->b);
}

int main(int argc, char *argv[])
{
    FILE* f = fopen("fichier.txt", "w"); // mode w écriture ou a pour ajouter
    if( f == NULL )
        return ERROR_FILE;

    fprintf(f, "%s", "Bonjour\n");

    for(int i=0; i<10; i++){
        fprintf(f, "%d\n", i); // écrit dans le fichier
        fprintf(stdout, "%d\n", i); // écrit sur la console
    }

    print_help(f); // fichier
    print_help(stdout); // console

    // Ecriture de la structure
    TestStruct s = {.a=1, .b=2}; // déclaration d'une structure
    TestStruct tab[10] = {0}; // déclaration d'un tableau de structure
    tab[0].a = 1;
    tab[0].b = 2;
    saveStruct(&s, f);

    fclose(f);

    return 0;
}