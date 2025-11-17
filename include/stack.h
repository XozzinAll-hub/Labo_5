#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *items;      // Arreglo para almacenar elementos
    int top;         // Índice del tope
    int capacity;    // Capacidad máxima
} Stack;

// Creación y destrucción
Stack* create_stack(int capacity);
void free_stack(Stack *stack);

// Operaciones de pila
void push(Stack *stack, int item);//agregar elemento al tope
int pop(Stack *stack); // eliminar y devolver el elemento en el tope
int peek(const Stack *stack); // devolver el elemento en el tope sin eliminarlo

// Verificación de estado
bool is_empty(const Stack *stack); //verifica si la pila está vacía

#endif