#include <stdio.h>
#include <stdint.h>

int main(){
    uint8_t *x = (uint8_t*) 0xF0;
    int8_t *y = (int8_t*) 0xF6;
    printf("Dir de x: %p Valor: %d\n", (void*) x, *x);
    printf("Dir de y: %p Valor: %d\n", (void*) y, *y);
    //Devolver ́a:
    // Dir de x: 0xF0 Valor: 255
    // Dir de y: 0xF6 Valor: -128
}

/*
La diferenica es q X es un int sin signo lo cual es que su valor es de 0 a 2^32 -1 
y y es con signo por lo que es desde -2^31 a 2^31 -1
*/