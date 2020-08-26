/*
    This file will handle the productions of the
    expression sintax, for example, the productions
    are models which the data and syntax are shaped.
    Example: factor -> digit|(exp)
    The factor production can be a digit or an expression
    between parentheses.

    The following productions will be used to handle the
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
#include "error_handler.h"
#include "utils.h"

int parse_data(struct Stack *st, char *str){
    // Stores the needed spece for exp string
    st_exp = (char*) malloc(sizeof(char)*(strlen(str)+1));
    // Assign the string to the exp variable
    strcpy(st_exp, str);

    // Requests the needed value of the token variable
    token = (char*) malloc(sizeof(char)*2);
    strcpy(token, "");

    // Assigns the stack expression pointer
    stack = st;

    // Starts the lookahead as zero
    lookahead = 0;

    // Inits the expression loop
    expr();

    puts("\n");

    return 0;
}

static void expr(){
    while (st_exp[lookahead] != '\0' && st_exp[lookahead] != ')'){
        term();

        get_spaces(st_exp, &lookahead);

        switch(st_exp[lookahead]){
            case '+':
                lookahead++;

                get_spaces(st_exp, &lookahead);

                term();

                append(token, '+');

                recognize(token);
            break;
            case '-':
                lookahead++;
                get_spaces(st_exp, &lookahead);

                term();

                append(token, '-');

                recognize(token);
            break;
        }
    }
}

static void term(){
    factor();

    get_spaces(st_exp, &lookahead);

    while(st_exp[lookahead] == '*' || st_exp[lookahead] == '/'){
        switch (st_exp[lookahead])
        {
            case '*':
                lookahead++;

                get_spaces(st_exp, &lookahead);

                factor();

                append(token, '*');

                recognize(token);
            break;
            case '/':
                lookahead++;

                get_spaces(st_exp, &lookahead);

                factor();

                append(token, '/');

                recognize(token);
            break;
        }

        get_spaces(st_exp, &lookahead);
    }
}

static void factor(){
    if (st_exp[lookahead] == '-' && isdigit(st_exp[lookahead+1])){
        lookahead++;

        bool hasPoint = false;

        while(isdigit(st_exp[lookahead]) || st_exp[lookahead] == '.'){
            append(token, st_exp[lookahead]);
            lookahead++;

            if (st_exp[lookahead] == '.' && hasPoint){
                error = 11;

                strcpy(errinfo, token);

                return;
            }

            if (st_exp[lookahead] == '.')
                hasPoint = true;
        }

        if (strlen(token) != 0)
            recognize(token);

        append(token, '-');
    }
    else if (isdigit(st_exp[lookahead])){
        bool hasPoint = false;

        while(isdigit(st_exp[lookahead]) || st_exp[lookahead] == '.'){
            append(token, st_exp[lookahead]);
            lookahead++;

            if (st_exp[lookahead] == '.' && hasPoint){
                error = 11;

                strcpy(errinfo, token);

                return;
            }

            if (st_exp[lookahead] == '.')
                hasPoint = true;
        }

        if (strlen(token) != 0)
            recognize(token);
    }
    else if (strcmp(get_substring(st_exp, lookahead, 2), "PI") == 0){
        resize_assing(token, "PI");

        recognize(token);

        lookahead += 2;
    }
    else if (st_exp[lookahead] == 'e'){
        append(token, 'e');

        recognize(token);

        lookahead++;
    }
    else if (st_exp[lookahead] == '(') {
        if (st_exp[lookahead] == '('){
            lookahead++;

            expr();
        }

        get_spaces(st_exp, &lookahead);

        if (st_exp[lookahead] == ')')
            lookahead++;
    }
}

static void function(){
    if (!isdigit(st_exp[lookahead])){
        append(token, st_exp[lookahead]);
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
        append(token, st_exp[lookahead]);
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
    printf("%s ", token);

    resize_assing(token, "");
}