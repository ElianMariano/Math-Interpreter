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
#include <string.h>

int sanitize_flags(int argc, char **argv){
    char *flags[5]= {"-i", "-e", "-d", "-r", "-help"};
    char *expression;
    int mode = DEGREE;

    for (int i = 1;i < argc;i++){
        for (int j = 1;j < 5;j++){
            if (strcmp(argv[i], flags[j]) == 0 && strcmp(argv[i], flags[1]) == 0){
                strcpy(expression, argv[i+1]);

                // Adds 2 to i counter
                i += 2;
            }
            else if (strcmp(argv[i], flags[j]) == 0){
                if (strcmp(argv[i], flags[0]) == 0){
                    // Executes the interpreter
                }
                else if (strcmp(argv[i], flags[2]) == 0){
                    mode = DEGREE;
                }
                else if (strcmp(argv[i], flags[3]) == 0){
                    mode = RADIANS;
                }
                else if (strcmp(argv[i], flags[4]) == 0){
                    // Show help info
                }
            }
            else{
                // handle error
            }
        }
    }
}

int sanitize_espression(char *exp, int length, int mode){

}