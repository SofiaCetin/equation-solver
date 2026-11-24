#ifndef LEXER_H_
#define LEXER_H_

#include "math_lib.h"
#include "list.h"
#include "mystr.h"

Token pre_token_type(char c);
List pre_tokenization(char* expr);

#endif