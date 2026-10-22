#ifndef SBUILDER_H
#define SBUILDER_H

#include <stddef.h>

typedef struct {
    char *str;
    size_t len;
    size_t cap;
} StringBuilder;

StringBuilder sbuilder_with_cap(size_t cap);

#endif
