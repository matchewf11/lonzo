#ifndef PARSER_H
#define PARSER_H

#include "ast.h"
#include "token.h"

Stmt *parse(const Token *tokens);

#endif
