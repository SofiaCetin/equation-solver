#ifndef MYSTR_H_
#define MYSTR_H_

#include <stdio.h>

extern const char NUMBERS[];
extern const char ALPHABET[];
extern const char OPERANDS[];

char* new_empty_str(void);
int count_char(const char* s, char c);
int any_c_in(const char* str, const char* input);
size_t str_len(const char* s);
char* str_add(char *dest, char c);
// char* detect_number(const char* expr);
char* char_to_str(char c);
char* strip(char* str);

#endif