INCLUDE "memory.ld"

SECTIONS {
    .text   : { *(.vectors) *(.text) *(.rodata) } >flash
    .data   : { *(.data) } >sram AT>flash
    .bss    : { *(.bss) } >sram AT>flash
}
