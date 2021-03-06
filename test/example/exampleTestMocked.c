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

void __wrap_MailboxInit(Example * this) {
    function_called();
}

static void testExampleNewCallsMailboxInit(void **state)
{
    expect_function_call(MailboxInit);
    ExampleNew();
}

static const struct CMUnitTest tests[] =
{
    cmocka_unit_test(testExampleNewCallsMailboxInit)
};

int exampleTestMockedRunTests()
{
    return cmocka_run_group_tests_name("Test de la classe Example mockée", tests, setUp, tearDown);
}