#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima_log(int a[], int length) {
    // COMPLETAR!! 
    int lft= 0;
    int rgt = length - 1;

    // Utilizamos una búsqueda binaria modificada.
    // El invariante es que la cima siempre está dentro del rango [low, high].
    while (lft < rgt) {
        // Calculamos el punto medio para evitar desbordamiento
        int mid = lft + (rgt - lft) / 2;

        // Comparamos el elemento central con su vecino derecho.
        // Si a[mid] < a[mid+1], estamos en la parte creciente de la secuencia.
        // La cima debe estar a la derecha de mid (incluyendo mid+1).
        if (a[mid] < a[mid + 1]) {
            lft = mid + 1;
        }
        // Si a[mid] > a[mid+1], estamos en la parte decreciente o en la propia cima.
        // La cima debe estar en mid o a la izquierda de mid.
        // Mantenemos 'mid' en el rango porque podría ser la cima.
        else {
            rgt = mid;
        }
    }

    // Cuando low == high, hemos encontrado el índice de la cima.
    // El bucle termina porque el espacio de búsqueda se reduce en cada paso
    // y la cima está garantizada a existir dentro del rango [low, high].
    return lft; // o high, ya que son iguales en este punto.
}
