/*
 * Library test
 */

#include <test.h>
#include <misc.h>

/**
 * Test the memcmp2 function.
 *
 * @return True if the function works correctly, false otherwise.
 */
static bool
test_memcmp2(void)
{
    bool passed = true;
    passed = memcmp2(NULL, 0, NULL, 0) == 0 && passed;
    passed = memcmp2("", 0, NULL, 0) == 0 && passed;
    passed = memcmp2(NULL, 0, "", 0) == 0 && passed;
    passed = memcmp2("", 0, "", 0) == 0 && passed;
    passed = memcmp2("x", 1, NULL, 0) == 1 && passed;
    passed = memcmp2(NULL, 0, "x", 1) == -1 && passed;
    passed = memcmp2("x", 1, "x", 1) == 0 && passed;
    passed = memcmp2("y", 1, "x", 1) == 1 && passed;
    passed = memcmp2("x", 1, "y", 1) == -1 && passed;
    passed = memcmp2("xx", 2, "xx", 2) == 0 && passed;
    passed = memcmp2("x", 1, "xx", 2) == -1 && passed;
    passed = memcmp2("xx", 2, "x", 1) == 1 && passed;
    passed = memcmp2("xy", 2, "xx", 2) == 1 && passed;
    passed = memcmp2("xx", 2, "xy", 2) == -1 && passed;
    return passed;
}

/**
 * Test the strcmp function.
 *
 * @return True if the function works correctly, false otherwise.
 */
static bool
test_strcmp(void)
{
    bool passed = true;
    passed = strcmp("", "") == 0 && passed;
    passed = strcmp("x", "") == 1 && passed;
    passed = strcmp("", "x") == -1 && passed;
    passed = strcmp("xx", "") == 1 && passed;
    passed = strcmp("", "xx") == -1 && passed;
    passed = strcmp("x", "x") == 0 && passed;
    passed = strcmp("y", "x") == 1 && passed;
    passed = strcmp("x", "y") == -1 && passed;
    passed = strcmp("xx", "xx") == 0 && passed;
    passed = strcmp("xx", "x") == 1 && passed;
    passed = strcmp("x", "xx") == -1 && passed;
    passed = strcmp("xy", "xx") == 1 && passed;
    passed = strcmp("xx", "xy") == -1 && passed;
    passed = strcmp("xx", "xx") == 0 && passed;
    passed = strcmp("yx", "xx") == 1 && passed;
    passed = strcmp("xx", "yx") == -1 && passed;
    return passed;
}

/**
 * Test the snprintf function.
 *
 * @return True if the function works correctly, false otherwise.
 */
