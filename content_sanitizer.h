#ifndef CONTENT_SANITIZER_H
#define CONTENT_SANITIZER_H
#include <stdbool.h>

int sanitize_flags(int argc, char **argv);

int sanitize_espression(char *exp, int length, int mode);

#endif