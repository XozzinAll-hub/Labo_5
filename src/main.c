#include <stdio.h>
#include "dynamic_array.h"
#include "linked_array.h"
#include "doble_linked_array.h"


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
void prueba_linked_array(){
    //crar la lista enlazada
    LinkedList *list = create_linked_list();

    //insertar elementos en la posicion 0 varias veces
    printf("\n -> Insertando elementos al inicio de la lista enlazada (0, 10, 20, 30, ...)\n");
    for (int i = 0; i < 3; i++) {
        insert_at(list, i * 10 , 0); // Inserta 0, 10, 20, 30 al inicio
        print_list(list);
    }
    //insertar elementos al final de la lista enlazada
    printf("\n -> Insertando elementos al final de la lista enlazada (40, 50, 60 ...)\n");
    for (int i = 4; i < 7; i++) {
        insert_at(list, i * 10 , list->size); // Inserta 40, 50, 60 al final
        print_list(list);
    }
    //insertar elementos en la posicion media de la lista enlazada
    printf("\n -> Insertando elementos en la posicion media de la lista enlazada (25, 35)\n");
    insert_at(list, 25 , 2); // Inserta 25 en la posicion 2
    print_list(list);
    insert_at(list, 35 , 4); // Inserta 35 en la posicion 4
    print_list(list);
    //buscar elementos en la lista enlazada
    printf("\n -> Buscando elementos en la lista enlazada (10, 35, 100)\n");
    search_element(list, 10); // Buscar 10
    search_element(list, 35); // Buscar 35
    search_element(list, 100); // Buscar 100 (no existe)
    //eliminar elementos en la lista enlazada
    printf("\n -> Eliminando elementos en la lista enlazada (0, 35, 100)\n");
    delete_element(list, 0); // Eliminar 0
    print_list(list);
    delete_element(list, 35); // Eliminar 35
    print_list(list);
    delete_element(list, 100); // Eliminar 100 (no existe) 
    //liberar memoria
    free_list(list); 
}



void prueba_doble_linked_array() {
    printf("Testeo de las implementaciones de la lista doblemente enlazada\n");
    
    // Crear lista doblemente enlazada
    DoublyLinkedList *dll = create_doubly_linked_list();
    
    // Insertar elementos en el inicio
    printf("\n -> Insertando elementos (10, 20, 30, ....) en el inicio\n");
    for (int i = 1; i <= 3; i++) {
        insert_at_dll(dll, i * 10, 0); // Inserta 10, 20, 30 al inicio
        print_forward_dll(dll);
    }
    //insertar elementos al final
    printf("\n -> Insertando elementos (40, 50, 60, ....) al final\n");
    for (int i = 4; i <= 6; i++) {
        insert_at_dll(dll, i * 10, dll->size); // Inserta 40, 50, 60 al final
        print_backward_dll(dll); // Imprime hacia atras para verificar
    }
    //insertar elementos en el medio
    printf("\n -> Insertando elementos (25, 35, 45) en el medio\n");
    insert_at_dll(dll, 25, 2); // Inserta 25 en la posición 2
    print_forward_dll(dll);
    insert_at_dll(dll, 35, 4); // Inserta 35 en la posición 4
    print_forward_dll(dll);
    insert_at_dll(dll, 45, 6); // Inserta 45 en la posición 6
    print_forward_dll(dll);
    
    
    // Eliminar elementos
    printf("\n -> Eliminando elementos (10, 35, 60)\n");
    delete_element_dll(dll, 10);  // Elimina 10
    print_forward_dll(dll);
    delete_element_dll(dll, 35);  // Elimina 35
    print_forward_dll(dll);
    delete_element_dll(dll, 60);  // Elimina 60
    print_forward_dll(dll);
    
    // Probar caso de error al eliminar un elemento no existente
    printf("\n -> Probando caso de error al eliminar un elemento no existente (100)\n");
    delete_element_dll(dll, 100);  // Elemento no existente
    
    // Liberar memoria
    free_doubly_linked_list(dll);
}
int main() {
    prueba_dynamic_array();
    prueba_doble_linked_array();
    prueba_linked_array();
    return 0;
}