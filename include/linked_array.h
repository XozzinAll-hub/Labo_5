#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Nodo de la lista
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Estructura principal de la lista
typedef struct {
    Node *head;
    int size;
} LinkedList;

// Creación y destrucción
LinkedList* create_linked_list();
void free_list(LinkedList *list);

// Inserción
void insert_at(LinkedList *list, int data, int position);

// Eliminación
int delete_element(LinkedList *list, int data);

// Búsqueda y acceso
int search_element(const LinkedList *list, int data);
// Utilidades
void print_list(const LinkedList *list); // Imprime la lista

#endif