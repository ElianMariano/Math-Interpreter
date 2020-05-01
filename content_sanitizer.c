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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sanitize_flags(int argc, char **argv){
    char *flags[5]= {"-i", "-e", "-d", "-r", "-help"};
    // Stores the already used flags indexes
    int *used_flags, count = 1;
    char *expression;
    int mode = DEGREE;

    used_flags = (int*) malloc(sizeof(int));

    for (int i = 1;i < argc;i++){
        // Reallocs the data in the used flags variable
        if (i > 1){
            count++;
            used_flags = (int*) realloc(used_flags, sizeof(int)*count);
        }

        // Verify if the flag is valid
        if (strcmp(argv[i], flags[0]) == 0){
            printf("Executes the interpreter\n");
            used_flags[i-1] = 0;
        }
        else if (strcmp(argv[i], flags[1]) == 0){
            used_flags[i-1] = 1;
            bool is_flag_received = false;

            for (int j = 0;j < 5;j++){
                if (strcmp(argv[i+1], flags[j]) == 0){
                    is_flag_received = true;
                }
            }

            if (is_flag_received){
                error = 4;
                strcpy(errinfo, argv[i+1]);

                free(used_flags);

                return -1;
            }
            else if (i+1 > argc){
                error = 3;

                free(used_flags);
                
                return -1;
            }
            else{
                strcpy(expression, argv[i+1]);
                i++;
            }
        }
        else if (strcmp(argv[i], flags[2]) == 0){
            used_flags[i-1] = 2;

            mode = DEGREE;
        }
        else if (strcmp(argv[i], flags[3]) == 0){
            used_flags[i-1] = 3;

            mode = RADIANS;
        }
        else if (strcmp(argv[i], flags[4]) == 0){
            help_info();
        }
        else{
            error = 1;
            strcpy(errinfo, argv[i]);

            free(used_flags);
            
            return -1;
        }

        // Verify if the flag is duplicated
        for (int j = 0;j < 5;j++){
            for (int k = 0;k < 5;k++){
                if (used_flags[i] == used_flags[k]){
                    error = 2;
                    strcpy(errinfo, flags[used_flags[k]]);

                    free(used_flags);

                    return -1;
                }
            }
        }
    }

    free(used_flags);
}

int sanitize_expression(char *exp, int length, int mode){

}