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

/**
 * Calculate true position in space.
 * param[in} distance The distance.
 * param[in} longitude_ascending_node The longitude of the ascending node.
 * param[in} true_anomaly The true anomaly.
 * param[in] argument_perihelion The argument of the perihelion.
 * param[in] inclination_ecliptic The inclination of the ecliptic.
 * param[in/out] x_heliocentric The x position heliocentric geocentric for moon
 * param[in/out] y_heliocentric The y position heliocentric geocentric for moon
 * param[in/out] z_heliocentric The z position heliocentric geocentric for moon
 * param[in/out] ecliptic_longitude The ecliptic longitude.
 * param[in/out] ecliptic_latitude The ecliptic latitude.
 * return not 0 if success, 0 otherwise.
 */
int calculate_position_in_space(const float distance,                 //
                                const float longitude_ascending_node, //
                                const float true_anomaly,             //
                                const float argument_perihelion,      //
                                const float inclination_ecliptic,     //
                                float *x_heliocentric,                //
                                float *y_heliocentric,                //
                                float *z_heliocentric,                //
                                float *ecliptic_longitude,            //
                                float *ecliptic_latitude);

/**
 * Calculate the pertubations of the moon.
 * param[in} Ms The Mean Anomaly of the Sun
 * param[in} Mm The Mean Anomaly of the Moon
 * param[in} Nm The Longitude of the Moon's node
 * param[in} ws The Argument of perihelion for the Sun
 * param[in} wm The Argument of perihelion for the Moon
 * param[in/out] lonecl The corrected ecliptic longitude.
 * param[in/out] latecl The corrected ecliptic latitude.
 * param[in/out} distance The corrected distance.
 * return not 0 if success, 0 otherwise.
 */
int calculate_pertubations_moon(const float Ms, //
                                const float Mm, //
                                const float Nm, //
                                const float ws, //
                                const float wm, //
                                float *lonecl,  //
                                float *latecl,  //
                                float *distance);

/**
 * Calculate the pertubations of jupiter saturn and uranus.
 * param[in} Mj The Mean anomaly of Jupiter.
 * param[in} Ms The Mean anomaly of Saturn.
 * param[in} Mu The Mean anomaly of Uranus.
 * param[in/out] lonecl_j The corrected longitude of jupiter.
 * param[in/out] latecl_j The corrected latitude of jupiter.
 * param[in/out] lonecl_s The corrected longitude of saturn.
 * param[in/out] latecl_s The corrected latitude of saturn.
 * param[in/out] lonecl_u The corrected longitude of uranus.
 * param[in/out] latecl_u The corrected latitude of uranus.
 * return not 0 if success, 0 otherwise.
 */
int calculate_pertubations_planets(const float Mj,  //
                                   const float Ms,  //
                                   const float Mu,  //
                                   float *lonecl_j, //
                                   float *latecl_j, //
                                   float *lonecl_s, //
                                   float *latecl_s, //
                                   float *lonecl_u, //
                                   float *latecl_u);
