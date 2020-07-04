#include <stdlib.h>
#include <string.h>
#include "stack.h"

void create_empty_stack(struct Stack *st){
    st->items = (char**) malloc(sizeof(char**));
    st->size = -1;
}

void push(struct Stack *st, char *item){
    // Increases the size
    ++st->size;

    // Reallocates more space for the items
    st->items = (char**) realloc(st->items, sizeof(char**)*(st->size+1));

    // Allocates the spece needed for the string item
    st->items[st->size] = (char*) malloc(sizeof(char*)*strlen(item));

    // Stores the new item
    st->items[st->size] = item;
}

void pop(struct Stack *st){
    // Frees the last address of items
    free(st->items[st->size]);

    // Decreases the size
    --st->size;
}

// Returns the last item
char* peek(struct Stack *st){
    return st->items[st->size];
}

bool isEmpty(struct Stack *st){
    if (st->size == -1)
        return true;
    else
        return false;
}