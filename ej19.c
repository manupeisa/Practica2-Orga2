#include <stdio.h>

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // p apunta al int en la fila 0, columna 0
    int *p = &matrix[0][0];

    // ¿que es reshape?
    int (*reshape)[2] = (int (*)[2]) p;

    printf("%d\n", p[3]); // Qu ́e imprime esta l ́ınea?
    printf("%d\n", reshape[1][1]); // Qu ́e imprime esta l ́ınea?

    return 0;
}


/*
 int reshape = {
    [1 , 2]
    [3 , 4]
    [5 , 6]
    [7 , 8]
    [9 , 10]
    [11 , 12]
    };

    *(*(reshape + fila) + columna)
    *(*(reshape + 2)+ 1) = 6

    reshape lo que hace es convertir mi matriz en una matriz de 2 columnas y 6 filas por lo que reacomoda como dice el nombre a mi matriz
    en una matriz de 2x6

    Lo que imprime p[3] es de la primera fila ya que el puntero siempre apunta a [0][0] este lo que hace es apuntar a matriz[0][3] = 4
    reshape[1][1] lo que hace es ir a la segunda fila de mi matriz reacomodade que es reshape y ir al segundo valor que es 4 
*/