#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node{
    Point p; // data
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
} List;

void init_list(List* l){
    l->head = NULL;
    l->tail = NULL;
}

void print_list(List* l){

    // affichage des points
    Node* current = l->head;
    int cpt = 0;
    while( current != NULL ){
        printf("Point %d : x=%d   / y=%d   \n", cpt, current->p.x, current->p.y );
        current = current->next;
        cpt++;
    }
}

Node* create_node(int x, int y){
    Node* new = malloc(sizeof(Node));
    if( new == NULL) return NULL;

    new->p.x = x;
    new->p.y = y;
    new->next = NULL;
    return new;
}

// fonction pop, retire peremier element
Point pop(List* l){
    if( l == NULL || l->head == NULL ) exit(1);

    Point p = l->head->p; // on copie les valeurs du points à retourner
    Node* tmp = l->head; // backup adresse du noeud à supprimer

    // un seul elem.
    if( l->head->next == NULL ){
        l->tail = NULL; // la liste est vide
    }
    l->head = l->head->next; // mise à jour de head

    free(tmp);
    return p;
}

// créer un point et l'ajouter en fin de liste
bool append(List* l, int x, int y){
    Node* node = create_node(x, y);
    if( node == NULL ) return false;

    if( l->head == NULL ){ // la liste est vide
        l->head = node;
        l->tail = node;
    }
    else{
        l->tail->next = node;
        l->tail = node;
    }
}

int main() {
    List l;
    init_list(&l);

    append(&l, 10, 20);
    append(&l, 11, 21);
    print_list(&l); // 2points

    pop(&l);
    print_list(&l); // 1 points

    pop(&l);
    print_list(&l); // rien
    
    pop(&l);
    print_list(&l); // rien
    
    return 0;
}