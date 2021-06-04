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

void merge_sort(simple_linked_list *list, unsigned p, unsigned r);
void merge(simple_linked_list *list, unsigned p, unsigned q, unsigned r);

// --- Definitions ---

void merge_sort(simple_linked_list *list, unsigned p, unsigned r){
    if(p < r){
        unsigned q = (p+r)/2;
        merge_sort(list, p, q);
        merge_sort(list, q+1, r);
        merge(list, p, q, r);
    }
}

void merge(simple_linked_list *list, unsigned p, unsigned q, unsigned r){
    unsigned n_1 = q-p+1, n_2 = r-q;
    unsigned i, j, k;

    simple_linked_list *list_L = new_simple_linked_list();
    for(i = 1; i <= n_1; i++){
        insert_to(list_L, new_node(get_element(list, p+i-1)->data));
    }
    simple_linked_list *list_R = new_simple_linked_list();
    for(j = 1; j <= n_2; j++){
        insert_to(list_R, new_node(get_element(list, q+j)->data));
    }

    insert_to(list_L, new_node(INFINITY));
    insert_to(list_R, new_node(INFINITY));
    i = 0;
    j = 0;

    for(k = p; k <= r; k++){
        if(get_element(list_L, i)->data <= get_element(list_R, j)->data){
            get_element(list, k)->data = get_element(list_L, i)->data;
            i++;
        }else{
            get_element(list, k)->data = get_element(list_R, j)->data;
            j++;
        }
    }
}

// --- Test ---

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

    merge_sort(list, 0, list->size-1);
    printf("\nLista ordenada: ");
    print_simple_linked_list(list);

    return 0;
}