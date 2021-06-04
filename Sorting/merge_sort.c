#include <stdio.h>
#include "../Structures/simple_linked_list.c"
#include <math.h>


void merge_sort(SimpleLinkedList *list, unsigned p, unsigned r){
    if(p < r){
        unsigned q = (p+r)/2;
        merge_sort(list, p, q);
        merge_sort(list, q+1, r);
        merge(list, p, q, r);
    }
}

void merge(SimpleLinkedList *list, unsigned p, unsigned q, unsigned r) {
    unsigned n_1 = q-p+1, n_2 = r-q;
    unsigned i, j, k;

    SimpleLinkedList *list_L = newSimpleLinkedList();
    for(i = 1; i <= n_1; i++){
        insertionAsLastElement_simpleLinkedList(list_L, newNodeSimpleLinkedList(getElementByIndex_simpleLinkedList(list, p+i-1)->data));
    }
    SimpleLinkedList *list_R = newSimpleLinkedList();
    for(j = 1; j <= n_2; j++){
        insertionAsLastElement_simpleLinkedList(list_R, newNodeSimpleLinkedList(getElementByIndex_simpleLinkedList(list, q+j)->data));
    }

    insertionAsLastElement_simpleLinkedList(list_L, newNodeSimpleLinkedList(INFINITY));
    insertionAsLastElement_simpleLinkedList(list_R, newNodeSimpleLinkedList(INFINITY));
    i = 0;
    j = 0;

    for(k = p; k <= r; k++){
        if(getElementByIndex_simpleLinkedList(list_L, i)->data <= getElementByIndex_simpleLinkedList(list_R, j)->data){
            getElementByIndex_simpleLinkedList(list, k)->data = getElementByIndex_simpleLinkedList(list_L, i)->data;
            i++;
        }else{
            getElementByIndex_simpleLinkedList(list, k)->data = getElementByIndex_simpleLinkedList(list_R, j)->data;
            j++;
        }
    }
}

int main(){

    SimpleLinkedList *list = newSimpleLinkedList();

    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(1));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(2));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(9));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(5));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(6));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(4));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(8));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(0));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(7));
    insertion_simpleLinkedList(list, newNodeSimpleLinkedList(3));

    printf("\nLista desordenada: ");
    print_simpleLinkedList(list);

    merge_sort(list, 0, list->size-1);
    printf("\nLista ordenada: ");
    print_simpleLinkedList(list);

    return 0;
}