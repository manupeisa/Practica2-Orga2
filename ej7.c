#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 10, y =20;
    swap(&x, &y);
    printf("X : %d Y: %d", x, y);

    return 0;
}


/*
No hay diferencia si nuestro swap lo poenmos con el void en el caso de que lo usemos dentro de nuestro main con varaibles del main,
pero si usamos unicamente el swap no nos va a devolver nada 
*/