#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* =========================
   type.h (adaptado inline)
   ========================= */

typedef enum e_type {
    TypeFAT32 = 0,
    TypeEXT4 = 1,
    TypeNTFS = 2
} type_t;


typedef struct {
    uint32_t data;
} fat32_t;

typedef struct {
    uint32_t data;
} ext4_t;

typedef struct {
    uint32_t data;
} ntfs_t;

/* Funciones (solo declaración) */
fat32_t* new_fat32(){
    fat32_t *f = malloc(sizeof(fat32_t));
    if( f == NULL) return NULL;
    f->data = 0;
    return f;
}

ext4_t* new_ext4(){
    ext4_t *e = malloc(sizeof(ext4_t));
    if( e == NULL) return NULL;
    e->data = 1;
    return e;
}
ntfs_t* new_ntfs(){
    ntfs_t *n = malloc(sizeof(ntfs_t));
    if( n == NULL) return NULL;
    n->data = 2 ;
    return n;
}

fat32_t* copy_fat32(fat32_t* file){
    fat32_t *f = malloc(sizeof(fat32_t));
    if(f == NULL || file == NULL) return NULL;
    f->data = file->data;
    return f;
}

ext4_t* copy_ext4(ext4_t* file){
    ext4_t *e = malloc(sizeof(ext4_t));
    if(e == NULL || file == NULL) return NULL;
    e->data = file->data;
    return e;
}

ntfs_t* copy_ntfs(ntfs_t* file){
    ntfs_t *n = malloc(sizeof(ntfs_t));
    if( n == NULL || file == NULL) return NULL;
    n->data = file-> data;
    return n;
}

void rm_fat32(fat32_t* file){
    free(file);
}
void rm_ext4(ext4_t* file){
    free(file);
}
void rm_ntfs(ntfs_t* file){
    free(file);
}


/* =========================
   list.h (adaptado inline)
   ========================= */

typedef struct node {
    void* data;
    struct node* next;
} node_t;

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
} list_t;

/* Prototipos */
list_t* listNew(type_t t);
void listAddFirst(list_t* l, void* data);
void* listGet(list_t* l, uint8_t i);
void* listRemove(list_t* l, uint8_t i);
void listDelete(list_t* l);


/* =========================
   list.c (implementación)
   ========================= */

list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t));
    l->type = t;
    l->size = 0;
    l->first = NULL;
    return l;
}
//Swap de 2 nodos 
void swaplist(list_t* l, uint8_t i, uint8_t j){
    if( l == NULL || l->size <= 1 || i >= l->size || j >= l->size || i == j){
        return;
    }
    if(i > j){
        uint8_t temp = i;
        i = j;
        j = temp;
    }
    node_t* prev1 = NULL;
    node_t* prev2 = NULL;
    node_t* n1 = l->first;
    node_t* n2 = l->first;
   
    for(uint32_t w = 0; w < i ; w++){
        prev1 = n1;
        n1 = n1->next;
    }
    for(uint32_t p = 0; p < j; p++){
        prev2 = n2;
        n2 = n2->next;
    }
    if(n1 == NULL || n2 == NULL){
        return;
    }
    if(n1->next == n2){
        if(prev1 != NULL){
            prev1->next = n2;
        }
        else{
            l->first = n2;
        }
        n1->next =n2->next;
        n2->next =n1;
    }
    else{
        if(prev1!= NULL){
            prev1->next =n2;
        }
        else{
            l->first = n2;
        }
        if(prev2 != NULL){
            prev2->next= n1;
        }
        else{
            l->first= n1;
        }

        node_t* temp = n1-> next;
        n1->next= n2->next;
        n2->next = temp;
    }

    

}

void listAddFirst(list_t* l, void* data) {
    node_t* n = malloc(sizeof(node_t));

    switch(l->type) {
        case TypeFAT32:
            n->data = (void*) copy_fat32((fat32_t*) data);
            break;  
        case TypeEXT4:
            n->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            n->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
    }

    n->next = l->first;
    l->first = n;
    l->size++;
}

void* listGet(list_t* l, uint8_t i){
    node_t* n = l->first;

    for(uint8_t j = 0; j < i; j++)
        n = n->next;

    return n->data;
}

void* listRemove(list_t* l, uint8_t i){
    node_t* tmp = NULL;
    void* data = NULL;

    if(i == 0){
        data = l->first->data;
        tmp = l->first;
        l->first = l->first->next;
    } else {
        node_t* n = l->first;

        for(uint8_t j = 0; j < i - 1; j++)
            n = n->next;

        data = n->next->data;
        tmp = n->next;
        n->next = n->next->next;
    }

    free(tmp);
    l->size--;
    return data;
}

void listDelete(list_t* l){
    node_t* n = l->first;

    while(n){
        node_t* tmp = n;
        n = n->next;

        switch(l->type) {
            case TypeFAT32:
                rm_fat32((fat32_t*) tmp->data);
                break;
            case TypeEXT4:
                rm_ext4((ext4_t*) tmp->data);
                break;
            case TypeNTFS:
                rm_ntfs((ntfs_t*) tmp->data);
                break;
        }

        free(tmp);
    }

    free(l);
}


void printFat32List(list_t* l) {
    node_t* n = l->first;
    printf("[");
    while (n != NULL) {
        fat32_t* f = (fat32_t*) n->data;
        printf("%u", f->data);
        if (n->next != NULL) {
            printf(" -> ");
        }
        n = n->next;
    }
    printf("]\n");
}

/* =========================
   main de ejemplo
   ========================= */

int main() { list_t* l = listNew(TypeFAT32);

    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
    fat32_t* f3 = new_fat32();
    fat32_t* f4 = new_fat32();

    f1->data = 10;
    f2->data = 20;
    f3->data = 30;
    f4->data = 40;

    listAddFirst(l, f1);  // lista: [10]
    listAddFirst(l, f2);  // lista: [20 -> 10]
    listAddFirst(l, f3);  // lista: [30 -> 20 -> 10]
    listAddFirst(l, f4);  // lista: [40 -> 30 -> 20 -> 10]

    printf("Lista original: ");
    printFat32List(l);

    swaplist(l, 1, 3);
    printf("Swap indices 1 y 3: ");
    printFat32List(l);

    swaplist(l, 0, 1);
    printf("Swap indices 0 y 1: ");
    printFat32List(l);

    listDelete(l);

    rm_fat32(f1);
    rm_fat32(f2);
    rm_fat32(f3);
    rm_fat32(f4);

    return 0;
}