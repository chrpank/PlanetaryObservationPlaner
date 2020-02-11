/**
 * Christian Pankratz 2020.
 */

#include <string.h>

/**
 * Calculate days from a date.
 * param[in] year The year.
 * param[in] month The month.
 * param[in] day The day.
 * param[in] ut The universal time.
 * param[in/out] days The days.
 * return not 0 if success, 0 otherwise.
 */
int calculate_time_scale(const int year, const int month, const int day,
                         const float ut, float *days);

/**
 * Calculate angle reduction.
 * param[in/out] angle The angle.
 * return not 0 if success, 0 otherwise.
 */
int calculate_angle_reduction(float *angle);

/**
 * Calculate orbital elements.
 * param[in} o The celestial object.
 * param[in/out] N The longitude of the ascending node.
 * param[in/out] i The inclination to the ecliptic.
 * param[in/out] w The argument of perihelion.
 * param[in/out] a The semi-major axis.
 * param[in/out] e The eccentricity.
 * param[in/out] M The mean anomaly.
 * param[in} d The days.
 * return not 0 if success, 0 otherwise.
 */
int calculate_orbital_elements(const char *o, float *N, float *i, float *w,
                               float *a, float *e, float *M, const float d);

/**
 * Calculate the obliquity of the ecliptic.
 * param[in/out] ecl The obliquity of the ecliptic.
 * param[in} d The days.
 * return not 0 if success, 0 otherwise.
 */
int calculate_obliquity_ecliptic(float *ecl, const float d);

/**
 * Calculate the local sidereal time.
 * param[in] year The year.
 * param[in] month The month.
 * param[in] day The day.
 * param[in} universal_time The universal time.
 * param[in} local_longitude The local longitude.
 * param[in/out] local_sidereal_time The local sidereal time.
 * return not 0 if success, 0 otherwise.
 */
int calculate_local_sidereal_time(const int year,              //
                                  const int month,             //
                                  const int day,               //
                                  const float universal_time,  //
                                  const float local_longitude, //
                                  float *local_sidereal_time);
