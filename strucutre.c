#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// on peut définir des types
typedef int MonType;

struct Measure_long{
    int id; // on ne peut pas init ici = 0
    double value;
};

typedef struct MeasureN{ // structure nommée
    int id;
    double value;
} MeasureN;

typedef struct{ // structure nommée
    int id;
    double value;
} Measure;

typedef struct{
    int age;
    char name[50];
    char firstname[50];
} Person;

void set_meas(Measure m){ // passage par copie
    printf("Mesure : %d\n", m.id);
    m.id = 21;
}

void print_measure(Measure* m){
    int id_long = (*m).id; // version longue
    int id = m->id; // permet d'acceder aux champs avec un pointeur
    printf("id : %d  /  value : %.2lf\n", m->id, m->value);
}

void create_measure(Measure* m, int id, double value){
    if( m != NULL && id > 0 )
        m->id = id;
        m->value = value;
}

// exemple sur les points
typedef struct Point{
    int x;
    int y;
} Point;

Point create_point(int x, int y){
    Point p = {x, y};
    return p;
}

void print_point(Point* p){
    printf("Point : (%d, %d)\n", p->x, p->y);
}

Point add_point(Point* p1, Point* p2){
    Point p = {p1->x + p2->x, p1->y + p2->y};
    return p;
}

bool comp_point(Point* p1, Point* p2){
    // return p1->x == p2->x && p1->y == p2->y;
    return memcmp(p1, p2, sizeof(Point)) == 0;
}

int main()
{
    MonType a = 12;

    // version longue
    struct Measure_long m1 = {.id=1, .value=0.0};
    
    Measure m2 = {.id=2, .value=-5.0};
    Measure m3;
    create_measure(&m2, 1, 23.4);
    create_measure(&m3, 2, -1e-4);
    
    printf("id %d", m2.id);


    // Les points
    Point p1 = create_point(1, 2);
    Point p2 = create_point(3, 4);
    Point p3 = add_point(&p1, &p2);
    print_point(&p3);
    return 0;
}