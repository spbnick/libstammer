/*
 * Semihosting interface
 */

/**
 * Write a null-terminated string to the host terminal.
 *
 * @param str   The pointer to the string to write.
 */
extern void semihosting_write0(const char *str);
