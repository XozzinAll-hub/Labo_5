#include "linked_array.h"
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
//eliminar elemento basado en data
int delete_element(LinkedList *list, int data) {
    //headersguard
    if (list == NULL) {
        printf("ERROR>>no hay lista enlazada\n");
        return -1;
    }
    Node *tempactu= list->head;
    Node *tempprev = NULL;
    while (tempactu != NULL) {
        if (tempactu->data == data) {
            if (tempprev == NULL) { // Eliminar el primer nodo
                list->head = tempactu->next;
            } else {
                tempprev->next = tempactu->next;
            }
            free(tempactu);
            list->size--;
            printf("elemento %d eliminado de la lista enlazada\n", data);
            return data; // Retorna el dato eliminado
        }
        tempprev = tempactu;
        tempactu = tempactu->next;
    }
    printf("elemento %d no encontrado en la lista enlazada\n", data);
    return -1; // Valor inválido si no se encuentra el elemento
}
//buscar elemento en la lista enlazada
int search_element(const LinkedList *list, int data) {
    //headersguard
    if (list == NULL) {
        printf("ERROR>>no hay lista enlazada\n");
        return -1;
    }
    Node *tempactu = list->head;
    int position = 0;

    while (tempactu != NULL) {
        if (tempactu->data == data) {
            printf("elemento %d encontrado en la posición %d\n", data, position);
            return position; // Retorna y termina el while
        }
        tempactu = tempactu->next;
        position++;
    }
    // tempactu == NULL es un error 
    printf("elemento %d no encontrado en la lista enlazada\n", data);
    return -1; // Valor inválido si no se encuentra el elemento
}
//imprimir lista enlazada
void print_list(const LinkedList *list) {
    //headersguard
    if (list == NULL) {
        printf("ERROR>>no hay lista enlazada\n");
        return;
    }
    if (list->head == NULL)
        printf("lista enlazada vacía\n");
        return;     
    
    if (list->size == 0) {
        printf("lista enlazada vacía\n");
        return;
    }
    printf("tamanio de la lista %d", list->size);
    Node *tempactu = list->head;
    while (tempactu != NULL) {
        printf(" -> %d", tempactu->data);
        tempactu = tempactu->next;
    }
    printf("\n");
}