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

TokenList* pre_tokenization(char* expr){
    if (expr == NULL || str_len(expr) < 1){
        return NULL;
    }

    Token first_type = pre_token_type(*expr);
    TokenEl* first = create_el(*expr, first_type);
    if (!isElValid(first)){
        return NULL;
    }

    TokenList* res = create_list(first);
    if (!isListValid(res)){
        return NULL;
    }
    expr++;

    while(*expr != '\0'){
        Token type = pre_token_type(*expr);
        TokenEl* token = create_el(*expr, type);
        if (!isElValid(token)){
            return NULL;
        }
        append(res, token);
    }

    return res;
}

int main(void){
    return 0;
}