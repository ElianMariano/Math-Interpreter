#include <stdio.h>
#include "error_handler.h"
#include "content_sanitizer.h"

int main(int argc, char **argv){
    int status;

    // Init the program
    status = sanitize_flags(argc, argv);

    if (status == -1)
        get_error(error);

    printf("Program exit with -1 status!\n");
    return 0;
}