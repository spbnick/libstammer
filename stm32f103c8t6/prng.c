/*
 * Pseudo-random number generator (PRNG)
 */

#include <prng.h>

static uint32_t
prng_calc(uint32_t state)
{
    /*
     * Xorshift32 from
     * https://en.wikipedia.org/wiki/Xorshift
     */
    uint32_t next_state = state;
    next_state ^= next_state << 13;
    next_state ^= next_state >> 17;
    next_state ^= next_state << 5;
    return next_state;
}

/** The global PRNG state */
static uint32_t prng_state;

void
prng_seed(uint32_t seed)
{
    prng_state = (seed == 0) ? 1 : seed;
}

uint32_t
prng_next(void)
{
    return (prng_state = prng_calc(prng_state)) - 1;
}
