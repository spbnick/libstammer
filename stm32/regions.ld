/*
 * Memory regions
 */
MEMORY {
    flash (RX) : ORIGIN = 0x08000000, LENGTH = 4K
    sram (! RX) : ORIGIN = 0x20000000, LENGTH = 16K
}
