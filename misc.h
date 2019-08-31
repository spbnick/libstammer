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
                asm ("wfi");    \
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

#endif /* _MISC_H */
