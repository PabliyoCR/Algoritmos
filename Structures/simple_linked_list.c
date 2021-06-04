// --- Nodes ---

typedef struct node_simple_linked_list node_simple_linked_list;
typedef struct simple_linked_list simple_linked_list;

struct node_simple_linked_list
{
    int data;
    node_simple_linked_list *next;
};

struct simple_linked_list
{
    int size;
    node_simple_linked_list *start;
};

// ---Declarations ---

node_simple_linked_list *new_node_simple_linked_list(int data);
simple_linked_list *new_simple_linked_list();
void insertion_on_simple_linked_list(simple_linked_list *list, node_simple_linked_list *node);
void insertion_as_last_element_on_simple_linked_list(simple_linked_list *list, node_simple_linked_list *node);
node_simple_linked_list *get_element_by_index_on_simple_linked_list(simple_linked_list *list, int idx);
void print_simple_linked_list(simple_linked_list *list);

// --- Definition ---

node_simple_linked_list *new_node_simple_linked_list(int data){
    node_simple_linked_list *node;
    node = (node_simple_linked_list *) malloc(sizeof(node_simple_linked_list));
    node->data = data;
    node->next = NULL;
    return node;
}

simple_linked_list *new_simple_linked_list(){
    simple_linked_list *list;
    list = (simple_linked_list *) malloc(sizeof(simple_linked_list));
    list->size = 0;
    list->start = NULL;
    return list;
}

void insertion_on_simple_linked_list(simple_linked_list *list, node_simple_linked_list *node){
    if(list->start == NULL){
        list->start = node;
    }else{
        node->next = list->start;
        list->start = node;
    }
    list->size++;
}

void insertion_as_last_element_on_simple_linked_list(simple_linked_list *list, node_simple_linked_list *node){
    if(list->start == NULL){
        list->start = node;
    }else{
        node_simple_linked_list *aux = list->start;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    list->size++;
}

node_simple_linked_list *get_element_by_index_on_simple_linked_list(simple_linked_list *list, int idx){
    node_simple_linked_list *node;
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

void print_simple_linked_list(simple_linked_list *list){
    node_simple_linked_list *node;
    for(node = list->start; node != NULL; node = node->next){
        printf("%i ", node->data);
    }
    printf("\n");
}









