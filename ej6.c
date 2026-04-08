#include <stdio.h>
#include <stdint.h>

int main(){
    int8_t memoria[8] = {1,2,3,4};
    uint8_t *x = (uint8_t*) &memoria;
    int8_t *y = &memoria[0]; 

    printf("Dir de x: %p Valor: %d\n", (void*) x, *x);
    printf("Dir de y: %p Valor: %d\n", (void*) y, *x);

}