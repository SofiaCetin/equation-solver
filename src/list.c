#include "list.h"

List new_list(void){
    List l;
    l = malloc(sizeof(*l));
    if (l == NULL){
        return NULL;
    }
    l->next = l;
    l->prev = l;
    return l;
}

int isListEmpty(List l){
    return l->next == l;
};

void append(List l, char* value, Token type){
    if (l == NULL){
        return;
    }

    struct TokenCell* new = malloc(sizeof(*new));
    if (new == NULL){
        return;
    }
    new->value = value;
    new->type = type;

    new->prev = l->prev;
    new->next = l;

    l->prev->next = new;
    l->prev = new;
}

void show_list(List l){
    if (l == NULL){
        return;
    }
    if (isListEmpty(l)){
        printf("[]");    
        return;
    }

    struct TokenCell* actual = l->next;
    printf("[");
    while (actual->next != l){
        printf("%s(%u), ", actual->value, actual->type);
        actual = actual->next;
    }
    printf("%s(%u)]", actual->value, actual->type);
};

void delete_list(List* l){
    if (l == NULL){
        return;
    }
    struct TokenCell* actual = (*l)->next;
    while (actual != *l){
        struct TokenCell* next = actual->next;
        free(actual);
        actual = next;
    }
    free(*l);
    *l = NULL;
}