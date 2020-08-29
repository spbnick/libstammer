/*
 * Output sections
 */
SECTIONS {
    .vectors        : { vectors.o(.vectors) } >flash
    .text           : { *(.text) } >flash
    .rodata         : { *(.rodata) } >flash

    .data : {
        _DATA_START = ABSOLUTE(.);
        *(.data)
    } >sram AT>flash
    _DATA_SIZE = SIZEOF(.data);
    _DATA_END = _DATA_START + _DATA_SIZE;
    _DATA_LOAD_START = LOADADDR(.data);
    _DATA_LOAD_END = _DATA_LOAD_START + _DATA_SIZE;

    .bss : {
        _BSS_START = ABSOLUTE(.);
        *(.bss)
    } >sram
    _BSS_SIZE = SIZEOF(.bss);
    _BSS_END = _BSS_START + _BSS_SIZE;

    .stack ALIGN(4) : {
        _STACK_START = ABSOLUTE(.);
        . += _STACK_SIZE;
        . = ALIGN(4);
    } >sram
    _STACK_END = _STACK_START + SIZEOF(.stack);
}
