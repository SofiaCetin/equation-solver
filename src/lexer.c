#include "lexer.h"
#include "mystr.h"
#include <stdio.h>
#include "math_lib.h"

Token pre_token_type(char c){

    if (count_char(OPERANDS,c) > 0){
        return T_OPERAND;
    }
    if (count_char(ALPHABET,c) > 0){
        return T_ALPHA;
    }
    if (count_char(NUMBERS, c) > 0){
        return T_NUMBER;
    }
    if (c == '('){
        return T_LPAR;
    }
    if (c == ')'){
        return T_RPAR;
    }
    else{
        return UNDEF;
    }

}

List pre_tokenization(char* expr){
    if (expr == NULL || str_len(expr) < 1){
        return NULL;
    }

    Token type = pre_token_type(*expr);

    List res = new_list();
    char* str = char_to_str(*expr);
    if (res == NULL || str == NULL){
        return NULL;
    }
    append(res, str, type);
    expr++;

    while(*expr != '\0'){
        Token type = pre_token_type(*expr);
        char* str = char_to_str(*expr);
        if (res == NULL || str == NULL){
            return NULL;
        }
        append(res, str, type);
        expr++;
    }

    return res;
}

void tokenization(List l){
    if (l == NULL || isListEmpty(l)){
        return;
    }

    struct TokenCell* actual = l->next;
    while (actual != l){

        /* Test for numbers */
        if (actual->type == 1){
            printf("detected: %d numbers starting at %s\n", detect_number(actual), actual->value);
        }
        actual = actual->next;
    }
}

int detect_number(struct TokenCell* element){
    /* no digits should return 0, a single digit should return 1,
    then a number of n digits should return n */

    if (element == NULL){
        return -1;
    }

    int res = 0;

    struct TokenCell* actual = element;
    while(actual->type == 1){
        res++;
        actual = actual->next;
    }

    return res;
}

int main(void){
    List test = pre_tokenization("255x+b5");
    if (test == NULL){
        return 1;
    }
    show_list(test);
    tokenization(test);
    show_list(test);
    return 0;
}