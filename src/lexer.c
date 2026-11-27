#include "lexer.h"
#include "mystr.h"
#include <stdio.h>
#include <stdlib.h>
#include "math_lib.h"
#include <unistd.h>

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
    if (expr == NULL || str_len(expr) < 1 || !hasOneEqualSymbol(expr)){
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

    struct TokenCell* current = l->next;
    while (current != l){

        if (current->type == 0){
            // Check for undefined chars/symbols (ex: "2x+5$" is wrong)
            printf("Error: %s is undefined", current->value);
            delete_list(&l);
            exit(1);
        }

        if (current->type == 1){
            // Conversion from separated digits to whole numbers
            int step = detect_number(current);
            if (step >= 2){
                struct TokenCell* current2 = current->next;
                for (; step != 1 ;step--){
                    current->value = str_add(current->value, str_to_char(current2->value));
                    struct TokenCell* next = current2->next;
                    delete_element(current2);
                    current2 = next;
                }
                current = current2;
                continue;
            }
        }

        if (current->type == 2){

        }

        current = current->next;
    }
}

int detect_number(struct TokenCell* element){
    /* one digit should return 1, 
    a number of n digits after should return n.
    basically tolds the tokenization function how many digits
    to group with the first digit */

    if (element == NULL){
        return -1;
    }

    int res = 0;
    struct TokenCell* current = element;
    while(current != NULL && current->type == 1){
        res++;
        current = current->next;
    }

    return res;
}

int main(void){
    List test = pre_tokenization(strip("120 + x + 2x = 3"));
    if (test == NULL){
        printf("Error: main returned 1");
        return 1;
    }
    show_list(test);
    tokenization(test);
    show_list(test);
    delete_list(&test);
    getchar();
    return 0;
}