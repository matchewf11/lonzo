#include <stdlib.h>
#include <string.h>

#include "sslice.h"
#include "token.h"

Token *lex_string(const char *input, size_t *out) {
    StringSlice slice = sslice_from_str(input);
    Token *tokens = malloc(sizeof(Token) * strlen(input));
    size_t tokens_len = 0;

    while (1) {
        sslice_chopl(&slice);
        if (slice.len == 0) {
            break;
        }
    }

    *out = tokens_len;
    return tokens;
}
