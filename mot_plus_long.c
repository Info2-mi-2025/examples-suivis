// 

#include <stdio.h>
#include <string.h>

const char* mot_le_plus_long(const char* mots[], int taille) {
    const char* plus_long = mots[0];
    for (int i = 1; i < taille; i++) {
        if (strlen(mots[i]) > strlen(plus_long)) {
            plus_long = mots[i];
        }
    }
    return plus_long;
}

int main() {
    // Tableau de chaînes de caractères
    const char* mots[5] = { "chat", "éléphant", "chien", "lion", "girafe" };

    // Appel de la fonction
    const char* resultat = mot_le_plus_long(mots, 5);

    // Affichage du résultat
    printf("Le mot le plus long est : %s\n", resultat);

    return 0;
}
