#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    unsigned int i = 0;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 5;
    //
    while (i < length) {
        if (value > arr[i] && (res.is_lowerbound == true)) {
            res.is_lowerbound = false;  
        }
        if (value < arr[i] && (res.is_upperbound == true)) {
            res.is_upperbound = false;  
        }
        if (arr[i] == value && res.exists == false) {
            res.exists = true;
            res.where = i;
        } 
        i++;
    }

    //
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    int i = 0;
    //
    // TODO: COMPLETAR - Pedir entrada al usuario
    // ingresar numeros para el array, usar un for o while
    while (ARRAY_SIZE > i) {
        printf("Ingrese un numero entero: ");
        scanf("%d", &a[i]);
        i++;
    }
    
    //
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d", result.is_upperbound); // Imprime 1
    printf("%d", result.is_lowerbound); // Imprime 0
    printf("%u", result.exists);        // Imprime 1

    if (result.where == 5) {
        printf(" El valor no existe en el array.\n");
    } else {
        printf("%u", result.where);         // Imprime 2
    }

    return EXIT_SUCCESS;
}

