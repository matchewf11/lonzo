#include <string.h>
#include <stdio.h>

#include "token.h"

int token_cmp(const Token *a, const Token *b) {
    int kind_cmp = a->kind - b->kind;
    if (kind_cmp != 0) return kind_cmp;
    if (a->kind != IDENT) return 0;
    size_t ident_len_cmp = a->ident.len - b->ident.len;
    if (ident_len_cmp != 0) return ident_len_cmp;
    return strncmp(a->ident.str, b->ident.str, a->ident.len);
}

void token_display(const Token *token) {
    switch (token->kind) {
        case LPAREN:
            printf("<LPAREN>");
            break;
        case RPAREN:
            printf("<RPAREN>");
            break;
        case SLASH:
            printf("<SLASH>");
            break;
        case DOT:
            printf("<DOT>");
            break;
        case IDENT:
            printf("<IDENT>");
            break;
    }

    printf(": ");

    switch (token->kind) {
        case LPAREN:
            printf("(");
            break;
        case RPAREN:
            printf(")");
            break;
        case SLASH:
            printf("\\");
            break;
        case DOT:
            printf(".");
            break;
        case IDENT:
            printf("%.*s", (int)token->ident.len, token->ident.str);
            break;
    }

    printf("\n");
}
