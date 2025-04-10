#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    int ppiv = izq;
    int i = izq + 1;
    int j = der;

    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i++;
        } else if (goes_before(a[ppiv], a[j])) {
            j--;
        } else {
            swap(a, i, j);
        }
    }
    swap(a, ppiv, j);
    return j;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int ppiv;
    if (der > izq) {
        ppiv = partition(a, izq, der);
        // Solo llamar si hay elementos a la izquierda del pivote
        if (ppiv > izq) {
            quick_sort_rec(a, izq, ppiv - 1);
        }
        // La llamada derecha suele ser segura si ppiv <= der
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}