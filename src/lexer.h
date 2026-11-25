#ifndef LEXER_H_
#define LEXER_H_

#include "list.h"

Token pre_token_type(char c);
List pre_tokenization(char* expr);
void tokenization(List l);
int detect_number(struct TokenCell* element);

#endif