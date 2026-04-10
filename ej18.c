#include <stdio.h>
#include <stdlib.h>


//Inicia mi puntero hacia el array y va llenadolo con la varaible value 
void allocateArray(int *arr, int size, int value) {
    arr = (int*) malloc(size * sizeof(int));
    if(arr != NULL) {
        for(int i=0; i<size; i++) {
            arr[i] = value;
        }
    }
}

// Uso
int main(){
    int *vector = NULL;
    allocateArray(vector,5,45);
    for(int i = 0; i < 5; i++){
        printf("%d\n", vector[i]);
    }
    free(vector);
}


/*
Si corremos este codigo no sucede nada ya que lo que hacemos es pasarle por copia a allocateArray el vector ya que esto no imprime pq mi 
vector sige siendo NULL

*/