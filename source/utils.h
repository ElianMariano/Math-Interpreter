#ifndef UTILS_H
#define UTILS_H

// Resize the length of the string and assings a new result to it
void resize_assing(char* str, char* new_str);

// Appends the character in the token variable
void append(char* str, char c);

// Get next substring of given length
char* get_substring(char* exp, int lookahed, int length);

// Gets the space of the expression
void get_spaces(char* exp, int* lookahead);

#endif