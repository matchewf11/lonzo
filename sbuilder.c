#include <stdlib.h>

#include "sbuilder.h"

StringBuilder sbuilder_with_cap(size_t cap) {
    return (StringBuilder) {
        .cap = cap,
        .len = 0,
        .str = malloc(sizeof(char) * cap),
    };
}
