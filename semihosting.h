/*
 * Semihosting interface
 */

/**
 * Write a zero-terminated string to the host terminal.
 *
 * @param ptr   The pointer to the string to write.
 */
extern void semihosting_write0(const char *ptr);
