/*
 * Pseudo-random number generator (PRNG)
 */

#include <stdint.h>

#ifndef _STM32_PRNG_H
#define _STM32_PRNG_H

/** Maximum generated random number */
#define PRNG_MAX    (UINT32_MAX - 1)

/**
 * Seed the state of the global PRNG.
 *
 * @param seed  The seed.
 */
extern void prng_seed(uint32_t seed);

/**
 * Calculate the next random number of the global PRNG.
 *
 * @return Next random number, between PRNG_MIN and PRNG_MAX.
 */
extern uint32_t prng_next(void);

#endif /* _STM32_PRNG_H */
