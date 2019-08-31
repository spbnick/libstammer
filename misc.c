/*
 * Miscellaneous definitions
 */

#include <misc.h>

void *memset(void *s, int c, size_t n) {
    char *p = s;
    for (; n > 0; p++, n--) {
        *p = c;
    }
    return s;
}

void *memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    for (; n > 0; d++, s++, n--) {
        *d = *s;
    }
    return dest;
}
