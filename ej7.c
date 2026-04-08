#include <stdio.h>

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 10, y =20;
    swap(x, y);
    printf("X : %d Y: %d", x, y);

    return 0;
}


/*
Ahora que cambie las variables a int a y int b mis valores no cambian por lo que no sirve mi swap

No se modifican ya que lo que hace mi swap es darle las copias de x e y y dentro del swap si se modifican los valores de las copias 
pero no modifica el valor real de x e y ya que solo le paso copias no su direccion de memoria 
*/