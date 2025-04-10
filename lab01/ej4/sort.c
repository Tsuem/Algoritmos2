#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i, unsigned int length) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
    int j= i;
    assert(i < length);

    while (j > 0 && a[j] < a[j-1]) {
        swap(a, j-1, j);
        j = j-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
    for (unsigned int i = 0; i < length; ++i) {
        insert(a, i, length);

        // Verificación de invariante: comprobar que a[0..i] está ordenado
        assert(array_is_sorted(a, i + 1));
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    int ppiv = izq;
   int i = izq + 1;
   int j = der;

   while (i <= j) {
    if (a[i] <= a[ppiv]) {
        i++;
    } else if (a[j] >= a[ppiv]) {
        j--;
    } else {
        swap(a, i, j);
    }
   }
   swap(a, ppiv, j);
   return j;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 2 */
    unsigned int ppiv;
   if (der > izq) {
    ppiv = partition(a, izq, der);
    quick_sort_rec(a, izq, ppiv - 1);
    quick_sort_rec(a, ppiv + 1, der);
   }
}

void quick_sort(int a[], unsigned int length) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
