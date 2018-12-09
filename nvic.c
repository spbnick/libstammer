/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#include <nvic.h>

void
nvic_int_set_enable_ext(unsigned int ext_num)
{
    enum nvic_int num;
    assert(ext_num < 16);
    if (ext_num == 0) {
        num = NVIC_INT_EXTI0;
    } else if (ext_num == 1) {
        num = NVIC_INT_EXTI1;
    } else if (ext_num == 2) {
        num = NVIC_INT_EXTI2;
    } else if (ext_num == 3) {
        num = NVIC_INT_EXTI3;
    } else if (ext_num == 4) {
        num = NVIC_INT_EXTI4;
    } else if (ext_num <= 9) {
        num = NVIC_INT_EXTI9_5;
    } else {
        num = NVIC_INT_EXTI15_10;
    }
    nvic_int_set_enable(num);
}
