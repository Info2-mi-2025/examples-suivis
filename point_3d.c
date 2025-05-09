#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int x;
    int y;
    int z;
} Point;

typedef struct Node{
    Point p;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct{
    Node* head;
    Node* tail;
} List;

void print_point(Point* p){
    if( p == NULL ) return;
    printf("Point : x=%d   / y=%d   / z=%d\n", p->x, p->y, p->z);
}

Node* create_node(int x, int y, int z){
    Node* n = malloc(sizeof(Node));
    if(n == NULL)
        return NULL;

    n->prev = NULL;
    n->next = NULL;
    n->p.x = x;
    n->p.y = y;
    n->p.z = z;
    return n;
}

bool compare_points(Point* p1, Point* p2){
    if(p1 == NULL || p2 == NULL)
        return false;
    return memcmp(p1, p2, sizeof(Point)) == 0;
}

int find_point(List* l, Point* p){
    if( l == NULL || p == NULL)
        return -1;

    Node* current = l->head;

    int pos = 0;
    while(current != NULL){
        if( compare_points(p, &(current->p)) )
            return pos;
        pos++;
        current = current->next;
    }
    return -1;
}

Node* find_add_point(List* l, Point* p){
    if( l == NULL || p == NULL)
        return NULL;

    Node* current = l->head;

    while(current != NULL){
        if( compare_points(p, &(current->p)) )
            return current;
        current = current->next;
    }
    return NULL;
}

void print_list(List* l){
    Node* current = l->head;
    while(current != NULL){
        print_point(&(current->p));
        current = current->next;
    }
}

void print_reverse(List* l){
    Node* current = l->tail;
    while(current != NULL){
        print_point(&(current->p));
        current = current->prev;
    }
}

bool insert_first(List* l, int x, int y, int z){
    Node* n = create_node(x,y,z);
    if( n == NULL ) return false;

    // liste vide
    if( l->head == NULL ){
        l->tail = n;
    }
    else{
        l->head->prev = n;
    }
    n->prev = NULL;
    n->next = l->head;
    l->head = n;

    return true;
}

bool insert_end(List* l, int x, int y, int z){
    Node* n = create_node(x,y,z);
    if( n == NULL ) return false;

    // liste vide
    if( l->head == NULL ){
        l->head = n;
    }
    else{
        n->prev = l->tail;
        l->tail->next = n;
    }

    n->next = NULL;
    l->tail = n;
    return true;
} 

bool insert_after(List* l, Point* p, int x, int y, int z){
    Node* n = create_node(x,y,z);
    if( n == NULL ) return false;

    Node* current = find_add_point(l, p);
    if(current == NULL)
        return false;

    n->prev = current;
    n->next = current->next;

    // test si dernier
    if( current->next == NULL ){
        l->tail = n;
    }
    else{
        current->next->prev = n;
    }

    current->next = n;
}

bool insert_before(List* l, Point* p, int x, int y, int z){
    Node* n = create_node(x,y,z);
    if( n == NULL ) return false;

    Node* current = find_add_point(l, p);
    if(current == NULL)
        return false;

    n->next = current;
    n->prev = current->prev;

    // test si premier
    if( current->prev == NULL ){
        l->head = n;
    }
    else{
        current->prev->next = n;
    }

    current->prev = n;
}

bool remove_point(List* l, Point* p){
    Node* to_del = find_add_point(l, p);
    if(to_del == NULL)
        return false;

    bool midlle = true;

    // si premier
    if(to_del == l->head){
        l->head = to_del->next;
        to_del->next->prev = NULL;
        midlle = false;
    }
    // si dernier
    // on ne peut pas utiliser de else if car un élément peut être premier et dernier
    if(to_del == l->tail){
        l->tail = to_del->prev;
        to_del->prev->next = NULL;
        midlle = false;
    }
    
    if(midlle){
        to_del->prev->next = to_del->next;
        to_del->next->prev = to_del->prev;
    }

    free(to_del);
}

bool remove_first(List* l){
    remove_point(l, &l->head->p);
}

bool remove_last(List* l){
    // on ne peut pas utiliser remove_point car il peut y avoir un point identique avant
    if( l->tail == NULL ){
        return false;
    }

    Node* to_del = l->tail;

    // si aussi premier
    if( l->head == l->tail ){
        l->head = NULL;
    }
    else{
        l->tail->prev->next = NULL;
    }
    
    l->tail = to_del->prev; // si c'est le premier, sera NULL
    free(to_del);
}

int main(){
    List maList;

    // dans le programme
    printf("Normal\n");
    insert_first(&maList, 1,2,3);
    insert_first(&maList, 10,20,30);
    print_list(&maList);
    
    printf("Reverse\n");
    print_reverse(&maList);

    printf("Insert end\n");
    insert_end(&maList, 30,-1,-2);
    insert_end(&maList, 10,-1,-2);
    print_list(&maList);

    printf("\nInsert after\n");
    Point p = {.x=10, .y=20, .z=30};
    insert_after(&maList, &p, -1,-2,-3);
    print_list(&maList);
    printf("   reverse\n");
    print_reverse(&maList);

    printf("\nInsert before\n");
    insert_before(&maList, &p, -10,-20,-30);
    insert_before(&maList, &p, -100,-200,-300);
    print_list(&maList);
    
    printf("\nDelete\n");
    Point p1 = {.x=-10, .y=-20, .z=-30};
    remove_point(&maList, &p1);
    Point p2 = {.x=-1, .y=-2, .z=-3};
    remove_point(&maList, &p2);
    Point p3 = {.x=10, .y=-1, .z=-2};
    remove_point(&maList, &p3);
    print_list(&maList);

    printf("\nDelete first\n");
    remove_first(&maList);
    print_list(&maList);

    printf("\nDelete last\n");
    remove_last(&maList);
    print_list(&maList);

    while(remove_last(&maList)){
        printf("\nDelete last\n");
        print_list(&maList);
    }
    return 0;
}