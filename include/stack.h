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
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(const Stack *stack);

// Verificación de estado
bool is_empty(const Stack *stack);
bool is_full(const Stack *stack);
int get_size_stack(const Stack *stack);

#endif