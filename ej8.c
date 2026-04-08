#include <stdio.h>


int main(){
    char *str1 = "Hola";
    char str2[] = "hola";

    printf("%s\n", str1);
    printf("%s", str2);

    return 0;
}

/*
Se puede pensar el operador [] como un operador de desreferencia. En este caso no cambia nada en nuestro codigo 

Pero la diferencia es que *str1 es un puntero mientras que str2[] un un array de chars
*/