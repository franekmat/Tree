#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "parse.h"

typedef enum { false, true } bool;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        INPUT (false);
        return 0;
    }
    if (argc == 2 && strcmp(argv[1], "-v") == 0) {
        INPUT (true);
        return 0;
    }
    else {
        printf ("ERROR");
        return 1;
    }
}
