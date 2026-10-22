#ifndef AST_H
#define AST_H

#include "sslice.h"

typedef enum {
    APP,
    VAR,
    LAM,
} ExprKind;

typedef struct Expr Expr;

struct Expr {
    ExprKind kind;
    union {
        StringSlice var;
        struct {
            StringSlice param;
            Expr *body;
        } lam;
        struct {
            Expr *lexpr;
            Expr *rexpr;
        } app;
    } as;
};

typedef enum {
    EXPR,
    BIND,
} StmtKind;

typedef struct {
    StmtKind kind;
    Expr expr;
} Stmt;

#endif
