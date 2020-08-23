#ifndef PRODUCTIONS_H
#define PRODUCTIONS_H
#include "stack.h"
#include <stdbool.h>

/*
    Parses a string to the requested data
    in the end it builds a stack which represents
    the mathematical expression.
    Returns zero if an error occurs;
*/
int parse_data(struct Stack *st, char *str);

// Stores the whole mathematical expression
static char *st_exp;

// Current token or keyword analyzed
static char *token;

// The memory length of the token
static int length;

// Index of the current character analyzed
static int lookahead;

// References the main expression stack
struct Stack *stack;

// Evaluates an expression
static void expr();

// Evaluates the term
static void term();

// Most primitive type of data
static void factor();

// Evaluates a function of one parameter
static void function();

// Evaluates a function of two parameter
static void func2();

// Recognize a string as correct and adds it to the stack
static void recognize(char *token);

// Appends the character in the token variable
static void append(char c);

// Gets the space of the expression
static void get_spaces();

#endif
