#include "PCUnit.h"
#include "test.h"
#include <stdio.h>

PCU_TestCase suite[] = {
	{ "RingBuf_tests", RingBuf_tests, RingBuf_tests_initialize, RingBuf_tests_cleanup },
	{ "StrToken_tests", StrToken_tests },
	PCU_NULL,
};


int main(int argc, char **argv)
{
	PCU_set_putchar(putchar);
	PCU_set_getchar(getchar);
	PCU_enable_color();
/*    PCU_disable_color();*/
	if (argc >= 2) {
		PCU_set_mode(PCU_MODE_INTERACTIVE);
	}
	PCU_run(suite);
	return 0;
}

