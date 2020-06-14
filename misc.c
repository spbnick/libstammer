/*
 * Miscellaneous definitions
 */

#include <misc.h>

void *
memset(void *s, int c, size_t n) {
    char *p = s;
    assert(s != NULL || n == 0);
    for (; n > 0; p++, n--) {
        *p = c;
    }
    return s;
}

void *
memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    assert(dest != NULL || n == 0);
    assert(src != NULL || n == 0);
    for (; n > 0; d++, s++, n--) {
        *d = *s;
    }
    return dest;
}
