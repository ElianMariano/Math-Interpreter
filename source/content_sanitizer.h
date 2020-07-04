#ifndef CONTENT_SANITIZER_H
#define CONTENT_SANITIZER_H
#include <stdbool.h>

// This macros defines the entry mode
#define INTERPRETER 1
#define EXPRESSION 2

int sanitize_flags(int argc, char **argv);

int sanitize_expression(char *exp, int mode);

#endif