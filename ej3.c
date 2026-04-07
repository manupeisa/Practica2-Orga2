#include <stdio.h>

int main(){
    int x = 42;
    int *p = &x;

    printf("Direccion de x: %p Valor: %d\n", (void*) &x, x);
    printf("Direccion de p: %p Valor: %p\n", (void*) &p, (void*) p);
    printf("Valor de lo que apunta p: %d\n", *p);
}

/*
Ej 3
La diferencia entre x y p es que x es la varaible la cual almacena un valor y p
unicamente es un puntero que apunta a la direcion de memoria de x
La diferencia entre x y &x es que x es la varaible y &x es la direccion de memoria 
donde esta esta guardada 
Lo que cambia entre p y *p es que  p es el valor de p y *p es el valor al caul apunta p

Cuando se ejecute va a imprimir :
La direccion de memoria de X , El valor de x = 42 
La direccion donde esta el puntero y donde esta la memoria de X 
El valor el cual eesta apuntando p
*/

/*
Ej 4
Los valores que se imprimieron son :
Direccion de x: 0x7fffd20c527c Valor: 42
Direccion de p: 0x7fffd20c5280 Valor: 0x7fffd20c527c
Valor de lo que apunta p: 42

Esos son:
Donde esta X en la memoria y su valor 
Donde esta p en la memoria que es x pero extendido en memoria y el valor de p que es la 
direccion de memoria de X
EL valor al cual apunta p que es 42
*/