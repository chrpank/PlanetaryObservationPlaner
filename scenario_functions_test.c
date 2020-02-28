/**
 * Christian Pankratz 2020.
 */

#include "scenario_functions.h"

#include <acutest.h>

void scenario_calculate_azimuthal_coordinates_test(void) {

  float az, alt;

  TEST_CHECK(scenario_calculate_azimuthal_coordinates(
                 "sun", 2020, 2, 28, 12, 13.3, 52.45, &az, &alt) != 0);

  TEST_CHECK(1 == 0);
  TEST_MSG("az: %f", az);
  TEST_MSG("alt: %f", alt);
}

TEST_LIST = {{NULL, scenario_calculate_azimuthal_coordinates_test},
             {NULL, NULL}};
