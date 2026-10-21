#ifndef TOKEN_H
#define TOKEN_H

#include "sslice.h"

typedef enum {
    LPAREN,
    RPAREN,
    IDENT,
    SLASH,
    DOT,
} TokenKind;

typedef struct {
    TokenKind kind;
    StringSlice ident;
} Token;

int token_cmp(const Token *a, const Token *b);

#endif
