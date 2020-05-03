/*
    This file will contain methods for extracting
    the informations from strings, and verify if
    it has any errors and display acording with the
    error_handling.c file.
    If any error ocurr the function will return -1,
    and it will change the variable error.
*/

#include "content_sanitizer.h"
#include "mode.h"
#include "error_handler.h"
#include "info.h"
#include "interpreter.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sanitize_flags(int argc, char **argv){
    char *flags[5]= {"-i", "-e", "-d", "-r", "-help"};
    char *expression;
    // Pass degree mode as default
    int mode = DEGREE;

    // Flags provided by the user
    char **in_flags;
    // Allocate the data from strings and assign the flags to the array
    in_flags = (char**) malloc(sizeof(char*)*(argc-1));
    for (int i = 1;i < argc;i++){
        in_flags[i-1] = (char*) malloc(sizeof(char)*(strlen(argv[i])+1));

        strcpy(in_flags[i-1], argv[i]);
    }

    // Verify if the input flags are duplicated
    for (int i = 0;i<argc-1;i++){
        for (int j = 0; j < argc-1;j++){
            if (strcmp(in_flags[i], in_flags[j]) == 0 && i != j){
                errinfo = (char*) malloc(sizeof(char*)*(strlen(in_flags[i])+1));
                strcpy(errinfo, in_flags[i]);
                error = 2;
                free(in_flags);

                return -1;
            }
        }
    }

    // Verify the errors in the inputs
    for (int i = 0;i < argc-1;i++){
        if (strcmp(in_flags[i], flags[0]) == 0){
            init_interpreter();
        }
        else if (strcmp(in_flags[i], flags[1]) == 0){
            bool is_flag_received = false;

            if (i+2 == argc){
                error = 3;
                free(in_flags);

                return -1;
            }

            for (int j = 0;j < 5;j++){
                if (strcmp(in_flags[i+1], flags[j]) == 0)
                    is_flag_received = true;
            }

            if (is_flag_received){
                error = 4;
                errinfo = (char*) malloc(sizeof(char*)*(strlen(in_flags[i+1])+1));
                strcpy(errinfo, in_flags[i+1]);
                free(in_flags);

                return -1;
            }

            // Stores the data
            expression = (char*) malloc(sizeof(char*)*(strlen(in_flags[i+1])+1));
            strcpy(expression, in_flags[i+1]);

            // Skips 2 in for loop
            i++;
        }
        else if (strcmp(in_flags[i], flags[2]) == 0){
            mode = DEGREE;
        }
        else if (strcmp(in_flags[i], flags[3]) == 0){
            mode = RADIANS;
        }
        else if (strcmp(in_flags[i], flags[4]) == 0){
            help_info();
        }
        else{
            errinfo = (char*) malloc(sizeof(char*)*(strlen(in_flags[i])+1));
            strcpy(errinfo, in_flags[i]);
            error = 1;
            free(in_flags);

            return -1;
        }
    }

    free(in_flags);

    return 0;
}

int sanitize_expression(char *exp, int length, int mode){
    return 0;
}