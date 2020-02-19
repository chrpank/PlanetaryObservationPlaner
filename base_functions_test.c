/**
 * Christian Pankratz 2020.
 */

#include "base_functions.h"
#include <acutest.h>
#include <math.h>

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

void calculate_value_reduction_test(void) {
  float value;
  float factor = 360.0;

  value = -1000.0;
  TEST_CHECK(calculate_value_reduction(factor, &value) != 0);
  TEST_CHECK(value >= 0.0 && value <= factor);

  value = +1000.0;
  TEST_CHECK(calculate_value_reduction(factor, &value) != 0);
  TEST_CHECK(value >= 0.0 && value <= factor);

  value = 0.0;
  TEST_CHECK(calculate_value_reduction(factor, &value) != 0);
  TEST_CHECK(value == 0.0);

  value = 180.0;
  TEST_CHECK(calculate_value_reduction(factor, &value) != 0);
  TEST_CHECK(value == 180.0);

  value = 360.0;
  TEST_CHECK(calculate_value_reduction(factor, &value) != 0);
  TEST_CHECK(value == factor);

  value = -1000000.0;
  TEST_CHECK(calculate_value_reduction(factor, &value) == 0);

  value = +1000000.0;
  TEST_CHECK(calculate_value_reduction(factor, &value) == 0);
}

void calculate_obliquity_ecliptic_test(void) {
  float ecl1 = 0.0;
  float ecl2 = 0.0;

  TEST_CHECK(calculate_obliquity_ecliptic(&ecl1, 000.0) != 0);
  TEST_CHECK(calculate_obliquity_ecliptic(&ecl2, 100.0) != 0);

  TEST_CHECK(ecl1 != ecl2);
}

void calculate_local_sidereal_time_test(void) {
  int y = 2025;
  int m = 2;
  int d = 12;

  float hour = 19.0;
  float minute = 35.0;
  float second = 11.0;

  float local_longitude = 13.1;

  float UT = hour + minute / 60.0 + second / 3600.0;
  float LST_ = 6.0;
  float LST;

  TEST_CHECK(
      calculate_local_sidereal_time(y, m, d, UT, local_longitude, &LST) != 0);

  TEST_CHECK(fabs(LST - LST_) < 0.01f);
}

void calculate_true_anomaly_test(void) {
  float r = 0.0;
  float v = 1.0;

  const float M = 180.0;
  const float e = 0.0;
  const float a = 1.0;

  TEST_CHECK(calculate_true_anomaly(M, e, a, &r, &v) != 0);

  TEST_CHECK(r == 1.0);
  TEST_CHECK(v == 180.0);

  float value;
  TEST_CHECK(calculate_true_anomaly(+361.0, +0.0, +1.0, &value, &value) == 0);
  TEST_CHECK(calculate_true_anomaly(-1.000, +0.0, +1.0, &value, &value) == 0);
  TEST_CHECK(calculate_true_anomaly(+180.0, +1.1, +1.0, &value, &value) == 0);
  TEST_CHECK(calculate_true_anomaly(+180.0, -0.1, +1.0, &value, &value) == 0);
}

void calculate_position_in_space_test(void) {
  float x = 0.0;
  float y = 0.0;
  float z = 0.0;
  float lonecl = 0.0;
  float latecl = 0.0;

  TEST_CHECK(calculate_position_in_space(1.0, 2.0, 3.0, 4.0, 5.0, &x, &y, &z,
                                         &lonecl, &latecl) != 0);
  TEST_CHECK(x != 0.0);
  TEST_CHECK(y != 0.0);
  TEST_CHECK(z != 0.0);
  TEST_CHECK(lonecl != 0.0);
  TEST_CHECK(latecl != 0.0);

  float distance = sqrt(x * x + y * y + z * z);
  TEST_CHECK(fabs(distance - 1.0) < 0.001);
}

void calculate_pertubations_moon_test(void) {

  float value1 = 0.0;
  float value2 = 0.0;
  float value3 = 0.0;

  TEST_CHECK(calculate_pertubations_moon(1.0, 2.0, 3.0, 4.0, 5.0, &value1,
                                         &value2, &value3) != 0);

  TEST_CHECK(value1 != 0);
  TEST_CHECK(value2 != 0);
  TEST_CHECK(value3 != 0);
}

void calculate_pertubations_planets_test(void) {

  float lonecl_j = 0.0;
  float latecl_j = 0.0;
  float lonecl_s = 0.0;
  float latecl_s = 0.0;
  float lonecl_u = 0.0;
  float latecl_u = 0.0;

  TEST_CHECK(calculate_pertubations_planets(1.0, 2.0, 3.0, &lonecl_j, &latecl_j,
                                            &lonecl_s, &latecl_s, &lonecl_u,
                                            &latecl_u) != 0);

  TEST_CHECK(lonecl_j != 0 || latecl_j != 0);
  TEST_CHECK(lonecl_s != 0 || latecl_s != 0);
  TEST_CHECK(lonecl_u != 0 || latecl_u != 0);
}

void calculate_sind_cosd_atan2d_test(void) {
  TEST_CHECK(fabs(sind(000.0) - (+0.0)) < 0.001);
  TEST_CHECK(fabs(sind(090.0) - (+1.0)) < 0.001);
  TEST_CHECK(fabs(sind(180.0) - (+0.0)) < 0.001);
  TEST_CHECK(fabs(sind(270.0) - (-1.0)) < 0.001);
  TEST_CHECK(fabs(sind(360.0) - (+0.0)) < 0.001);

  TEST_CHECK(fabs(cosd(000.0) - (+1.0)) < 0.001);
  TEST_CHECK(fabs(cosd(090.0) - (+0.0)) < 0.001);
  TEST_CHECK(fabs(cosd(180.0) - (-1.0)) < 0.001);
  TEST_CHECK(fabs(cosd(270.0) - (+0.0)) < 0.001);
  TEST_CHECK(fabs(cosd(360.0) - (+1.0)) < 0.001);

  TEST_CHECK(fabs(atan2d(+0.0, +0.0) - (+000.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(+0.0, +1.0) - (+000.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(+0.0, -1.0) - (+180.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(+1.0, +0.0) - (+090.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(+1.0, +1.0) - (+045.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(+1.0, -1.0) - (+135.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(-1.0, +0.0) - (-090.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(-1.0, +1.0) - (-045.0)) < 0.001);
  TEST_CHECK(fabs(atan2d(-1.0, -1.0) - (-135.0)) < 0.001);
}

TEST_LIST = {{NULL, calculate_time_scale_test},
             {NULL, calculate_orbital_elements_test},
             {NULL, calculate_value_reduction_test},
             {NULL, calculate_obliquity_ecliptic_test},
             {NULL, calculate_local_sidereal_time_test},
             {NULL, calculate_true_anomaly_test},
             {NULL, calculate_position_in_space_test},
             {NULL, calculate_pertubations_moon_test},
             {NULL, calculate_pertubations_planets_test},
             {NULL, calculate_sind_cosd_atan2d_test},
             {NULL, NULL}};
