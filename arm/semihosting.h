/*
 * Semihosting interface
 */

#include <stddef.h>

/**
 * Write a null-terminated string to the host terminal.
 *
 * @param str   The pointer to the string to write.
 */
extern void semihosting_write0(const char *str);

/**
 * Print arguments to the host terminal, using a printf-style format string
 * with a subset of supported conversion specifications (see vsnprintf() for
 * specifics). Maximum output length is 255 characters per call.
 *
 * @param fmt       The printf-style format string using the conversion
 *                  specifications described above.
 * @param ...       Conversion arguments.
 *
 * @return The number of characters printed.
 */
extern size_t semihosting_printf(const char *fmt, ...)
                                 __attribute__ ((format (printf, 1, 2)));
