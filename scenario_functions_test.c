/**
 * Christian Pankratz 2020.
 */

#include "scenario_functions.h"

#include <acutest.h>
#include <math.h>

typedef struct {
  float hour;
  float minute;
  float second;
  int day;
  int month;
  int year;
  float azi;
  float alt;
} obsdata;

void scenario_calculate_azimuthal_coordinates_sun_test(void) {
  /*	Sun, lon 13.0 lat 52.0
  -----------------------------------------
          Date         |Horiz.coordinates |
                       |(Azimuth/Altitude)|
                       |                  |
  ---------------------|------------------|
    h  m  s            |    °       °     |
  00 00 00  28.02.2010 | 013.932 -45.354  |
  08 30 00  24.11.2012 | 145.768 +10.855  |
  17 00 00  21.08.2015 | 275.324 +11.254  |
  01 30 00  18.05.2018 | 034.848 -11.775  |
  10 00 00  11.02.2021 | 158.478 +21.787  |
  18 30 00  08.11.2023 | 278.968 -28.104  |
  03 00 00  05.08.2026 | 053.222 -05.449  |
  11 30 00  01.05.2029 | 190.000 +52.918  |
  20 00 00  26.01.2032 | 291.171 -38.766  |
  04 30 00  23.10.2034 | 092.735 -12.401  |
  13 00 00  19.07.2037 | 223.236 +52.617  |
  */

  obsdata data[] = {
      {00.0, 00.0, 00.0, /**/ 28, /***/ 2, 2010, 013.932, -45.354},
      {08.0, 30.0, 00.0, /**/ 24, /**/ 11, 2012, 145.768, +10.855},
      {17.0, 00.0, 00.0, /**/ 21, /***/ 8, 2015, 275.324, +11.254},
      {01.0, 30.0, 00.0, /**/ 18, /***/ 5, 2018, 034.848, -11.775},
      {10.0, 00.0, 00.0, /**/ 11, /***/ 2, 2021, 158.478, +21.787},
      {18.0, 30.0, 00.0, /***/ 8, /**/ 11, 2023, 278.968, -28.104},
      {03.0, 00.0, 00.0, /***/ 5, /***/ 8, 2026, 053.222, -05.449},
      {11.0, 30.0, 00.0, /***/ 1, /***/ 5, 2029, 190.000, +52.918},
      {20.0, 00.0, 00.0, /**/ 26, /***/ 1, 2032, 291.171, -38.766},
      {04.0, 30.0, 00.0, /**/ 23, /**/ 10, 2034, 092.735, -12.401},
      {13.0, 00.0, 00.0, /**/ 19, /***/ 7, 2037, 223.236, +52.617}};

  int num_data = 11;

  float azi, alt;
  float lon = 13.0;
  float lat = 52.0;

  int success = 1;

  for (int index = 0; index < num_data; index++) {
    TEST_CHECK(scenario_calculate_azimuthal_coordinates(
                   "sun", data[index].year, data[index].month, data[index].day,
                   data[index].hour + data[index].minute / 60.0 +
                       data[index].second / 3600.0,
                   lon, lat, &azi, &alt) != 0);

    if (fabsf(data[index].azi - azi) > 1.0 ||
        fabsf(data[index].alt - alt) > 1.0) {
      success = 0;
    }
  }

  TEST_CHECK(success == 1);
}

void scenario_calculate_azimuthal_coordinates_moon_test(void) {
  /*
  Moon, lon 13.0 lat 52.0
  -----------------------------------------
          Date         |Horiz.coordinates |
                       |(Azimuth/Altitude)|
                       |                  |
  ---------------------|------------------|
    h  m  s            |    °       °     |
  00 00 00  28.02.2010 | 208.240 +42.814  |
  08 30 00  24.11.2012 | 012.025 -28.646  |
  17 00 00  21.08.2015 | 194.158 +23.133  |
  01 30 00  18.05.2018 | 358.790 -18.515  |
  10 00 00  11.02.2021 | 162.825 +16.010  |
  18 30 00  08.11.2023 | 340.550 -31.791  |
  03 00 00  05.08.2026 | 156.510 +51.383  |
  11 30 00  01.05.2029 | 299.770 -51.076  |
  20 00 00  26.01.2032 | 122.480 +40.571  |
  04 30 00  23.10.2034 | 307.245 -36.467  |
  13 00 00  19.07.2037 | 118.184 +14.034  |
  */

  obsdata data[] = {
      {00.0, 00.0, 00.0, /**/ 28, /***/ 2, 2010, 208.240, +42.814},
      {08.0, 30.0, 00.0, /**/ 24, /**/ 11, 2012, 012.025, -28.646},
      {17.0, 00.0, 00.0, /**/ 21, /***/ 8, 2015, 194.158, +23.133},
      {01.0, 30.0, 00.0, /**/ 18, /***/ 5, 2018, 358.790, -18.515},
      {10.0, 00.0, 00.0, /**/ 11, /***/ 2, 2021, 162.825, +16.010},
      {18.0, 30.0, 00.0, /***/ 8, /**/ 11, 2023, 340.550, -31.791},
      {03.0, 00.0, 00.0, /***/ 5, /***/ 8, 2026, 156.510, +51.383},
      {11.0, 30.0, 00.0, /***/ 1, /***/ 5, 2029, 299.770, -51.076},
      {20.0, 00.0, 00.0, /**/ 26, /***/ 1, 2032, 122.480, +40.571},
      {04.0, 30.0, 00.0, /**/ 23, /**/ 10, 2034, 307.245, -36.467},
      {13.0, 00.0, 00.0, /**/ 19, /***/ 7, 2037, 118.184, +14.034}};

  int num_data = 11;

  float azi, alt;
  float lon = 13.0;
  float lat = 52.0;

  int success = 1;

  for (int index = 0; index < num_data; index++) {
    TEST_CHECK(scenario_calculate_azimuthal_coordinates(
                   "moon", data[index].year, data[index].month, data[index].day,
                   data[index].hour + data[index].minute / 60.0 +
                       data[index].second / 3600.0,
                   lon, lat, &azi, &alt) != 0);

    if (fabsf(data[index].azi - azi) > 1.0 ||
        fabsf(data[index].alt - alt) > 1.0) {
      success = 0;
    }
  }

  TEST_CHECK(success == 1);
}

TEST_LIST = {
    {"scenario sun", scenario_calculate_azimuthal_coordinates_sun_test},
    {"scenario moon", scenario_calculate_azimuthal_coordinates_moon_test},
    {NULL, NULL}};
