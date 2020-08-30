#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>

// Resize the length of the string and assings a new result to it
void resize_assing(char* str, char* new_str);

// Appends the character in the token variable
void append(char* str, char c);

// Get next substring of given length
char* get_substring(char* exp, int lookahead, int length);

// Returns true if the next substring is a function
bool is_substring_function(char* exp, int lookahead);

// Gets the space of the expression
void get_spaces(char* exp, int* lookahead);

#endif