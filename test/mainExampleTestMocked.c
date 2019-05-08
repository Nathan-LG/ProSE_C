#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmocka/cmocka.h"
#include "example/exampleTestMocked.c"

#define NB_SUITE_TESTS 1

int (* suite_tests[])(void) = {exampleTestMockedRunTests};

static void testRunner();

int main(int argc, char * argv[])
{
	if ((argc > 1)) {
		if (!strcmp(argv[1], "-texte")) {
			cmocka_set_message_output(CM_OUTPUT_STDOUT);
		} else if (!strcmp(argv[1], "-subunit")) {
			cmocka_set_message_output(CM_OUTPUT_SUBUNIT);
		} else if (!strcmp(argv[1], "-tap")) {
			cmocka_set_message_output(CM_OUTPUT_TAP);
		} else if (!strcmp(argv[1], "-xml")) {
			cmocka_set_message_output(CM_OUTPUT_XML);
		}
	}

	testRunner();
	return 0;
}

static void testRunner()
{
	int i;

	for (i = 0; i < NB_SUITE_TESTS; i++) {
		suite_tests[i]();
	}
}
