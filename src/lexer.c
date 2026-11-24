#include "lexer.h"

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

int main(void){
    List test = pre_tokenization("ax+b");
    if (test == NULL){
        return 1;
    }
    show_list(test);
    char* test3 = strip("b o njour");
    printf("%s", test3);
    return 0;
}