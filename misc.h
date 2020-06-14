/*
 * Miscellaneous definitions
 */

#ifndef _MISC_H
#define _MISC_H

#include <stddef.h>

/** Return number of elements in an array */
#define ARRAY_SIZE(_x) (sizeof(_x) / sizeof((_x)[0]))

/** Return minimum */
#define MIN(_x, _y) ((_x) < (_y) ? (_x) : (_y))

/** Return maximum */
#define MAX(_x, _y) ((_x) > (_y) ? (_x) : (_y))

/**
 * Assert an expression is true.
 * Go into an endless loop if the expression is false.
 *
 * @param _expr The expression to assert.
 */
#ifndef NDEBUG
#define assert(_expr) \
    do {                        \
        if (!(_expr)) {         \
            do {                \
            } while (1);        \
        }                       \
    } while (0)
#else
#define assert(_expr)
#endif

/**
 * Fill memory with a constant byte.
 *
 * @param s     The memory to fill.
 * @param c     The byte value to fill with.
 * @param n     Number of bytes to fill.
 *
 * @return The pointer to the filled memory (s).
 */
extern void *memset(void *s, int c, size_t n);

/**
 * Copy a memory area. The source and destination must not overlap.
 *
 * @param dest  The destination memory area.
 * @param src   The source memory area.
 * @param n     Number of bytes to copy.
 *
 * @return The destination memory area (dest).
 */
extern void *memcpy(void *dest, const void *src, size_t n);

/**
 * Compare two memory areas of different lengths.
 *
 * @param p1    Pointer to the first memory area.
 * @param l1    Length of the first memory area.
 * @param p2    Pointer to the second memory area.
 * @param l1    Length of the second memory area.
 *
 * @return  0 if p1 == p2.
 *          1 if p1 > p2.
 *         -1 if p2 < p2.
 */
extern int memcmp2(const void *p1, size_t l1, const void *p2, size_t l2);

/**
 * Compare two memory areas of the same length.
 *
 * @param p1    Pointer to the first memory area.
 * @param p2    Pointer to the second memory area.
 * @param l     Length of each memory area.
 *
 * @return  0 if p1 == p2.
 *          1 if p1 > p2.
 *         -1 if p2 < p2.
 */
static inline int
memcmp(const void *p1, const void *p2, size_t l)
{
    return memcmp2(p1, l, p2, l);
}

/**
 * Calculate null-terminated string length.
 *
 * @param s The string to calculate the length of.
 *
 * @return The length of the string, bytes.
 */
static inline size_t
strlen(const char *s)
{
    const char *p;
    for (p = s; *p; p++);
    return p - s;
}

/**
 * Compare two null-terminated strings.
 *
 * @param s1    The first string to compare.
 * @param s2    The second string to compare.
 *
 * @return  0 if s1 == s2.
 *          1 if s1 > s2.
 *         -1 if s1 < s2.
 */
extern int strcmp(const char *s1, const char *s2);

#endif /* _MISC_H */
