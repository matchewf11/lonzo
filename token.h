#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    LPAREN,
    RPAREN,
    IDENT,
    SLASH,
    DOT,
} TokenKind;

typedef struct {
    TokenKind kind;
    union {} as;
} Token;

#endif
