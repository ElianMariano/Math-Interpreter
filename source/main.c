#include "info.h"
#include "error_handler.h"
#include "content_sanitizer.h"
#include <stdio.h>
#include <stdlib.h>
#include "productions.h"

int main(int argc, char **argv){
    int status = 0;

    if (argc > 1){
        // Init the program
        status = sanitize_flags(argc, argv);

        if (status == -1){
            get_error(error);
            printf(COLOR_RED "Program exit with -1 status!" COLOR_RESET "\n");

            return -1;
        }
    }
    else{
        usage_info();
    }

    return 0;
}