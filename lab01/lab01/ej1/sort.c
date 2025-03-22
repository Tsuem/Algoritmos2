#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    /* needs implementation */
    int j= i;
    assert(i < length);

    // pag 59 de las filminas de clase, ordenacion por insercion
    while (j > 0 && a[j] < a[j-1]) {
        swap(a, j-1, j);
        j = j-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        insert(a, i, length);

        // Verificación de invariante: comprobar que a[0..i] está ordenado
        assert(array_is_sorted(a, i + 1));
    }
}
