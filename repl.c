#include <stdio.h>

#define MAX_INPUT 256

void repl(void) {
    char buffer[MAX_INPUT];
    while (1) {
        printf("> ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }
    }
}
