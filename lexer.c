#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "sslice.h"
#include "token.h"

Token *lex_string(const char *input, size_t *out) {
    StringSlice slice = sslice_from_str(input);
    Token *tokens = malloc(sizeof(Token) * strlen(input));
    size_t tokens_len = 0;

    while (1) {
        sslice_triml(&slice);
        if (slice.len == 0) break;

        char curr = slice.str[0];
        switch (curr) {
            case '(':
                tokens[tokens_len++] = (Token) {
                    .kind = LPAREN,
                };
                sslice_chopl(&slice);
                break;
            case ')':
                tokens[tokens_len++] = (Token) {
                    .kind = RPAREN,
                };
                sslice_chopl(&slice);
                break;
            case '.':
                tokens[tokens_len++] = (Token) {
                    .kind = DOT,
                };
                sslice_chopl(&slice);
                break;
            case '\\':
                tokens[tokens_len++] = (Token) {
                    .kind = SLASH,
                };
                sslice_chopl(&slice);
                break;
            default:
                if (!isalpha(curr)) {
                    fprintf(stderr, "Unknown char: %d\n", curr);
                    sslice_chopl(&slice);
                    break;
                }
                tokens[tokens_len++] = (Token) {
                    .kind = IDENT,
                    .ident = sslice_chop_while(&slice, isalpha),
                };
        }
    }

    *out = tokens_len;
    return tokens;
}
