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

int
memcmp2(const void *p1, size_t l1, const void *p2, size_t l2)
{
    const uint8_t *b1;
    const uint8_t *b2;
    assert(p1 != NULL || l1 == 0);
    assert(p2 != NULL || l2 == 0);
    for (b1 = p1, b2 = p2; l1 && l2; b1++, l1--, b2++, l2--) {
        if (*b1 < *b2) {
            return -1;
        } else if (*b1 > *b2) {
            return 1;
        }
    }
    return l1 == l2 ? 0 : (l1 < l2 ? -1 : 1);
}