static bool
test_snprintf(void)
{
    bool passed = true;
    char buf[16] = {0xff,};

#define TEST_NULL(_ret, _fmt, _args...) \
    (passed = snprintf(NULL, 0, _fmt, ##_args) == (_ret) && passed)

#define TEST_NBUF(_ret, _out, _len, _fmt, _args...) \
    do {                                                                \
        const char out[] = {_out};                                      \
        memset(buf, '*', sizeof(buf) - 1);                              \
        buf[sizeof(buf) - 1] = '\0';                                    \
        passed = snprintf(buf, _len, _fmt, ##_args) == (_ret) &&        \
                 memcmp2(buf, sizeof(buf), out, sizeof(out)) == 0 &&    \
                 passed;                                                \
    } while (0)

#define TEST_BUF(_ret, _out, _fmt, _args...) \
    TEST_NBUF(_ret, _out, sizeof(buf), _fmt, ##_args)

    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wformat-zero-length"
    #pragma GCC diagnostic ignored "-Wformat-truncation"
    #pragma GCC diagnostic ignored "-Wformat"

    TEST_NULL(0, "");
    TEST_NULL(1, "x");
    TEST_NULL(2, "xy");
    TEST_NULL(3, "xyz");

    TEST_NULL(0, "%s", "");
    TEST_NULL(1, "%s", "x");
    TEST_NULL(2, "%s", "xy");
    TEST_NULL(3, "%s", "xyz");

    TEST_BUF(0, "\0**************", "");
    TEST_BUF(1, "x\0*************", "x");
    TEST_BUF(2, "xy\0************", "xy");
    TEST_BUF(3, "xyz\0***********", "xyz");

    TEST_NBUF(0, "***************", 0, "");
    TEST_NBUF(1, "***************", 0, "x");
    TEST_NBUF(2, "***************", 0, "xy");
    TEST_NBUF(0, "\0**************", 1, "");
    TEST_NBUF(0, "\0**************", 2, "");

    TEST_NBUF(3, "***************", 0, "xyz");
    TEST_NBUF(3, "\0**************", 1, "xyz");
    TEST_NBUF(3, "x\0*************", 2, "xyz");
    TEST_NBUF(3, "xy\0************", 3, "xyz");
    TEST_NBUF(3, "xyz\0***********", 4, "xyz");

    TEST_NBUF(1, "***************", 0, "%");
    TEST_NBUF(1, "\0**************", 1, "%");
    TEST_NBUF(1, "%\0*************", 2, "%");

    TEST_NBUF(1, "***************", 0, "%%");
    TEST_NBUF(1, "\0**************", 1, "%%");
    TEST_NBUF(1, "%\0*************", 2, "%%");

    TEST_NBUF(2, "***************", 0, "%%%");
    TEST_NBUF(2, "\0**************", 1, "%%%");
    TEST_NBUF(2, "%\0*************", 2, "%%%");
    TEST_NBUF(2, "%%\0************", 3, "%%%");

    TEST_BUF(0, "\0**************", "%s", "");
    TEST_BUF(0, "\0**************", "%s%s", "", "");
    TEST_BUF(1, "x\0*************", "%s", "x");
    TEST_BUF(2, "xy\0************", "%s%s", "x", "y");
    TEST_BUF(3, "x-y\0***********", "%s-%s", "x", "y");
    TEST_BUF(2, "xy\0************", "%s", "xy");
    TEST_BUF(3, "xyz\0***********", "%s", "xyz");

    TEST_NBUF(1, "***************", 0, "%c", 'x');
    TEST_NBUF(1, "\0**************", 1, "%c", 'x');
    TEST_NBUF(1, "x\0*************", 2, "%c", 'x');
    TEST_BUF(2, "xy\0************", "%c%c", 'x', 'y');
    TEST_BUF(3, "x-y\0***********", "%c-%c", 'x', 'y');

    TEST_BUF(1, "0\0*************", "%u", 0);
    TEST_BUF(1, "1\0*************", "%u", 1);
    TEST_BUF(1, "9\0*************", "%u", 9);
    TEST_BUF(2, "10\0************", "%u", 10);
    TEST_BUF(2, "11\0************", "%u", 11);
    TEST_BUF(10, "4294967295\0****", "%u", 4294967295U);

    TEST_NBUF(1, "***************", 0, "%u", 0);
    TEST_NBUF(1, "\0**************", 1, "%u", 0);
    TEST_NBUF(1, "0\0*************", 2, "%u", 0);

    TEST_NBUF(10, "***************", 0, "%u", 4294967295U);
    TEST_NBUF(10, "\0**************", 1, "%u", 4294967295U);
    TEST_NBUF(10, "4\0*************", 2, "%u", 4294967295U);
    TEST_NBUF(10, "429496729\0*****", 10, "%u", 4294967295U);
    TEST_NBUF(10, "4294967295\0****", 11, "%u", 4294967295U);

    TEST_BUF(1, "0\0*************", "%d", 0);

    TEST_BUF(1, "1\0*************", "%d", 1);
    TEST_BUF(1, "9\0*************", "%d", 9);
    TEST_BUF(2, "10\0************", "%d", 10);
    TEST_BUF(2, "11\0************", "%d", 11);
    TEST_BUF(10, "2147483647\0****", "%d", 2147483647);

    TEST_BUF(2, "-1\0************", "%d", -1);
    TEST_BUF(2, "-9\0************", "%d", -9);
    TEST_BUF(3, "-10\0***********", "%d", -10);
    TEST_BUF(3, "-11\0***********", "%d", -11);
    TEST_BUF(11, "-2147483648\0***", "%d", -2147483648);

    TEST_NBUF(2, "***************", 0, "%d", -1);
    TEST_NBUF(2, "\0**************", 1, "%d", -1);
    TEST_NBUF(2, "-\0*************", 2, "%d", -1);
    TEST_NBUF(2, "-1\0************", 3, "%d", -1);

    TEST_BUF(1, "0\0*************", "%x", 0);
    TEST_BUF(1, "1\0*************", "%x", 1);
    TEST_BUF(1, "9\0*************", "%x", 9);
    TEST_BUF(1, "a\0*************", "%x", 10);
    TEST_BUF(1, "b\0*************", "%x", 11);
    TEST_BUF(1, "f\0*************", "%x", 15);
    TEST_BUF(2, "10\0************", "%x", 16);
    TEST_BUF(8, "ffffffff\0******", "%x", 4294967295U);

    TEST_BUF(1, "0\0*************", "%X", 0);
    TEST_BUF(1, "1\0*************", "%X", 1);
    TEST_BUF(1, "9\0*************", "%X", 9);
    TEST_BUF(1, "A\0*************", "%X", 10);
    TEST_BUF(1, "B\0*************", "%X", 11);
    TEST_BUF(1, "F\0*************", "%X", 15);
    TEST_BUF(2, "10\0************", "%X", 16);
    TEST_BUF(8, "FFFFFFFF\0******", "%X", 4294967295U);

    #pragma GCC diagnostic pop
    return passed;
}

bool
test(void)
{
    bool passed = true;
    passed = test_memcmp2() && passed;
    passed = test_strcmp() && passed;
    passed = test_snprintf() && passed;
    return passed;
}
