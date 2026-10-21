#define TEST_MAIN

#include <assert.h>
#include <stdlib.h>

#include "tests.h"
#include "token.h"
#include "lexer.h"

Test(lex) {
    const char *input = " \t\n()\\.foo.bar jar";

    Token expected[] = {
        { .kind = LPAREN },
        { .kind = RPAREN },
        { .kind = SLASH },
        { .kind = DOT },
        { .kind = IDENT, .ident = (StringSlice){.str = "foo", .len = 3}},
        { .kind = DOT },
        { .kind = IDENT, .ident = (StringSlice){.str = "bar", .len = 3}},
        { .kind = IDENT, .ident = (StringSlice){.str = "jar", .len = 3}},
    };

    size_t actual_len;
    Token *actual = lex_string(input, &actual_len);
    assert(actual_len == sizeof(expected) / sizeof(Token));

    for (size_t i; i < actual_len; i++) {
        assert(token_cmp(&expected[i], &actual[i]) == 0);
    }
}
