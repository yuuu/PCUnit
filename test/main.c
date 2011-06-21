#include "../PCUnit/PCUnit.h"
#include <string.h>
#include <stdio.h>

extern PCU_Test string_tests[];
extern PCU_Test snprintf_tests[];
extern PCU_Test strtol_tests[];
extern PCU_Test assert_tests[];

PCU_TestCase suite[] = {
	{ "snprintf_tests", snprintf_tests },
	{ "string_tests", string_tests },
	{ "strtol_tests", strtol_tests },
	PCU_NULL,
};

PCU_TestCase suite_assert[] = {
	{ "assert_tests", assert_tests },
	PCU_NULL,
};

int main(int argc, char **argv)
{
	PCU_enable_color();
	PCU_set_getchar(getchar);
	if (argc > 1) {
		PCU_set_mode(PCU_MODE_INTERACTIVE);
		if (strcmp(argv[1], "assert") == 0) {
			PCU_run(suite_assert);
		} else {
			PCU_run(suite);
		}
	} else {
		PCU_run(suite);
	}
	return 0;
}

