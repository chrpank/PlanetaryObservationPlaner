/**
 * Christian Pankratz 2020.
 */

#include <math.h>
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
 * Calculate value reduction.
 * param[in/out] reduction_factor The reduction factor.
 * param[in/out] value The angle.
 * return not 0 if success, 0 otherwise.
 */
int calculate_value_reduction(const float reduction_factor, float *value);

/**
 * Calculate orbital elements.
 * param[in} celestial_object The celestial object.
 * param[in/out] longitude_ascending_node The longitude of the ascending node.
 * param[in/out] inclination_ecliptic The inclination to the ecliptic.
 * param[in/out] argument_perihelion The argument of perihelion.
 * param[in/out] semi_major_axis The semi-major axis.
 * param[in/out] eccentricity The eccentricity.
 * param[in/out] mean_anomaly The mean anomaly.
 * param[in} days The days.
 * return not 0 if success, 0 otherwise.
 */
int calculate_orbital_elements(const char *celestial_object,    //
                               float *longitude_ascending_node, //
                               float *inclination_ecliptic,     //
                               float *argument_perihelion,      //
                               float *semi_major_axis,          //
                               float *eccentricity,             //
                               float *mean_anomaly,             //
                               const float days);

/**
 * Calculate the obliquity of the ecliptic.
 * param[in/out] obliquity_ecliptic The obliquity of the ecliptic.
 * param[in} days The days.
 * return not 0 if success, 0 otherwise.
 */
int calculate_obliquity_ecliptic(float *obliquity_ecliptic, const float days);

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

/**
 * Calculate true anomaly and distance.
 * param[in} mean_anomaly The mean anomaly.
 * param[in} eccentricity The eccentricity.
 * param[in} semi_major_axis The semi major axis.
 * param[in/out] distance The distance.
 * param[in/out] true_anomaly The true anomaly.
 * return not 0 if success, 0 otherwise.
 */
int calculate_true_anomaly(const float mean_anomaly,    //
                           const float eccentricity,    //
                           const float semi_major_axis, //
                           float *distance,             //
                           float *true_anomaly);
