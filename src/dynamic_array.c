#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
//crear arreglo dinamico
DynamicArray* create_array() {
    DynamicArray *da = (DynamicArray *)malloc(sizeof(DynamicArray));
    da->size = 0;
    da->capacity = 2; // Capacidad inicial
    da->array = (int *)malloc(da->capacity * sizeof(int));
    
    printf("arreglo creado con capacidad de  %d\n", da->capacity);
    return da;
}

//agregar elemento al arreglo dinamico
void add_element(DynamicArray *da, int element) {
       if (da == NULL) {
        printf("ERROR>>no hay arreglo\n");
        return;
    }
    if (da->size == da->capacity) { // Redimensionar si es necesario
        int new_capacity = da->capacity * 2;
        int *new_array = (int *)realloc(da->array, new_capacity * sizeof(int));
        da->array = new_array;
        da->capacity = new_capacity;
        printf("arreglo redimensionado a capacidad de %d\n", da->capacity);
    }
    da->array[da->size++] = element;
    printf("elemento %d agregado al arreglo\n", element);
}
//eliminar elemento del arreglo dinamico
void remove_element(DynamicArray *da, int index) {//index elemento a eliminar
    if (da == NULL) {
        printf("ERROR>>no hay arreglo\n");
        return;
    }
    if (index < 0 || index >= da->size) { //caso cuando es -1 o mayor al size
        printf("índice fuera de rango\n");
        return;
    }
    
    for (int i = index; i < da->size - 1; i++) {
        da->array[i] = da->array[i + 1];
    }
    da->size--;
    printf("elemento en índice %d eliminado del arreglo\n", index);
}

//obtener elemento del arreglo dinamico
int get_element(const DynamicArray *da, int index) {
    if (da == NULL) {
        printf("ERROR>>no hay arreglo\n");
        return -1; // Valor inválido
    }
    if (index < 0 || index >= da->size) { //mismo headerguard del rango 
        printf("índice fuera de rango\n");
        return -1; // Valor inválido
    }
    
    return da->array[index]; // Retorna el elemento en el índice dado
}

//imprimir arreglo dinamico
void print_array(const DynamicArray *da) {
    if (da == NULL) {
        printf("ERROR>>no hay arreglo\n");
        return;
    }
    if (da->size == 0) {
        printf("arreglo vacío\n");
        return;
    }
    printf("Elementos en el arreglo dinámico: ");
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da->array[i]);
    }
    printf("\n");
}  

//liberar el espacio del arreglo dinamico
void free_array(DynamicArray *da) {
    if (da != NULL) {
        free(da->array);  // Liberar el arreglo interno primero
        free(da);         // Liberar la estructura
        printf("Arreglo dinámico liberado\n");
    }
}