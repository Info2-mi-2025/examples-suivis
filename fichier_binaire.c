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

    fclose(f);
    return 0;
}