#include <stdio.h>

#include "token.h"
#include "lexer.h"

#define MAX_INPUT 256

void repl(void) {
    char buffer[MAX_INPUT];
    while (1) {
        printf("> ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        size_t len = 0;
        Token *tokens = lex_string(buffer, &len);
        for (size_t i = 0; i < len; i++) {
            token_display(&tokens[i]); }
    }
}
