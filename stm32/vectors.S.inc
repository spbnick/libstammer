.syntax unified

.section ".text"

.thumb_func
default_handler:
    wfi
    b default_handler

.section ".vectors", "ax"

/* Define a vector table entry and a handler symbol */
.macro handler name
    .word \name
    .weak \name
    .thumb_set \name, default_handler
.endm

/* Stack top */
.word _STACK_END
/* Handlers */
.word reset_handler
