#include <stdio.h> 

typedef struct {
    nombre char[];
    vida int;
    ataque double;
    defensa double;
} mounstro_t;

mounstro_t mounstros[] = {
    {"Juan", 1000, 2600, 3000},
    {"Messi", 2000, 4000, 6000},
    {"Manu", 9999, 90000, 100000}
};

printf("Imprimo el mounstro y su vida : %s%d\n", mounstros[0].nombre, mounstros[0].vida);
printf("Imprimo el mounstro y su vida : %s%d\n", mounstros[1].nombre, mounstros[1].vida);
printf("Imprimo el mounstro y su vida : %s%d\n", mounstros[2].nombre, mounstros[2].vida);
