#define TEST_MAIN

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "tests.h"
#include "token.h"
#include "lexer.h"
#include "parser.h"
#include "ast.h"

Test(test_lex) {
    const char *input = " \t\n()\\.foob.bar jar";

    Token expected[] = {
        { .kind = LPAREN },
        { .kind = RPAREN },
        { .kind = SLASH },
        { .kind = DOT },
        { .kind = IDENT, .ident = (StringSlice){.str = "foob", .len = 4}},
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

Test(test_parse) {
    struct {
        char *input;
        char *output;
    } tests[] = {
        { "foo", "foo" },
        { "(foo)", "foo" },
        { "foo bar", "(foo bar)" },
        { "\\x.x", "(\\x.x)" },
    };
    int tests_len = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < tests_len; i++) {
        char *input = tests[i].input;
        char *output = tests[i].output;
        size_t out = 0;
        Token *tokens = lex_string(input, &out);
        Stmt *prog = parse(tokens);

        (void)prog;
        (void)output;
        // TODO: do something with this
        // char *prog_str = prog_display(prog);
        // assert(strcmp(prog_str, output) == 0);
    }

    (void)tests;
}
