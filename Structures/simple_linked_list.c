#include <stdio.h>

typedef struct NodeSimpleLinkedList NodeSimpleLinkedList;
typedef struct SimpleLinkedList SimpleLinkedList;

struct NodeSimpleLinkedList
{
    int data;
    NodeSimpleLinkedList *next;
};

struct SimpleLinkedList
{
    int size;
    NodeSimpleLinkedList *start;
};

// Definition

NodeSimpleLinkedList *newNodeSimpleLinkedList(int data){

    NodeSimpleLinkedList *node;
    node = (NodeSimpleLinkedList *) malloc(sizeof(NodeSimpleLinkedList));
    node->data = data;
    node->next = NULL;
    return node;
}

SimpleLinkedList *newSimpleLinkedList()
{
    SimpleLinkedList *list;
    list = (SimpleLinkedList *) malloc(sizeof(SimpleLinkedList));
    list->size = 0;
    list->start = NULL;
    return list;
}

void insertion_simpleLinkedList(SimpleLinkedList *list, NodeSimpleLinkedList *node){
    if(list->start == NULL){
        list->start = node;
    }else{
        node->next = list->start;
        list->start = node;
    }
    list->size++;
}

void insertionAsLastElement_simpleLinkedList(SimpleLinkedList *list, NodeSimpleLinkedList *node){
    if(list->start == NULL){
        list->start = node;
    }else{
        NodeSimpleLinkedList *aux = list->start;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    list->size++;
}

NodeSimpleLinkedList *getElementByIndex_simpleLinkedList(SimpleLinkedList *list, int idx){
    NodeSimpleLinkedList *node;
    if(list->start == NULL || idx >= list->size){
        return NULL;
    }else{
        node = list->start;
        int counter = 0;
        while (node != NULL)
        {
            if(counter == idx){
                return node;
            }
            counter++;
            node = node->next;
        }
    }
}

void print_simpleLinkedList(SimpleLinkedList *list){
    NodeSimpleLinkedList *node;
    for(node = list->start; node != NULL; node = node->next){
        printf("%i ", node->data);
    }
    printf("\n");
}









