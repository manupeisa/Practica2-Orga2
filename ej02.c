#include <stdio.h>

typedef struct {
    char nombre[20];
    int vida;
    double ataque;
    double defensa;
} mounstro_t;


mounstro_t evolucion(mounstro_t m){
    m.ataque *= 10;
    m.defensa *= 10;
    return m;
}

int main(){

    mounstro_t m1 = {"Juli", 10, 7, 3};
    printf("Mi mounstro  es: %s %d %f %f \n", m1.nombre, m1.vida , m1.ataque, m1.defensa);

    mounstro_t res = evolucion(m1);
    printf("Mi mounstro evolucionado es: %s %d %f %f\n", res.nombre,res.vida , res.ataque, res.defensa);
    return 0;
}