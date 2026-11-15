#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef enum {

    /*
    Elementary token types, that will help with early
    syntax checking:
    */

    UNDEF,
    T_NUMBER,
    T_ALPHA,
    T_LPAR,
    T_RPAR,
    T_OPERAND,

    /* 
    After syntax has been successfully checked, 
    we can name the chars with more accurate tokens,
    as following:
    */

    T_VARIABLE,
    T_CONSTANT,
    T_FUNCTION,
    T_EQUAL,
    T_SUM,
    T_MINUS,
    T_MULT,
    T_DIV,
    T_POW

}Token;

typedef struct TokenEl{
    char* value;
    Token type;
    struct TokenEl* next;
}TokenEl;

typedef struct TokenList{
    TokenEl* first;
    size_t len;
}TokenList;

TokenList* create_list(TokenEl* first);
TokenEl* create_el(char* value, Token type);
void cons(TokenList* list, TokenEl* el);
int isListValid(TokenList* list);
int isElValid(TokenEl* el);
void show_list(TokenList* list);

#endif