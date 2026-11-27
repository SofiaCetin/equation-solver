#ifndef LEXER_H_
#define LEXER_H_

#include "list.h"

#define ERROR(msg) \
    fprintf(stderr, "[ERREUR] %s:%d (%s) : %s\n", \
    __FILE__, __LINE__, __func__, msg)

Token pre_token_type(char c);
List pre_tokenization(char* expr);
void tokenization(List l);
int detect_same_type(struct TokenCell* element);
struct TokenCell* group_same_type(struct TokenCell* element, int steps);

#endif