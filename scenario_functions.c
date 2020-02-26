/**
 * Christian Pankratz 2020.
 */

#include <stdio.h>

#include "base_functions.h"

int scenario_calculate_azimuthal_coordinates(const char *object, const int year,
                                             const int month, const int day,
                                             const float ut, const float lat,
                                             float *az, float *alt) {
  int success = 1;

  float d;
  if (!calculate_time_scale(year, month, day, ut, &d)) {
    printf("the function calculate_time_scale failed");
    success = 0;
  }

  float N, i, w, a, e, M;
  if (!calculate_orbital_elements(object, &N, &i, &w, &a, &e, &M, d)) {
    printf("the function calculate_orbital_elements failed");
    success = 0;
  }

  float ecl;
  if (!calculate_obliquity_ecliptic(&ecl, d)) {
    printf("the function calculate_obliquity_ecliptic failed");
    success = 0;
  }

  float LST;
  if (!calculate_local_sidereal_time(year, month, day, ut, lat, &LST)) {
    printf("the function calculate_local_sidereal_time failed");
    success = 0;
  }

  float r, v;
  if (!calculate_true_anomaly(M, e, a, &r, &v)) {
    printf("the function calculate_true_anomaly failed");
    success = 0;
  }

  float xh, yh, zh, lonecl, latecl;
  if (!calculate_position_in_space(r, N, v, w, i, &xh, &yh, &zh, &lonecl,
                                   &latecl)) {
    printf("the function calculate_position_in_space failed");
    success = 0;
  }

  if (!strcmp(object, "moon")) {
    float Ns, is, ws, as, es, Ms;
    if (!calculate_orbital_elements("sun", &Ns, &is, &ws, &as, &es, &Ms, d)) {
      printf("the function calculate_orbital_elements failed");
      success = 0;
    }

    if (!calculate_pertubations_moon(Ms, M, N, ws, w, &lonecl, &latecl, &r)) {
      printf("the function calculate_pertubations_moon failed");
      success = 0;
    }
  }

  return success;
}
