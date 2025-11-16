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
void insert_begin(LinkedList *list, int data);
void insert_end(LinkedList *list, int data);
void insert_at(LinkedList *list, int data, int position);

// Eliminación
int delete_element(LinkedList *list, int data);
int delete_at(LinkedList *list, int position);

// Búsqueda y acceso
int search_element(const LinkedList *list, int data);
int get_at(const LinkedList *list, int position);

// Utilidades
void print_list(const LinkedList *list); // Imprime la lista
int is_empty_list(const LinkedList *list); // Verifica si la lista está vacía
int get_size_list(const LinkedList *list); // Obtiene el tamaño de la lista

#endif