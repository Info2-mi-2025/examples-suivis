
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

```c
typedef struct {
    int x;
    int y;
} Point;

Point p = {.x = 1, .y = 2};
p.x = 3;
```