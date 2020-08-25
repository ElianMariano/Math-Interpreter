/*
    This file handle every error the program will
    get into its execution, and then display it to
    the user.
    Every error will have a corresponding code.
*/

#include "error_handler.h"
#include <stdio.h>
#include <stdlib.h>

void get_error(int code){
    switch(code){
        case 1:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Flag '%s' is not a valid flag!\n", errinfo);
            printf("Thown error code [%d]" COLOR_RESET "\n" , code);

            free(errinfo);
            break;
        case 2:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Flag '%s' is duplicated!\n", errinfo);
            printf("Thown error code [%d]" COLOR_RESET "\n", code);

            free(errinfo);
            break;
        case 3:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Mathematical expression expected!\n");
            printf("Thown error code [%d]" COLOR_RESET "\n", code);
            break;
        case 4:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Expected mathematic expression, but '%s' flag was received!\n", errinfo);
            printf("Thown error code: [%d]" COLOR_RESET "\n", code);

            free(errinfo);
            break;
        case 5:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Entry mode expected!\n");
            printf("Thrown error code: [%d]" COLOR_RESET "\n", code);
            break;
        case 6:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Can not accept two entry modes!\n");
            printf("Interpreter and expression entry mode was given!\n");
            printf("Thrown error code: [%d]" COLOR_RESET "\n", code);
            break;
        case 7:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Help information requested with other flags!\n");
            printf("Thrown error code: [%d]" COLOR_RESET "\n", code);
            break;
        case 8:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Closing separator required!\n");
            printf("Thrown error code: [%d]" COLOR_RESET "\n", code);
            break;
        case 9:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Opening separator required!\n");
            printf("Thrown error code: [%d]" COLOR_RESET "\n", code);
            break;
        case 10:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Expression expected inside separator!\n");
            printf("Thrown error code: [%d]" COLOR_RESET "\n", code);
            break;
        case 11:
            printf(COLOR_RED "[ERROR]:\n");
            printf("Could not recognize number format: %s\n", errinfo);
            printf("Thrown error code: [%d]" COLOR_RESET "\n", code);

            free(errinfo);
            break;
        default:
            printf(COLOR_RED "Unknown error code!" COLOR_RESET "\n");
            break;
    }
}
