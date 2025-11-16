#include <stdio.h>
#include "dynamic_array.h"

void prueba_dynamic_array() {
    printf("Testeo de las implementaciones del arreglo dinamico\n");
    
    // Crear arreglo
    DynamicArray *da = create_array();
    
    // Agregar elementos
    printf("\n -> Agregando elementos (10, 20, 30, ....)\n");
    for (int i = 1; i <= 10; i++) {
        add_element(da, i * 10); // Agrega 10, 20, ..., 100
        print_array(da);
    }
    
    // Obtener elementos
    printf("\n -> Obtener los elementos de cada posicion que se inserto \n");
    for (int i = 0; i < get_size(da); i++) {
        int element = get_element(da, i);
        printf("Elemento en posición %d: %d\n", i, element);
    }
    
    // Eliminar elementos
    printf("\n -> Eliminar elementos (en los espacios 0, 4 y el ultimo)\n");
    remove_element(da, 0);  // Eliminar primero
    print_array(da);
    remove_element(da, 4);  // Eliminar del medio
    print_array(da);
    remove_element(da, get_size(da) - 1);  // Eliminar último
    print_array(da);
    
    // Probar casos de error por "out range"
    printf("\n -> Probando casos de error de un indice invalido \n");
    get_element(da, 100);  // Índice inválido, maximo deseado es de 10 
    remove_element(da, 100); // misma razon que el anterior
    
    // Liberar memoria
    free_array(da);
}

int main() {
    prueba_dynamic_array();
    return 0;
}