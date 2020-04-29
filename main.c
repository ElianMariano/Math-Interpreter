#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    printf("Argument count: %d\n", argc);

    if (argc > 1)
        printf("Flag 1: %s", argv[1]);

    return 0;
}