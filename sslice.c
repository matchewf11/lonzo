#include <ctype.h>
#include <string.h>

#include "sslice.h"

StringSlice sslice_from_str(const char *str) {
    return (StringSlice) {
        .str = str,
        .len = strlen(str),
    };
}

char *sslice_strndup(const StringSlice *sslice) {
    return strndup(sslice->str, sslice->len);
}

void sslice_chopl(StringSlice *sslice) {
    if (sslice->len == 0) return;
    sslice->str++;
    sslice->len--;
}

void sslice_chopr(StringSlice *sslice) {
    if (sslice->len == 0) return;
    sslice->len--;
}

void sslice_triml(StringSlice *sslice) {
    while (sslice->len > 0 && isspace(sslice->str[0])) {
        sslice_chopl(sslice);
    }
}
