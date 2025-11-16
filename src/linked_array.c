#include "linkled_array.h"
//crear lista enlazada
LinkedList* create_linked_list() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    printf("lista enlazada creada\n");
    return list;
}  
//crear nodo
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    printf("nodo creado con dato %d\n", data);
    return new_node;
}

//liberar memoria de la lista enlazada
void free_list(LinkedList *list) {
    Node *current = list->head;
    Node *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
    printf("memoria de la lista enlazada liberada\n");
}   

//insertar en una posicion especifica
void insert_at(LinkedList *list, int data, int position) {
    //headersguards
    if (list == NULL){  
        printf("ERROR>>no hay lista enlazada\n");
        return; 
    }
     
    if (position < 0 || position > list->size) {
        printf("posición fuera de rango\n");
        return;
    }
    Node *new_node = create_node(data);
    if (position == 0) { // Insertar al inicio
        new_node->next = list->head;
        list->head = new_node;
    }
    if (position == list->size) { // Insertar al final
        if (list->head == NULL) {
            list->head = new_node;
        } else {
            Node *current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    } else { // Insertar en el medio
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    list->size++;
    printf("elemento %d insertado en la posición %d\n", data, position);
}  
