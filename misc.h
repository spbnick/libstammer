/*
 * Miscellaneous definitions
 */

#ifndef _MISC_H
#define _MISC_H

/** Return number of elements in an array */
#define ARRAY_SIZE(_x) (sizeof(_x) / sizeof((_x)[0]))

/** Return minimum */
#define MIN(_x, _y) ((_x) < (_y) ? (_x) : (_y))

/** Return maximum */
#define MAX(_x, _y) ((_x) > (_y) ? (_x) : (_y))

#endif /* _MISC_H */
