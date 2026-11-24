#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {

    /*
    Elementary token types, that will help with early
    syntax checking:
    */

    UNDEF,      // i0
    T_NUMBER,   // i1
    T_ALPHA,    // i2
    T_LPAR,     // i3
    T_RPAR,     // i4
    T_OPERAND,  // i5

    /* 
    After syntax has been successfully checked, 
    we can name the chars with more accurate tokens,
    as following:
    */

    T_VARIABLE, // i6
    T_CONSTANT, // i7
    T_FUNCTION, // i8
    T_EQUAL,    // i9
    T_SUM,      // i10
    T_MINUS,    // i11
    T_MULT,     // i12
    T_DIV,      // i13
    T_POW       // i14

}Token;

struct TokenCell{
    char* value;
    Token type;
    struct TokenCell* next;
    struct TokenCell* prev;
};

typedef struct TokenCell* List;


List new_list(void);
int isListEmpty(List l);
void append(List l, char* value, Token type);
void show_list(List l);
void delete_list(List* l);

#endif