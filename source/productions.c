/*
    This file will handle the productions of the
    expression sintax, for example, the productions
    are models which the data and syntax are shaped.
    Example: factor -> digit|(exp)
    The factor production can be a digit or an expression
    between parentheses.

    The following produtions will be used to handle the
    majority of tasks performed by this program:
    factor -> digits|(exp)|function|PI|e
    func2 -> func2(exp, exp)
    function -> fuction(exp)
            | func2(exp, exp)
            | func2(exp, exp)
    term -> term * factor
        | term / factor
        | factor / term
        | factor
    exp -> exp + term
       | exp - term
       | term - exp
       | term

    The func2 and function productions are a broad set
    of mathematical function, func2 represents a set of
    functions with two parameters and function represents
    a set of functions with one parameter.
*/

#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "productions.h"

int parse_data(struct Stack *st, char *str){
    // Stores the needed spece for exp string
    st_exp = (char*) malloc(sizeof(char)*(strlen(str)+1));
    // Assign the string to the exp variable
    strcpy(st_exp, str);

    // Sets length default value
    length = 2;

    // Requests the neeed value of the token variable
    token = (char*) malloc(sizeof(char)*length);
    strcpy(token, "");

    // Assigns the stack expression pointer
    stack = st;

    // Starts the lookahead as zero
    lookahead = 0;

    // Inits the expression loop
    expr();
}

static void expr(){
    term();

    while (st_exp[lookahead] != '\0'){
        get_spaces();

        switch(st_exp[lookahead]){
            case '+':
                lookahead++;

                get_spaces();

                term();

                append('+');

                recognize(token);
            break;
            case '-':
                lookahead++;
                get_spaces();

                term();

                append('-');

                recognize(token);
            break;
        }
    }
}

static void term(){
    factor();

    get_spaces();

    switch (st_exp[lookahead])
    {
        case '*':
            lookahead++;

            get_spaces();

            factor();

            append('*');

            recognize(token);
        break;
        case '/':
            lookahead++;

            get_spaces();

            factor();

            append('/');

            recognize(token);
        break;
    }
}

static void factor(){
    while(isdigit(st_exp[lookahead]) || st_exp[lookahead] == '.'){
        append(st_exp[lookahead]);
        lookahead++;
    }

    if (strlen(token) != 0)
        recognize(token);
}

static void function(){
    if (!isdigit(st_exp[lookahead])){
        append(st_exp[lookahead]);
    }
    else if (st_exp[lookahead] == '('){
        // expectParenthesis++;
    }
    else if (st_exp[lookahead] == ')'){
        // expectParenthesis--;
    }
}

static void func2(){
    if (!isdigit(st_exp[lookahead])){
        append(st_exp[lookahead]);
    }
    else if (st_exp[lookahead] == '('){
        // expectParenthesis++;
    }
    else if (st_exp[lookahead] == ','){
        // to do
    }
    else if (st_exp[lookahead] == ')'){
        // expectParenthesis--;
    }
}

static void recognize(char *token){
    // push(stack, token);
    printf("%s", token);

    strcpy(token, "");

    length = 2;

    token = (char*) realloc(token, sizeof(char*)*length);
}

static void append(char c){
    if (strlen(token) >= 1){
        token = (char*) realloc(token, sizeof(char*)*(length+1));

        token[length-1] = c;
        token[length] = '\0';

        length++;
    }
    else {
        token[0] = c;
        token[1] = '\0';
    }
}

static void get_spaces(){
    while(st_exp[lookahead] == ' ')
        lookahead++;
}