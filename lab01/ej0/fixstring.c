#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

/* fstring_length() devuelve la longitud de la cadena guardada en el parámetro s */
unsigned int fstring_length(fixstring s) {
    int i = 0;
    
    while (s[i] != '\0') {
        i++;
    }

    return i;
}

/* fstring_eq() indica si las cadenas s1 y s2 son iguales (contienen la misma cadena) */
bool fstring_eq(fixstring s1, fixstring s2) {
    bool strIguales = true;

    if (s1 != s2) {
        strIguales = false;
    }
    
    return strIguales;
}

/* fstring_less_eq() indica si la cadena guardada en s1 es menor o igual que la guardada en s2 en el sentido del orden alfabético */
bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool menoroIgual = true;
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] > s2[i]) {
            menoroIgual = false;
        }
        i++;
    }
    
    return menoroIgual;
}


/* si es menor true
si es igual, seguir con el siguiente
si es mayor false */