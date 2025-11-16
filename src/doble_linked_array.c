#include <stdio.h>
#include <stdlib.h>
#include "doble_linked_array.h"

//crear lista doblemente enlazada
DoublyLinkedList* create_doubly_linked_list() { 
    DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    if (!list) {// en caso de que no se pueda asignar memoria 
        printf("ERROR>>no se pudo asignar la memoria\n");
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    printf("Lista doblemente enlazada creada\n");
    return list;
}
//liberar memoria de la lista doblemente enlazada  
void free_doubly_linked_list(DoublyLinkedList *list) {
    if (!list) {
        printf("ERROR>>no hay lista para liberar\n");
        return;
    }
    DNode *current = list->head;
    DNode *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
    printf("Memoria de la lista doblemente enlazada liberada\n");
}
//insertar en una posicion especifica de la lista doblemente enlazada
void insert_at_dll(DoublyLinkedList *list, int data, int position) {
    //header guard
    if (!list) {
        printf("ERROR>>no hay lista para insertar\n");
        return;
    }
    if (position < 0 || position > list->size) {
        printf("posición fuera de rango\n");
        return;
    }
    
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    if(!new_node) {
        printf("ERROR>>no se pudo crear el nuevo nodo\n");
        return;
    }
    //al inicio de la lista
    if (position == 0) {
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = list->head;
        if (list->head != NULL) {
            list->head->prev = new_node;
        }
        list->head = new_node;
        if (list->tail == NULL) {   
            list->tail = new_node;
        }
        list->head = new_node;
        list->size++;
        return;
    }
    //al final de la lista
    if (position == list->size) {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = list->tail;
        if (list->tail != NULL) {
            list->tail->next = new_node;
        }
        list->tail = new_node;
        if (list->head == NULL) {
            list->head = new_node;
        }
        list->tail = new_node;
        list->size++;
        return;
    }
    //en el medio de la lista
    DNode *tempactu = list->head;//nodo en la pos anterior
    for (int i = 0; i < position - 1; i++) {
        tempactu = tempactu->next;
    }
    
    
    //asignacion de punteros y datos
    new_node->data = data;
    new_node->prev = tempactu;
    new_node->next = tempactu->next;
    tempactu->next->prev = new_node;
    tempactu->next = new_node;
    list->size++;
}
