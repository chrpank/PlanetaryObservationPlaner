/**
 * Christian Pankratz 2020.
 */

#include "base_functions.h"
#include <acutest.h>

void calculate_time_scale_test(void) {
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

void calculate_orbital_elements_test(void) {

  // sun
  float value1 = 1.0;
  float value2 = 2.0;
  float value3 = 3.0;
  float value4 = 4.0;
  float value5 = 5.0;
  float value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("sun", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // moon
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("moon", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // mercury
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("mercury", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // venus
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("venus", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // mars
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("mars", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // jupiter
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("jupiter", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // saturn
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("saturn", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // uranus
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("uranus", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // neptune
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("neptune", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) != 0);
  TEST_CHECK(value1 != 1.0 && //
             value2 != 2.0 && //
             value3 != 3.0 && //
             value4 != 4.0 && //
             value5 != 5.0 && //
             value6 != 6.0);

  // none
  value1 = 1.0;
  value2 = 2.0;
  value3 = 3.0;
  value4 = 4.0;
  value5 = 5.0;
  value6 = 6.0;

  TEST_CHECK(calculate_orbital_elements("none", &value1, &value2, &value3,
                                        &value4, &value5, &value6, 1) == 0);
  TEST_CHECK(value1 == 1.0 && //
             value2 == 2.0 && //
             value3 == 3.0 && //
             value4 == 4.0 && //
             value5 == 5.0 && //
             value6 == 6.0);
}

TEST_LIST = {{NULL, calculate_time_scale_test},
             {NULL, calculate_orbital_elements_test},
             {NULL, NULL}};
