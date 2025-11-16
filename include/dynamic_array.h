#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;      // Puntero al arreglo dinámico
    int size;        // Número de elementos actuales
    int capacity;    // Capacidad total del arreglo
} DynamicArray;

// Creación y destrucción
DynamicArray* create_array();
void free_array(DynamicArray *da);

// Operaciones básicas
void add_element(DynamicArray *da, int element);
void remove_element(DynamicArray *da, int index);
void get_element(const DynamicArray *da, int index);

// Utilidades
void print_array(const DynamicArray *da);
#endif