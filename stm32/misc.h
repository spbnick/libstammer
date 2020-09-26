/*
 * Miscellaneous definitions
 */

#ifndef _MISC_H
#define _MISC_H

#include <stddef.h>
#include <stdarg.h>

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
 * Format arguments into a buffer using a printf-style format string with a
 * subset of supported conversion specifications and conversion arguments
 * supplied as a variable argument list. The following conversion
 * specifications are supported:
 *
 *  %%
 *  %c
 *  %s
 *  %u
 *  %d
 *  %x
 *  %X
 *
 * @param buf_ptr   Pointer to the buffer to output to.
 * @param buf_len   The length of the buffer to output to.
 * @param fmt       The printf-style format string using the conversion
 *                  specifications described above.
 * @param ap        Conversion arguments.
 *
 * @return The number of characters required to format the supplied arguments
 *         with the supplied format string, not counting the terminating null
 *         byte, regardless of how much space was available in the output
 *         buffer. The buffer receives only the characters that would fit
 *         together with the terminating null byte.
 */
extern size_t vsnprintf(char *buf_ptr, size_t buf_len,
                        const char *fmt, va_list ap);

/**
 * Format arguments into a buffer using a printf-style format string with a
 * subset of supported conversion specifications (see vsnprintf() for
 * specifics).
 *
 * @param buf_ptr   Pointer to the buffer to output to.
 * @param buf_len   The length of the buffer to output to.
 * @param fmt       The printf-style format string using the conversion
 *                  specifications described above.
 * @param ...       Conversion arguments.
 *
 * @return The number of characters required to format the supplied arguments
 *         with the supplied format string, not counting the terminating null
 *         byte, regardless of how much space was available in the output
 *         buffer. The buffer receives only the characters that would fit
 *         together with the terminating null byte.
 */
extern size_t snprintf(char *buf_ptr, size_t buf_len,
                       const char *fmt, ...)
                       __attribute__ ((format (printf, 3, 4)));

#endif /* _MISC_H */
