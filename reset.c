/*
 * Reset-time implicit initialization
 */

#include <reset.h>

/** Initialized global data section storage start address (not aligned) */
extern char _DATA_LOAD_START[];
/** Initialized global data section storage end address (not aligned) */
extern char _DATA_LOAD_END[];
/** Initialized global data section runtime start address (not aligned) */
extern char _DATA_START[];

/**
 * Start address of uninitialized (implicitly zeroed) static data section
 * (not aligned).
 */
extern char _BSS_START[];
/**
 * End address of uninitialized (implicitly zeroed) static data section
 * (not aligned).
 */
extern char _BSS_END[];

/** Main function */
extern int main(void);

void
reset_handler(void)
{
    char *src;
    char *dst;

    /* Copy initialized global data to its runtime address, if necessary */
    if (_DATA_START != _DATA_LOAD_START) {
        for (src = _DATA_LOAD_START, dst = _DATA_START;
             src < _DATA_LOAD_END; src++, dst++) {
            *dst = *src;
        }
    }

    /* Initialize uninitialized static data */
    for (dst = _BSS_START; dst < _BSS_END; dst++) {
        *dst = 0;
    }

    main();
}
