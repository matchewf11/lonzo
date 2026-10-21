#ifndef SSLICE_H
#define SSLICE_H

typedef struct {
    const char *str;
    size_t len;
} StringSlice;

StringSlice sslice_from_str(const char *str);

void sslice_chopl(StringSlice *sslice);
void sslice_chopr(StringSlice *sslice);

void sslice_triml(StringSlice *sslice);

char *sslice_strndup(const StringSlice *sslice);

#endif
