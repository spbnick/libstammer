/*
 * Reset-time implicit initialization
 */

#include <../stm32/reset.h>
#include <../stm32/misc.h>

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
    /* Copy initialized global data to its runtime address, if necessary */
    if (_DATA_START != _DATA_LOAD_START) {
        memcpy(_DATA_START, _DATA_LOAD_START,
               _DATA_LOAD_END - _DATA_LOAD_START);
    }

    /* Initialize uninitialized static data */
    memset(_BSS_START, 0, _BSS_END - _BSS_START);

    main();
}
