/**
 * Christian Pankratz 2020.
 */

#include "base_functions.h"
#include <acutest.h>

void calculate_time_scale_output_test(void) {
  float days = 42;

  TEST_CHECK(calculate_time_scale(1999, 12, 31, 0.0, &days) != 0);
  TEST_CHECK(days == 0.0);
  TEST_MSG("days: %f", days);

  TEST_CHECK(calculate_time_scale(1998, 12, 31, 24.0, &days) != 0);
  TEST_CHECK(days == -365.0 + 1.0 /* 24h */);
  TEST_MSG("days: %f", days);

  TEST_CHECK(calculate_time_scale(2000, 12, 31, 24.0, &days) != 0);
  TEST_CHECK(days == +365.0 + 1.0 /* leap year */ + 1.0 /* 24h */);
  TEST_MSG("days: %f", days);

  float days1 = 111.0;
  float days2 = 222.0;
  TEST_CHECK(calculate_time_scale(1999, 12, 31, 24.0, &days1) != 0);
  TEST_CHECK(calculate_time_scale(2000, 01, 01, 00.0, &days2) != 0);
  TEST_CHECK(days1 == days2);
  TEST_MSG("days1: %f", days1);
  TEST_MSG("days2: %f", days2);
}

void calculate_time_scale_input_test(void) {

  float days;

  TEST_CHECK(calculate_time_scale(2000, 1, 1, 1, &days) != 0);
  TEST_CHECK(calculate_time_scale(1900, 1, 1, 1, &days) == 0);
  TEST_CHECK(calculate_time_scale(2100, 1, 1, 1, &days) == 0);

  TEST_CHECK(calculate_time_scale(2000, 10, 1, 1, &days) != 0);
  TEST_CHECK(calculate_time_scale(2000, 00, 1, 1, &days) == 0);
  TEST_CHECK(calculate_time_scale(2000, 13, 1, 1, &days) == 0);

  TEST_CHECK(calculate_time_scale(2000, 10, 01, 1, &days) != 0);
  TEST_CHECK(calculate_time_scale(2000, 10, 00, 1, &days) == 0);
  TEST_CHECK(calculate_time_scale(2000, 10, 32, 1, &days) == 0);

  TEST_CHECK(calculate_time_scale(2000, 10, 1, 10.0, &days) != 0);
  TEST_CHECK(calculate_time_scale(2000, 10, 1, -0.1, &days) == 0);
  TEST_CHECK(calculate_time_scale(2000, 10, 1, 24.1, &days) == 0);
}

TEST_LIST = {{NULL, calculate_time_scale_output_test},
             {NULL, calculate_time_scale_input_test},
             {NULL, NULL}};
