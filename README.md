
# Cours 17.02 - Pointeurs
Cours : [handout](https://heig-tin-info.github.io/handout/content/pointers.html?highlight=pointeur)

- Un pointeur est une variable qui contient l'adresse d'une autre variable
- le & est l'opérateur d'adresse de
- le * est l'opérateur de déréférencement (la valeur à l'adresse de)
- Si on incérmante un pointeur, on incrémente de la taille du type pointé

# Cours 21.02 - Tableau de pointeurs
- Il est possible de stocker des pointeurs dans un tableau
- `int *tab[10];` est un tableau de 10 pointeurs sur des entiers

# Cours 24.02 - Structure
- Une structure est un ensemble de variables regroupées sous un même nom
- `struct` est le mot clé pour définir une structure
- `.` est l'opérateur pour accéder à un champ d'une structure
- `->` est l'opérateur pour accéder à un champ d'une structure pointée
- Pour comparer deux structures, il faut comparer chaque champ ou utiliser `memcmp`

```c
typedef struct {
    int x;
    int y;
} Point;

Point p = {.x = 1, .y = 2};
p.x = 3;
```

# Cours 26.02 - Lecture d'un fichiers textes
[handout fichier](https://heig-tin-info.github.io/handout/content/files.html#)

La manipulation de fichier se fera en utilisant un pointeur de type `FILE*` et les fonctions suivantes :

- `fopen` ouvre un fichier
  - `a` pour ajouter à la fin
  - `r` pour lire
  - `w` pour écrire
- `fclose` ferme un fichier
- `fgetc` lit un caractère
- `fgets` lit une ligne et retourne un pointeur sur le buffer (ou NULL si fin de fichier)

la fonction `fgets` lit une ligne, mais si la ligne est plus longue que le buffer, elle ne lit que le buffer et laisse le reste dans le fichier. La fonction ajoutera un `\0` à la fin du buffer.

# Cours 03.03 - Ecriture fichier texte
- `fprintf` écrit dans un fichier
- Pour écrire un entier dans un fichier : `fprintf(f, "%d", i);`

# Cours 10.03 - Fichiers binaires
- `fwrite` écrit dans un fichier binaire
- `fread` lit dans un fichier binaire
- `fseek` permet de se déplacer dans un fichier
- `ftell` permet de connaître la position actuelle dans un fichier
- `rewind` permet de revenir au début d'un fichier

`fwrite` et `fread` prennent 4 arguments :
- un pointeur sur le buffer
- la taille d'un élément
- le nombre d'éléments
- le fichier
- `fwrite(&i, sizeof(int), 1, f);`

`fseek` prend 3 arguments :
- le décalage
- le point de départ
  - SEEK_SET : début du fichier
  - SEEK_CUR : position actuelle
  - SEEK_END : fin du fichier
- le fichier
- `fseek(f, 0, SEEK_SET);`

A faire :
- fichier :
Ecrire dans un fichier avec fwrite "Bonjour" pour que l'on puisse le lire avec un éditeur de texte

- exercice 9 à 11 : https://github.com/tony-maulaz/info2-exercices/blob/main/fichier.md#ex-9
- exercice meas : https://github.com/tony-maulaz/info2-exercices/blob/main/measure.md