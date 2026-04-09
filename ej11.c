#include <stdio.h>
#include <stdint.h>


uint16_t *secuencia(uint16_t n){
    uint16_t arr[n];
    for(uint16_t i =0 ; i<n ; i++){
        arr[i] = i;
    }
    return arr;
}


int main(){
    uint16_t *arr = secuencia(10);
    printf("%d\n", arr[0]);
    return 0;
}

/*
Este codigo no impirme nada pq tiene duracion automatica por lo que cuando termina de ejecutarse la funcion secuencia el valor arr deja de
existir por lo que entonces despues en mi main cuando yo quiero imprimir el primer valor de mi array este no me devuelve nada 
ya que luego que termine la funcion todo su contenido guardado en memoria se va :(
*/