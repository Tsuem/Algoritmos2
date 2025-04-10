#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    int i = 0;
    
    while (s[i] != '\0') {
        i++;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    unsigned int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
         // Opcional: chequeo de FIXSTRING_MAX
         // if (i >= FIXSTRING_MAX) break; 
    }
    // Son iguales si ambos caracteres actuales son el terminador NUL
    return s1[i] == '\0' && s2[i] == '\0';
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
    unsigned int i = 0;
    // Itera mientras ambos caracteres sean iguales y ninguno sea '\0'
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
        // Opcional: añadir chequeo para no exceder FIXSTRING_MAX si no confías en la terminación NUL
        // if (i >= FIXSTRING_MAX) return true; // O la lógica que corresponda si se alcanza MAX
    }
    // Compara el primer carácter diferente o el terminador NUL
    // Si s1[i] <= s2[i], entonces s1 es menor o igual
    // Esto funciona porque '\0' tiene valor 0, así que si s1 termina primero ("a" vs "abc"),
    // se compara s1[i] ('\0') con s2[i] ('b'), y '\0' < 'b', retorna true.
    // Si s2 termina primero ("abc" vs "a"), se compara s1[i] ('b') con s2[i] ('\0'),
    // y 'b' > '\0', retorna false.
    // Si son iguales, ambos serán '\0' y '\0' <= '\0' es true.
    return s1[i] <= s2[i];
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    /*
     * COMPLETAR
     *
     */
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}


