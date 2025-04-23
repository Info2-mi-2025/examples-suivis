
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

# Cours 17.03 - Allocation dynamique

Lien vers le [handout](https://heig-tin-info.github.io/handout/content/memory-management.html?highlight=malloc#allocation-dynamique)

Cyberlearn : [Allocation dynamique](https://cyberlearn.hes-so.ch/pluginfile.php/3363256/mod_resource/content/0/INFO2.03%20-%20lallocation%20dynamique.pdf)

L'allocation dynamique permet de réserver de la mémoire à l'exécution. Cela permet de ne pas avoir à définir la taille d'un tableau à la compilation. La taille peut être définie à l'exécution et est exprimée en octets.

>Pour rappel, il est possible de connaître la taille d'un type avec l'opérateur `sizeof`.

- `malloc` alloue de la mémoire
- `free` libère de la mémoire
- `realloc` réalloue de la mémoire
- `calloc` alloue de la mémoire et initialise à 0

`malloc` prend en argument la taille en octets et retourne un pointeur sur la mémoire allouée. Si la mémoire n'est pas allouée, la fonction retourne `NULL`.

`free` prend en argument un pointeur sur la mémoire à libérer.

Exemple pour un tableau de 10 entiers :
```c
int *tab = malloc(10 * sizeof(int));
tab[0] = 42;
free(p);
```

## Important
- Il n'est pas possible de récupérer la taille d'une zone mémoire allouée dynamiquement.
- Il n'est pas possible d'utiliser sizeof sur une zone mémoire allouée dynamiquement (comme avec malloc).
- Si l'adresse d'une zone allouée est perdue (c’est-à-dire si le pointeur est écrasé ou oublié), il est impossible de la retrouver.

### Réallocation de mémoire
`realloc` permet de réallouer de la mémoire. 

- Elle prend en argument un pointeur sur la mémoire à réallouer et la nouvelle taille en octets. 
- Si la mémoire n'est pas allouée, la fonction retourne `NULL`.
- Si la réallocation échoue, la mémoire originale est conservée.
- Si la réallocation réussit, la mémoire originale est libérée et la fonction retourne un pointeur sur la nouvelle mémoire allouée.

Exemple pour un tableau de 10 entiers :
```c
int *tab = malloc(10 * sizeof(int));
tab = realloc(tab, 20 * sizeof(int));
```

### Exercices
- [Exercices allocation dynamique](https://github.com/tony-maulaz/info2-exercices/blob/main/allocation.md)


# Cours 21.02 - Tableaux dynamiques

Lien vers le [handout](https://heig-tin-info.github.io/handout/content/data-structures.html#tableau-dynamique)

Lien vers le [slides](https://cyberlearn.hes-so.ch/pluginfile.php/3400672/mod_resource/content/0/allocation-dynamique.pdf)


Exercice : 
- [tableaux dynamique](https://github.com/tony-maulaz/info2-exercices/blob/main/td_allocation.md)
- [tableaux dynamique supl](https://github.com/tony-maulaz/info2-exercices/blob/main/allocation_dynamique.md)
- [tableaux dynamique binaire](https://github.com/tony-maulaz/info2-exercices/blob/main/allocation_binaire.md)



## Suppression de valeur
Dans un tableau dynamique, supprimer une valeur ne signifie pas que la donnée est physiquement retirée de la mémoire. En réalité, on se contente de diminuer le compteur d'éléments (par exemple, une variable taille ou count). Ainsi, la mémoire occupée par l’élément supprimé reste allouée. Si un nouvel élément est ajouté par la suite, il viendra généralement écraser la dernière valeur considérée comme supprimée.
Il est donc important de noter que la taille allouée en mémoire du tableau ne change pas lors d'une suppression. Seul le nombre logique d’éléments est mis à jour.

# Cours 31.03 - Les listes chaînées

L'example d'implémentation d'une liste chaînée est dans le fichier `list.c`

Lien vers le [handout](https://heig-tin-info.github.io/handout/content/data-structures.html#listes-chainees)

Lien vers le [slides](https://cyberlearn.hes-so.ch/pluginfile.php/3400675/mod_resource/content/0/liste-chain%C3%A9e.pdf)

Lien vers [developpez.com](https://chgi.developpez.com/liste/)

Important : 
- Une liste chaînée est une structure de données qui permet de stocker des éléments de manière dynamique.
- Chaque élément de la liste est appelé un nœud.
- Chaque nœud est créé dynamiquement avec `malloc`.
- Chaque nœud contient une valeur et un pointeur vers le nœud suivant.
- Le dernier nœud de la liste pointe vers NULL.
- La liste chaînée est dynamique, ce qui signifie que la taille de la liste peut changer à tout moment.
- La liste chaînée est plus flexible qu'un tableau, car elle permet d'ajouter et de supprimer des éléments facilement.
- Pour insérer ou supprimer un élément dans une liste chaînée, il faut modifier les pointeurs des nœuds.
- Pour parcourir une liste chaînée, il faut utiliser une boucle et un pointeur temporaire `Node* current`.

> Un exemple d'implémentation pour le `TD liste de double` est disponible dans le fichier : `td-list-example.c`.

Exercices :
- [Liste personne](https://github.com/tony-maulaz/info2-exercices/blob/main/liste_personne.md)
- [Liste de points 3D](https://github.com/tony-maulaz/info2-exercices/blob/main/liste-points.md)
