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
    pow -> pow(exp, exp)
    sqrt -> sqrt(exp, exp)
    function -> fuction(exp)
            | pow
            | sqrt
    term -> term * factor
        | term / factor
        | factor / term
        | factor
    exp -> exp + term
       | exp - term
       | term - exp
       | term
*/

#include "productions.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void exp(char *exp){
    // Exp function
}

void term(char *t){
}

void factor(char *t){
    // The current index of the string
    int i = 0;
    // Stores the extracted token
    char *f;
    f = (char*) malloc(sizeof(char*)*3);
    // If number has point, it will be true
    bool has_point = false;

    while (t[i] != '\0'){
        if (isdigit(t[i]) || t[i] == '.'){
            if (has_point)
                printf("Erro\n");

            if (t[i] == '.')
                has_point = true;

            if (i > 2){
                f = (char*) realloc(f, sizeof(char*)*(i+1));
            }

            f[i] = t[i];
        }
        else if (t[i] == '('){

        }
        else if (t[i] == 'P' && t[i+1] == 'I'){

        }
        else if (t[i] == 'e'){

        }
        else if (t[i] == ' '){
            continue;
        }
        else{

        }

        i++;
    }

    free(f);
}

void pow(char *t){

}

void sqrt(char *t){

}

void cos(char *t){

}

void sin(char *t){

}

void tan(char *t){

}

void abs(char *t){

}

void ln(char *t){

}

void cossec(char *t){

}

void sec(char *t){

}

void catg(char *t){

}