#include <string.h>

#include "token.h"

int token_cmp(const Token *a, const Token *b) {
    int kind_cmp = a->kind - b->kind;
    if (kind_cmp != 0) return kind_cmp;
    if (a->kind != IDENT) return 0;
    size_t ident_len_cmp = a->ident.len - b->ident.len;
    if (ident_len_cmp != 0) return ident_len_cmp;
    return strncmp(a->ident.str, b->ident.str, a->ident.len);
}
