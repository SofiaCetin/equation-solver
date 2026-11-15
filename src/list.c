#include "list.h"

inline int isListValid(TokenList* list){
    return list != NULL && list->first != NULL;
}

inline int isElValid(TokenEl* el){
    return el != NULL && el->value != NULL;
}

TokenList* create_list(TokenEl* first){
    if (!isElValid(first))
        return NULL;
    TokenList* res = malloc(sizeof(TokenList));
    if (!isListValid(res))
        return NULL;
    res->first = first;
    res->len = 1;
    return res;
}

TokenEl* create_el(char* value, Token type){
    if (value == NULL){
        return NULL;
    }

    TokenEl* res = malloc(sizeof(TokenEl));
    if (res == NULL){
        return NULL;
    }
    res->value = value;
    res->type = type;
    res->next = NULL;

    return res;
}

void append(TokenList* list, TokenEl* el){
    if (!isListValid(list) || !isElValid(el)){
        return;
    }
    TokenEl* current = list->first;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = el;
    el->next = NULL;
    list->len++;
}

void show_list(TokenList* list){
    if (!isListValid(list) || )
}