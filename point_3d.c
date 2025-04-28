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
        return -1;

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

bool insert_after(List* l, Point* p){
    Node* current = find_add_point(l, p);
    if(current == NULL)
        return false;

    
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
    return 0;
}