/**
 * Christian Pankratz 2020.
 */

#include "configuration_manager.h"
#include <acutest.h>
#include <math.h>

void test_template(void)
{
	TEST_CHECK(1 != 0);
}

void test_write_load_delete(void)
{
	float lat = 42.2;
	float lon = 43.3;
	float utd = 44.4;

	TEST_CHECK(set_local_latitude(lat) != 0);
	TEST_CHECK(set_local_longitude(lon) != 0);
	TEST_CHECK(set_local_ut_difference(utd) != 0);

	TEST_CHECK(write_configuration_file() != 0);
	TEST_CHECK(load_configuration_file() != 0);

	float lat_ = 0;
	float lon_ = 0;
	float utd_ = 0;

	TEST_CHECK(get_local_latitude(&lat_) != 0);
	TEST_CHECK(get_local_longitude(&lon_) != 0);
	TEST_CHECK(get_local_ut_difference(&utd_) != 0);

	TEST_CHECK(fabs(lat - lat_) < 0.001);
	TEST_CHECK(fabs(lon - lon_) < 0.001);
	TEST_CHECK(fabs(utd - utd_) < 0.001);

	TEST_CHECK(delete_configuration_file() != 0);
}

TEST_LIST = {{"test_template.........", test_template},
			 {"test_load_and_write...", test_write_load_delete},
			 {NULL, NULL}};
