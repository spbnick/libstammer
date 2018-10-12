/*
 * Miscellaneous definitions
 */

#ifndef _MISC_H
#define _MISC_H

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

#endif /* _MISC_H */
