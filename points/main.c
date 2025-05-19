// Pour compiler : gcc main.c array.c -oapp && ./app

#include <stdio.h>
#include "array.h"

int main(){
    // bonne solution
    PointArray* a = create_array(10);

    // plus simple
    //Array a;
    //create_array(&a, 10);

    insert_first(a, 1,2);
    insert_first(a, 4, 5);
    insert_first(a, 10, 20);
    printf("1\n");
    print_array(a);

    remove_first(a);
    printf("2\n");
    print_array(a);
    
    remove_first(a);
    printf("3\n");
    print_array(a);
    
    remove_first(a);
    printf("%s", "Ne doit pas afficher ce message");
}