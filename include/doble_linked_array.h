#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Nodo doble
typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Estructura principal
typedef struct {
    DNode *head;
    DNode *tail;
    int size;
} DoublyLinkedList;

// Creación y destrucción
DoublyLinkedList* create_doubly_linked_list();
void free_doubly_linked_list(DoublyLinkedList *list);

// Inserción
void insert_begin_dll(DoublyLinkedList *list, int data);
void insert_end_dll(DoublyLinkedList *list, int data);
void insert_at_dll(DoublyLinkedList *list, int data, int position);

// Eliminación
int delete_element_dll(DoublyLinkedList *list, int data);
int delete_at_dll(DoublyLinkedList *list, int position);

// Búsqueda y acceso
int search_element_dll(const DoublyLinkedList *list, int data);
int get_at_dll(const DoublyLinkedList *list, int position);

// Navegación
void print_forward_dll(const DoublyLinkedList *list);
void print_backward_dll(const DoublyLinkedList *list);

// Utilidades
int is_empty_dll(const DoublyLinkedList *list);
int get_size_dll(const DoublyLinkedList *list);

#endif