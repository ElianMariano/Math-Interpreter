#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*
    This file contains special methods to dealing with cummon
    string operations when reading a mathematical expression
    and parsing it to a expression stack.
*/

void resize_assing(char *str, char* new_str){
    str = (char*) realloc(str, sizeof(char)*(strlen(new_str)+2));

    strcpy(str, new_str);
}

void append(char* str, char c){
    if (strlen(str) >= 1){
        int length = strlen(str);

        str = (char*) realloc(str, sizeof(char*)*(length+2));

        str[length] = c;
        str[length+1] = '\0';
    }
    else {
        str[0] = c;
        str[1] = '\0';
    }
}

char* get_substring(char* exp, int lookahead, int length){
    char* str = (char*) malloc(sizeof(char)*(length+1));

    if (length == 0){
        strcpy(str, "");

        return str;
    }

    for (int i = lookahead;i < (lookahead+length);i++){
        str[i] = exp[i];
    }

    str[length+1] = '\0';

    return str;
}

bool is_substring_function(char* exp, int lookahead){
    int n = lookahead;

    while (!isdigit(exp[n]) && exp[n] != ' ')
        n++;

    while(exp[n] == ' ')
        n++;

    if (exp[n] == '(')
        return true;
    else
        return false;
}

void get_spaces(char* exp, int* lookahead){
    while(exp[(*lookahead)] == ' ' || exp[(*lookahead)] == '\t'){
        (*lookahead)++;
    }
}