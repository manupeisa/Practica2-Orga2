#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 50

typedef struct persona_s {
    char nombre[NAME_LEN];
    int edad;
    struct persona_s* hijo;
} persona_t;


void eliminarPersona(persona_t *p){
    free(p);
}



persona_t *crearPersona(char n[], int e){
    persona_t *p = malloc(sizeof(persona_t));
    if(p == NULL){
        return NULL;
    }
    strcpy(p->nombre, n);
    p->edad = e;
    p->hijo = NULL;

    return p;

}


int main(){
    char n[NAME_LEN] = "Juan";
    int e = 20;

    persona_t *p = crearPersona(n,e);
    
    if(p == NULL){
        printf("Error al reservar memoria\n");
        return 1;
    }
    printf("El nomre de la persona es : %s y su edad : %d ", p->nombre, p->edad);

    //Creo a la persona y luego de su uso la elimino de la memoria asi no usa espacio luego de su uso 
    eliminarPersona(p);
    p = NULL;

    return 0;
}
