#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

#include "token.h"

Token *lex_string(const char *input, size_t *out);

#endif
