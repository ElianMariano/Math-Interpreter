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

#include "productions.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_data(struct Stack *st, char *str){
    // Stores the needed spece for exp string
    st_exp = (char*) malloc(sizeof(char)*(strlen(str)+1));
    // Assign the string to the exp variable
    strcpy(st_exp, str);

    // Assigns the address to the main stack
    stack = st;

    // Sets the default value of the expectParenthesis variable
    expectParenthesis = 0;

    // Requests the neeed value of the token variable
    token = (char*) malloc(sizeof(char)*30);

    // Starts the lookahead as zero
    lookahead = 0;
}

static void expr(){
    term();

    while (st_exp[lookahead] != '\0'){
        switch(st_exp[lookahead]){
            case '+':
                append('+');

                recognize(token);

                term();            
            break;
            case '-':
                append('-');

                recognize(token);

                term();
            break;
        }
        lookahead++;
    }
}

static void term(){
    
}

static void factor(){
    if (isdigit(st_exp[lookahead])){
        append(st_exp[lookahead]);
    }
    else if (st_exp[lookahead] == '.'){
        append('.');
    }
}

static void function(){
    if (!isdigit(st_exp[lookahead])){
        append(st_exp[lookahead]);
    }
    else if (st_exp[lookahead] == '('){
        expectParenthesis++;
    }
    else if (st_exp[lookahead] == ')'){
        expectParenthesis--;
    }
}

static void func2(){
    if (!isdigit(st_exp[lookahead])){
        append(st_exp[lookahead]);
    }
    else if (st_exp[lookahead] == '('){
        expectParenthesis++;
    }
    else if (st_exp[lookahead] == ','){
        
    }
    else if (st_exp[lookahead] == ')'){
        expectParenthesis--;
    }
}

static void recognize(char *token){
    push(stack, token);
}

static void append(char c){
    int length = strlen(token);

    token[length] = c;
    token[length+1] = '\0';
}