#include <stdio.h>

#define VIDEO_COLS 80
#define VIDEO_FILS 50
// Cada posicion de memoria tiene 2 bytes
typedef struct ca_s {
    uint8_t c; // caracter
    uint8_t a; // atributos
} ca;
void screen_draw_layout(void) {
    // VIDEO es un puntero a la direcci ́on de memoria del buffer de video
    ca(*p)[VIDEO_COLS] = (ca(*)[VIDEO_COLS])VIDEO;
    uint32_t f,c;
    for (f = 0; f < VIDEO_FILS; f++) {
        for (c = 0; c < VIDEO_COLS; c++) {
            p[f][c].c = ' ';
            p[f][c].a = 0x10;
        }
    }
}

/*
Lo que hace  ca(*p)[VIDEO_COLS] = (ca(*)[VIDEO_COLS])VIDEO  es dado el puntero video mi puntero lo que hace es reacomodar la memeoria buffer
teniendo en cuenta que mis columnas van a ser de largo VIDEO_COLS  osea qeu voy a tener una "Matriz" de 80 columnas 

Lo que hace p[f][c].c = ’ ’ es en el puntero p que es del tripo sruct ca es en el dato c el cual es caracter asignarle el valor vacio osea
' '  y como nos explicaron el formato es de 2 bytes lo cual el primero es el caracter el cual todos seran ' ' y el segundo byte el cual sera
el color del caracter los cuales todos tengran el color 0x10


Si en vez de ca(*p)[VIDEO COLS] hubi ́eramos declarado ca** p nuestro puntero p no tendria el formato 
*/