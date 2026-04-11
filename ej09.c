#include <stdio.h>


int longitud(char *s){
    size_t len =0;
    while(*s != '\0'){
        len++;
        s++;
    }
    return (int) len;
}

void mayuscula(char s[]){
    int l = longitud(s);
    for(int i = 0; i < l; i++ ){
        if( 97 <= s[i] && s[i] <=122){
            s[i] -= 32;
        }
        printf("%c", s[i]);
    }
}

int main(){

    char s[20];
    printf("Ingresa tu palabra: ");
    scanf("%s", s);
    mayuscula(s);
  return 0;
}