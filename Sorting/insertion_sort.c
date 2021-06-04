// --- Librerías Standard ---

#include <stdio.h>
#include <math.h>

// ---Módulos Externos ---

#include "../Structures/simple_linked_list.c"

// --- External Functions Alias ---

#define insert_to(x, y) insertion_as_last_element_on_simple_linked_list(x, y)
#define new_node(x) new_node_simple_linked_list(x)
#define get_element(x, y) get_element_by_index_on_simple_linked_list(x, y)

// ---Declarations ---


// --- Definitions ---

void insertion_sort(simple_linked_list *L){
    int i, j;
    for(j = 1; j < L->size; j++){
        int key = get_element(L, j)->data;
        i = j-1;
        while(i >= 0 && get_element(L, i)->data > key){
            get_element(L, i+1)->data = get_element(L, i)->data;
            i = i-1;
        }
        get_element(L, i+1)->data = key;
    }
}

int main(){

    simple_linked_list *list = new_simple_linked_list();    
    insert_to(list, new_node(3));
    insert_to(list, new_node(7));
    insert_to(list, new_node(0));
    insert_to(list, new_node(8));
    insert_to(list, new_node(4));
    insert_to(list, new_node(6));
    insert_to(list, new_node(5));
    insert_to(list, new_node(9));
    insert_to(list, new_node(2));
    insert_to(list, new_node(1));

    printf("\nLista desordenada: ");
    print_simple_linked_list(list);

    insertion_sort(list);
    printf("\nLista ordenada: ");
    print_simple_linked_list(list);

    return 0;
}