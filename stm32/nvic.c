/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#include <../stm32/nvic.h>

enum nvic_int
nvic_int_from_ext(unsigned int ext_num)
{
    assert(ext_num < 16);
    if (ext_num == 0) {
        return NVIC_INT_EXTI0;
    } else if (ext_num == 1) {
        return NVIC_INT_EXTI1;
    } else if (ext_num == 2) {
        return NVIC_INT_EXTI2;
    } else if (ext_num == 3) {
        return NVIC_INT_EXTI3;
    } else if (ext_num == 4) {
        return NVIC_INT_EXTI4;
    } else if (ext_num <= 9) {
        return NVIC_INT_EXTI9_5;
    } else {
        return NVIC_INT_EXTI15_10;
    }
}
