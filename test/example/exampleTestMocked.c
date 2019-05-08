#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

// Inclusion du module à tester.
#include "../../src/example/example.c"

static int setUp(void **state)
{
    return 0;
}

static int tearDown(void **state)
{
    return 0;
}

static void testFunctionTropBien0(void **state)
{
    assert_int_equal(0, 0);
}

static const struct CMUnitTest tests[] =
{
    cmocka_unit_test(testFunctionTropBien0)
};

int exampleTestMockedRunTests()
{
    return cmocka_run_group_tests_name("Test de la classe Example mockée", tests, setUp, tearDown);
}