#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


//crear el stack
Stack* create_stack(int cap) { 
    //hederguard 
    if (cap <= 0) {
        printf("ERROR>> capacidad invalida, debe de ser mayor a 0\n");
        return NULL;
    }
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        printf("ERROR>> no se pudo asignar memoria para la pila\n");
        return NULL;
    }
    stack->items = (int *)malloc(cap * sizeof(int));
    if (!stack->items) {
        printf("ERROR>> no se pudo asignar memoria para los elementos de la pila\n");
        free(stack);
        return NULL;
    }
    stack->capacity = cap;
    stack->top = -1; // Indica que la pila está vacía
    printf("pila creada con capacidad de %d\n", cap);
    return stack;
}
//liberar memoria del stack
void free_stack(Stack *stack) {
    if(!stack) {
        printf("ERROR>> no hay pila\n");
        return;
    }   
    if (stack) {
        free(stack->items);
        free(stack);
        printf("pila liberada de memoria\n");
    }
}
//push>agregar elemento al tope del stack
void push(Stack *stack, int item) {
    //hederguard
    if(!stack) {
        printf("ERROR>> no hay pila\n");
        return;
    }
    
    if (stack->top == stack->capacity - 1) {
        //redimensionar la pila
        int new_capacity = stack->capacity * 2;
        int *new_items = (int *)realloc(stack->items, new_capacity * sizeof(int));
        if (!new_items) {
            printf("ERROR>> no se pudo redimensionar la pila\n");
            return; // No se pudo redimensionar
        }
        stack->items = new_items;
        stack->capacity = new_capacity;
        printf("pila redimensionada a capacidad de %d\n", new_capacity);
    }
    stack->top++;
    stack->items[stack->top] = item;    
    printf("elemento %d ha sido pusheado \n", item);
}
//is_empty> verifica si la pila está vacía
bool is_empty(const Stack *stack) {
    //hederguard
    if(!stack) {
        printf("ERROR>> no hay pila\n");
        return true; // Considerar pila inexistente como vacía
    }
    return (stack->top == -1);
}
//pop> eliminar y devolver el elemento en el tope del stack
int pop(Stack *stack) {
    //hederguard
    if(!stack) {
        printf("ERROR>> no hay pila\n");
        return -1; // Valor inválido
    }
    if (is_empty(stack)) {
        printf("ERROR>> pila vacia, no se puede hacer pop\n");
        return -1; // Valor inválido
    }
    int item = stack->items[stack->top];
    stack->top--;
    printf("elemento %d ha sido popeado \n", item);
    return item;
}
//peek> devolver el elemento en el tope del stack sin eliminarlo
int peek(const Stack *stack) {
    //hederguard
    if(!stack) {
        printf("ERROR>> no hay pila\n");
        return -1; // Valor inválido
    }
    if (is_empty(stack)) {
        printf("ERROR>> pila vacia, no se puede hacer peek\n");
        return -1; // Valor inválido
    }
    int item = stack->items[stack->top];
    printf("elemento del tope es %d\n", item);
    return item;
}