/*
 * Miscellaneous definitions
 */

#include <../stm32/misc.h>
#include <stdint.h>
#include <stdbool.h>

void *
memset(void *s, int c, size_t n) {
    char *p = s;
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnonnull-compare"
    assert(s != NULL || n == 0);
    #pragma GCC diagnostic pop
    for (; n > 0; p++, n--) {
        *p = c;
    }
    return s;
}

void *
memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnonnull-compare"
    assert(dest != NULL || n == 0);
    assert(src != NULL || n == 0);
    #pragma GCC diagnostic pop
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

int
strcmp(const char *s1, const char *s2)
{
    const uint8_t *p1;
    const uint8_t *p2;

    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnonnull-compare"
    assert(s1 != NULL);
    assert(s2 != NULL);
    #pragma GCC diagnostic pop

    for (p1 = (const uint8_t*)s1, p2 = (const uint8_t*)s2;
         *p1 || *p2; p1++, p2++) {
        if (*p1 < *p2) {
            return -1;
        } else if (*p1 > *p2) {
            return 1;
        }
    }
    return 0;
}

/**
 * Output a character into the vsnprintf output buffer, if there's space.
 * Expects and affects locals buf_ptr, buf_len, and out_len.
 *
 * @param _c    The expression returning the character to output.
 */
#define VSNPRINTF_C(_c) \
    do {                        \
        if (buf_len > 1) {      \
            *buf_ptr++ = (_c);  \
            buf_len--;          \
        }                       \
        out_len++;              \
    } while (0)

/**
 * Output a string into the vsnprintf output buffer, if there's space.
 * Expects and affects locals buf_ptr, buf_len, and out_len.
 *
 * @param _str  The expression returning the string to output.
 * @param _len  The expression returning the maximum number of characters to
 *              be printed.
 */
#define VSNPRINTF_S(_str, _len) \
    do {                                                \
        const char *p = (_str);                         \
        size_t l = (_len);                              \
        char c;                                         \
        for (; (c = *p) != '\0' && l > 0; p++, l--) {   \
            VSNPRINTF_C(c);                             \
        }                                               \
    } while (0)

/**
 * Output an unsigned decimal integer into the vsnprintf output buffer, if
 * there's space. Expects and affects locals buf_ptr, buf_len, and out_len.
 *
 * @param _num  The expression returning the number to output.
 */
#define VSNPRINTF_U(_unum) \
    do {                                                        \
        unsigned int unum = (_unum);                            \
        char digit_buf[32];                                     \
        char * const digit_end = digit_buf + sizeof(digit_buf); \
        char *digit_ptr = digit_end;                            \
                                                                \
        do {                                                    \
            *--digit_ptr = '0' + unum % 10;                     \
        } while (unum /= 10);                                   \
                                                                \
        VSNPRINTF_S(digit_ptr, digit_end - digit_ptr);          \
    } while (0)

/**
 * Output a signed decimal integer into the vsnprintf output buffer, if
 * there's space. Expects and affects locals buf_ptr, buf_len, and out_len.
 *
 * @param _num  The expression returning the number to output.
 */
#define VSNPRINTF_D(_snum) \
    do {                                    \
        int snum = (_snum);                 \
        if (snum < 0) {                     \
            VSNPRINTF_C('-');               \
            snum = -snum;                   \
        }                                   \
        VSNPRINTF_U((unsigned int)snum);    \
    } while (0)

/**
 * Output an hexadecimal integer into the vsnprintf output buffer, if
 * there's space. Expects and affects locals buf_ptr, buf_len, and out_len.
 *
 * @param _num          The expression returning the number to output.
 * @param _uppercase    The expression returning true if uppercase letters
 *                      should be output, false if lowercase.
 */
#define VSNPRINTF_X(_num, _uppercase) \
    do {                                                                \
        unsigned int num = (_num);                                      \
        const char letter_base = ((_uppercase) ? 'A' : 'a') - 10;       \
        unsigned int nibble;                                            \
        char digit_buf[sizeof(num) * 2];                                \
        char * const digit_end = digit_buf + sizeof(digit_buf);         \
        char *digit_ptr = digit_end;                                    \
                                                                        \
        do {                                                            \
            nibble = num & 0xf;                                         \
            *--digit_ptr = (nibble < 10 ? '0' : letter_base) + nibble;  \
        } while (num >>= 4);                                            \
                                                                        \
        VSNPRINTF_S(digit_ptr, digit_end - digit_ptr);                  \
    } while (0)

size_t
vsnprintf(char *buf_ptr, size_t buf_len, const char *fmt, va_list ap)
{
    size_t out_len = 0;
    const char *fmt_ptr = fmt;
    const char *fmt_spec = NULL;
    char c;

    assert(buf_ptr != NULL || buf_len == 0);
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnonnull-compare"
    assert(fmt != NULL);
    #pragma GCC diagnostic pop

    for (;(c = *fmt_ptr); fmt_ptr++) {
        /* If outside format specification */
        if (fmt_spec == NULL) {
            if (c == '%') {
                fmt_spec = fmt_ptr;
            } else {
                VSNPRINTF_C(c);
            }
        } else {
            switch (c) {
            case '%':
                VSNPRINTF_C(c);
                break;
            case 'c':
                VSNPRINTF_C(va_arg(ap, int));
                break;
            case 's':
                VSNPRINTF_S(va_arg(ap, const char *), SIZE_MAX);
                break;
            case 'u':
                VSNPRINTF_U(va_arg(ap, unsigned int));
                break;
            case 'd':
                VSNPRINTF_D(va_arg(ap, int));
                break;
            case 'x':
                VSNPRINTF_X(va_arg(ap, unsigned int), false);
                break;
            case 'X':
                VSNPRINTF_X(va_arg(ap, unsigned int), true);
                break;
            default:
                VSNPRINTF_S(fmt_spec, fmt_ptr - fmt_spec + 1);
                break;
            }
            fmt_spec = NULL;
        }
    }

    if (fmt_spec != NULL) {
        VSNPRINTF_S(fmt_spec, fmt_ptr - fmt_spec);
    }

    if (buf_len > 0) {
        *buf_ptr = '\0';
    }

    return out_len;
}

size_t
snprintf(char *buf_ptr, size_t buf_len, const char *fmt, ...)
{
    size_t out_len;
    va_list ap;

    assert(buf_ptr != NULL || buf_len == 0);
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnonnull-compare"
    assert(fmt != NULL);
    #pragma GCC diagnostic pop

    va_start(ap, fmt);
    out_len = vsnprintf(buf_ptr, buf_len, fmt, ap);
    va_end(ap);

    return out_len;
}
