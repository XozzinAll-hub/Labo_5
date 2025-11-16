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
    if (da->size == da->capacity) { // Redimensionar si es necesario
        da->capacity *= 2;
        da->array = (int *)realloc(da->array, da->capacity * sizeof(int));
        printf("arreglo redimensionado a capacidad de %d\n", da->capacity);
    }
    da->array[da->size++] = element;
    printf("elemento %d agregado al arreglo\n", element);
}
//eliminar elemento del arreglo dinamico
void remove_element(DynamicArray *da, int index) {//index elemento a eliminar
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