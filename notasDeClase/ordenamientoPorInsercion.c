#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Mueve los elementos del arreglo que son mayores que 'key' una posición hacia adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Inserta 'key' en su posición correcta
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);

    return 0;
}

/* ¿Cómo funciona este código?
1.- Arreglo original: Tenemos un arreglo desordenado.
2.- Iteración: Comenzamos desde el segundo elemento y lo insertamos en su posición correcta dentro del subconjunto ordenado. 
3.- Salida: Después de ejecutar el programa, verás el arreglo ordenado en orden ascendente. */