/*
    This file handle every error the program will
    get into its execution, and then display it to
    the user.
    Every error will have and corresponding code.
*/

#include "error_handler.h"
#include <stdio.h>

void get_error(int code){
    switch(code){
        case 1:
            printf("[ERROR]:\n");
            printf("Flag '%s' is not a valid flag!\n", errinfo);
            printf("Thown error code %d\n", code);
            break;
        case 2:
            printf("[ERROR]:\n");
            printf("Flag '%s' is duplicated!\n", errinfo);
            printf("Thown error code %d\n", code);
            break;
        case 3:
            printf("[ERROR]:\n");
            printf("Mathematical expression expected!\n");
            printf("Thown error code %d\n", code);
            break;
        case 4:
            printf("[ERROR]:\n");
            printf("Expected mathamatic expression, but '%s' flag received\n", errinfo);
            printf("Thown error code: %d\n", code);
            break;
        default:
            printf("Unknown error code!\n");
            break;
    }
}