#include "info.h"
#include <stdio.h>

void usage_info(){
    printf("Math Interpreter is a program which collects a mathematical\n");
    printf("expression and calculates it and give the corresponding\n");
    printf("result.\n");
    printf("This program is under the MIT License, to see more information\n");
    printf("enter into the link below.\n");
    printf("https://github.com/ElianMariano/Math-Interpreter/blob/master/LICENSE\n");
    printf("This program was created by Elian Mariano.\n");
    printf("https://github.com/ElianMariano\n");

    puts("\n");

    help_info();
}

void help_info(){
    printf("Read the instructions below to learn how to use this program:\n");

    printf(COLOR_BLUE "MODE:" COLOR_RESET "\n");
    printf("The program has two modes: Radians and Degrees. The first one\n");
    printf("considers PI constant as 180 degrees, and the last one considers\n");
    printf("it as 3.14. By default the program executes in Degree mode.\n");

    puts("\n");

    printf(COLOR_BLUE "FLAGS" COLOR_RESET "\n");
    printf("-i\n");
    printf("Executes an interpreter\n");
    printf("-e [EXPRESSION]\n");
    printf("Calculates the given expression\n");
    printf("-d\n");
    printf("Executes the program in DEGREE mode\n");
    printf("-r\n");
    printf("Executes in RADIANS mode\n");
    printf("-help\n");
    printf("Show this help information\n");

    puts("\n");

    printf( COLOR_BLUE "RESERVED KEYWORDS AND FUNCTIONS ACCEPTED" COLOR_RESET "\n");
    printf(COLOR_BLUE "CONSTANTS:" COLOR_RESET "\n");
    printf("PI: Constant for pi\n");
    printf("e: Euler's constant\n");
    printf(COLOR_BLUE "FUNCTIONS:" COLOR_RESET "\n");
    printf("sin: Sine function\n");
    printf("cos: Cosine function\n");
    printf("tan: Tangent function\n");
    printf("abs: Absolute function\n");
    printf("ln: Natural log function\n");
    printf("cossec: Cosecant function\n");
    printf("sec: Secant function\n");
    printf("cotg: Cotangent function\n");
    printf("pow: Power function\n");
    printf("sqrt: Square root function\n");
    printf(COLOR_BLUE "OPERATORS:" COLOR_RESET "\n");
    printf("+: Addition\n");
    printf("-: Subtraction\n");
    printf("*: Multiplication\n");
    printf("/: Division\n");
    printf(COLOR_BLUE "SEPARATORS:" COLOR_RESET "\n");
    printf("Only parenthesis is accepted\n");
}