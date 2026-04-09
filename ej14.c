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