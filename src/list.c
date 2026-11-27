#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List new_list(void){
    List l;
    l = malloc(sizeof(*l));
    if (l == NULL){
        return NULL;
    }
    l->type = 0;
    l->value = NULL;
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

    struct TokenCell* current = l->next;
    printf("[");
    while (current->next != l){
        printf("%s(%u), ", current->value, current->type);
        current = current->next;
    }
    printf("%s(%u)]\n", current->value, current->type);
};

void delete_element(struct TokenCell* element){
    if (element == NULL){
        return;
    }

    struct TokenCell* next = element->next;
    struct TokenCell* prev = element->prev;
    if (next == NULL && prev == NULL){
        free(element);
        return;
    }
    prev->next = next;
    next->prev = prev;
    free(element);
    element = NULL;
}

void delete_list(List* l){
    if (l == NULL){
        return;
    }
    struct TokenCell* current = (*l)->next;
    while (current != *l){
        struct TokenCell* next = current->next;
        free(current);
        current = next;
    }
    free(*l);
    *l = NULL;
}