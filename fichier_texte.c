// gcc fichier_texte.c -o app && ./app
#include <stdio.h>
#include <stdbool.h>

#define SIZE_BUFFER 3

int main() {
    FILE* f = NULL;
    
    printf("\n");
    
    // ouverture
    f = fopen("test.txt", "r"); // mode r lecture  w : write  a : append
    if( f == NULL ){
        printf("Erreur d'ouverture");
        return 1;
    }

    do{
        char c = fgetc(f);
        if( c == EOF )
            break;
        printf("%c", c);
    }while(true);
    fclose(f); // attention toujours fermer le fichier


    // fgets
    f = fopen("test.txt", "r"); // mode r lecture  w : write  a : append
    if( f == NULL ){
        printf("Erreur d'ouverture");
        return 1;
    }
    printf("\nnLecture fgets\n");
    char line[SIZE_BUFFER];
    int i = 0;
    #if 0
    while( fgets(line, SIZE_BUFFER, f) != NULL ){
        i++;
        printf("%s", line);
    }
    #else
    do{
        char* c = fgets(line, SIZE_BUFFER, f);
        if( c == NULL )
            break;
        i++;
        printf("%s", line);
    }while(true);
    #endif
    fclose(f);
}