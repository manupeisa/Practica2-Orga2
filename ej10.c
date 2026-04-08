#include <stdio.h>
#include <string.h>


int longitud(char *s){
    int l = (int) strlen(s);
    return l;
}


char* copiar(char *s){
    int l = longitud(s);
    char c[l];

    strcpy(c,s);

    return c;
}

char* unir(char *s1, char *s2){
    strcat(s1,s2);

    return s1;
}

void mayor(char *s1, char *s2){
    int cmp = strcmp(s1, s2);

    if(cmp > 0){
        printf("%s es mayor que %s\n", s1,s2);
    }
    else if(cmp < 0){
        printf("%s es mayor que %s\n", s2,s1);
    }
    else{
        printf("Ambas son iguales en valor");
    }
}

int main(){
    char s1[40];
    char s2[40];

    printf("Ingrese la primer palabra: ");
    scanf("%s", s1);

    printf("Ingrese la segunda palabra: ");
    scanf("%s", s2);
    
    printf("La longitud de la primer palabra es: %d y el de la segunda es: %d\n", longitud(s1), longitud(s2));

    char *c = copiar(s1);

    mayor(s1,s2);

    printf("Mis 2 palabras concatenadas son: %s\n", unir(s1,s2));

    return 0;

}

/*
Restrict dentro de strcpy lo que hace es que ningun otro puntero apuente a esa memoria por lo que no podria poner strcpy(s,s ) pq rompe 
el comportamiento del mismo ya que el destino es igual que el orgien por lo que hay 2 apuntando a lo mismo 
*/