#include <stdio.h>
#include "simple_linked_list.c"

void insertion_sort(SimpleLinkedList *L){
    int i, j;
    for(j = 1; j < L->size; j++){
        int key = getElementByIndex_simpleLinkedList(L, j)->data;
        i = j-1;
        while(i >= 0 && getElementByIndex_simpleLinkedList(L, i)->data > key){
            getElementByIndex_simpleLinkedList(L, i+1)->data = getElementByIndex_simpleLinkedList(L, i)->data;
            i = i-1;
        }
        getElementByIndex_simpleLinkedList(L, i+1)->data = key;
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

    insertion_sort(list);
    printf("\nLista ordenada: ");
    print_simpleLinkedList(list);

    return 0;
}