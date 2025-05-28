#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "pomme,banane,orange,kiwi";
    const char delim[] = ",";

    // strtok modifie la chaîne originale, donc on travaille sur une copie si on veut conserver l'original
    char *token = strtok(str, delim);

    // Boucle tant qu'on trouve un token
    while (token != NULL) {
        printf("Mot : %s\n", token);
        token = strtok(NULL, delim); // NULL pour continuer sur la même chaîne
    }


    char line[] = "Cercle,0,1,2,4.5";
    char* rest = strchr(line, ',') + 1; // + 1 pour éviter la ,
    
    char* name = strtok(line, delim);

    printf("Name : %s\n", name);
    printf("Rest : %s\n", rest);

    return 0;
}