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

  /****************************************************************************/
  // calculate_time_scale

  float d;
  if (!calculate_time_scale(year, month, day, ut, &d)) {
    printf("the function calculate_time_scale failed");
    success = 0;
  }

  /****************************************************************************/
  // calculate_orbital_elements

  float N, i, w, a, e, M;
  if (!calculate_orbital_elements(object, &N, &i, &w, &a, &e, &M, d)) {
    printf("the function calculate_orbital_elements failed");
    success = 0;
  }

  /****************************************************************************/
  // calculate_obliquity_ecliptic

  float ecl;
  if (!calculate_obliquity_ecliptic(&ecl, d)) {
    printf("the function calculate_obliquity_ecliptic failed");
    success = 0;
  }

  /****************************************************************************/
  // calculate_local_sidereal_time

  float LST;
  if (!calculate_local_sidereal_time(year, month, day, ut, lat, &LST)) {
    printf("the function calculate_local_sidereal_time failed");
    success = 0;
  }

  /****************************************************************************/
  // calculate_true_anomaly

  float r, v;
  if (!calculate_true_anomaly(M, e, a, &r, &v)) {
    printf("the function calculate_true_anomaly failed");
    success = 0;
  }

  /****************************************************************************/
  // calculate_position_in_space

  float xh, yh, zh, lonecl, latecl;
  if (!calculate_position_in_space(r, N, v, w, i, &xh, &yh, &zh, &lonecl,
                                   &latecl)) {
    printf("the function calculate_position_in_space failed");
    success = 0;
  }

  /****************************************************************************/
  // calculate_pertubations_moon

  if (!strcmp(object, "moon")) {
    float N_sun, i_sun, w_sun, a_sun, e_sun, M_sun;
    if (!calculate_orbital_elements("sun", &N_sun, &i_sun, &w_sun, &a_sun,
                                    &e_sun, &M_sun, d)) {
      printf("the function calculate_orbital_elements failed");
      success = 0;
    }
    if (!calculate_pertubations_moon(M_sun, M, N, w_sun, w, &lonecl, &latecl,
                                     &r)) {
      printf("the function calculate_pertubations_moon failed");
      success = 0;
    }
  }

  /****************************************************************************/
  // calculate_pertubations_planets

  if (!strcmp(object, "jupiter")) {
    float N_sat, i_sat, w_sat, a_sat, e_sat, M_sat, dummy;
    if (!calculate_orbital_elements("saturn", &N_sat, &i_sat, &w_sat, &a_sat,
                                    &e_sat, &M_sat, d)) {
      printf("the function calculate_orbital_elements failed");
      success = 0;
    }

    if (!calculate_pertubations_planets(M, M_sat, dummy, &lonecl, &latecl,
                                        &dummy, &dummy, &dummy, &dummy)) {
      printf("the function calculate_pertubations_planets failed");
      success = 0;
    }
  }

  if (!strcmp(object, "saturn")) {
    float N_jup, i_jup, w_jup, a_jup, e_jup, M_jup, dummy;
    if (!calculate_orbital_elements("jupiter", &N_jup, &i_jup, &w_jup, &a_jup,
                                    &e_jup, &M_jup, d)) {
      printf("the function calculate_orbital_elements failed");
      success = 0;
    }

    if (!calculate_pertubations_planets(M_jup, M, dummy, &dummy, &dummy,
                                        &lonecl, &latecl, &dummy, &dummy)) {
      printf("the function calculate_pertubations_planets failed");
      success = 0;
    }
  }

  if (!strcmp(object, "uranus")) {
    float N_sat, i_sat, w_sat, a_sat, e_sat, M_sat, dummy;
    if (!calculate_orbital_elements("saturn", &N_sat, &i_sat, &w_sat, &a_sat,
                                    &e_sat, &M_sat, d)) {
      printf("the function calculate_orbital_elements failed");
      success = 0;
    }

    if (!calculate_pertubations_planets(dummy, M_sat, M, &dummy, &dummy, &dummy,
                                        &dummy, &lonecl, &latecl)) {
      printf("the function calculate_pertubations_planets failed");
      success = 0;
    }
  }

  /****************************************************************************/
  // calculate_geocentric_coordinates_moon

  /****************************************************************************/
  // calculate_geocentric_coordinates_planet

  /****************************************************************************/
  // calculate_equatorial_coordinates

  /****************************************************************************/
  // calculate_azimuthal_coordinates

  return success;
}
