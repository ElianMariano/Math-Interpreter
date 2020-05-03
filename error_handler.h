#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

/*
    Error code information thrown by application:
    Flags related errors:
    [1] Flag is not valid
    [2] Flag is duplicated
    [3] Mathematical expression expected
    [4] Expected a expression, but a flag is received
*/

#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

// Stores special error info
char *errinfo;

// Stores the error code
int error;

// Displays the error based in the code
void get_error(int code);
#endif