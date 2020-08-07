/**
 * Christian Pankratz 2020.
 */

#include "configuration_manager.h"
#include <acutest.h>

void test_template(void)
{
	TEST_CHECK(1 == 1);
}

void test_load_configuration_file(void)
{
	TEST_CHECK(load_configuration_file() == 1);
}

TEST_LIST = {{"test_template..................", test_template},
			 {"test_load_configuration_file...", test_load_configuration_file},
			 {NULL, NULL}};
