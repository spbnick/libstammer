/*
 * Memory regions
 */
MEMORY {
    flash (RX) : ORIGIN = 0x08000000, LENGTH = 64K
    sram (! RX) : ORIGIN = 0x20000000, LENGTH = 8K
}
