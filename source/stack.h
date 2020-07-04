#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

struct Stack{
    char **items;
    int size;
};

void create_empty_stack(struct Stack *st);
void push(struct Stack *st, char *item);
void pop(struct Stack *st);
char* peek(struct Stack *st);
bool isEmpty(struct Stack *st);

#endif