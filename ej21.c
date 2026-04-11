#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef void* (*funcCopy_t)(void*);
typedef void* (*funcRm_t)(void*);


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

//Esta funcion lo que hace es ingresado el tipo de dato me devulve el copy que se nesecite 
funcCopy_t getCopyFunction(type_t t){
    switch(t){
        case TypeFAT32: return (funcCopy_t) copy_fat32; break ;
        case TypeEXT4: return (funcCopy_t) copy_ext4; break ;
        case TypeNTFS: return (funcCopy_t) copy_ntfs; break ;
        default : return NULL ; break;
    }
}

//Mismo formato que la anterior solo que dado el tipo de dato que ingreso le devuelvo una funcion para borrar ese tipo de dato 
funcRm_t getRmFunction(type_t t){
    switch(t){
        case TypeFAT32: return (funcRm_t) rm_fat32; break ;
        case TypeEXT4: return (funcRm_t) rm_ext4; break ;
        case TypeNTFS: return (funcRm_t) rm_ntfs; break ;
        default : return NULL ; break;
    }
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

void listAddFirst(list_t* l, void* data) {
    node_t* n = malloc(sizeof(node_t));
    n-> data = getCopyFunction(l->type)(data);
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
        getRmFunction(l->type)(tmp->data);
        free(tmp);
    }

    free(l);
}


/* =========================
   main de ejemplo
   ========================= */

int main() {
    list_t* l = listNew(TypeFAT32);

    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();

    listAddFirst(l, f1);
    listAddFirst(l, f2);

    listDelete(l);

    rm_fat32(f1);
    rm_fat32(f2);

    return 0;
}