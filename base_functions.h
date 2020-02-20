/**
 * Christian Pankratz 2020.
 */

#include <math.h>
#include <string.h>

#define deg2rad M_PI / 180.0
#define rad2deg 180.0 / M_PI

/**
 * calculate days from a date
 * param[in] year the year
 * param[in] month the month
 * param[in] day the day
 * param[in] ut the universal time
 * param[in/out] days the days
 * return not 0 if success, 0 otherwise
 */
int calculate_time_scale(const int y, const int month, const int day,
                         const float ut, float *d);

/**
 * calculate value reduction
 * param[in/out] factor the reduction factor
 * param[in/out] value the angle
 * return not 0 if success, 0 otherwise
 */
int calculate_value_reduction(const float factor, float *value);

/**
 * calculate orbital elements
 * param[in} o the celestial object
 * param[in/out] N the longitude of the ascending node
 * param[in/out] i the inclination to the ecliptic
 * param[in/out] w the argument of perihelion
 * param[in/out] a the semi-major axis
 * param[in/out] e the eccentricity
 * param[in/out] M the mean anomaly
 * param[in} d the days
 * return not 0 if success, 0 otherwise
 */
int calculate_orbital_elements(const char *o, float *N, float *i, float *w,
                               float *a, float *e, float *M, const float d);

/**
 * calculate the obliquity of the ecliptic.
 * param[in/out] ecl the obliquity of the ecliptic
 * param[in} d the days
 * return not 0 if success, 0 otherwise
 */
int calculate_obliquity_ecliptic(float *ecl, const float d);

/**
 * calculate the local sidereal time
 * param[in] y the year
 * param[in] m the month
 * param[in] d the day
 * param[in} UT the universal time
 * param[in} local_longitude the local longitude
 * param[in/out] LST the local sidereal time
 * return not 0 if success, 0 otherwise
 */
int calculate_local_sidereal_time(const int y, const int m, const int d,
                                  const float UT, const float local_longitude,
                                  float *LST);

/**
 * calculate true anomaly and distance
 * param[in} M the mean anomaly
 * param[in} e the eccentricity
 * param[in} a the semi major axis
 * param[in/out] r the distance
 * param[in/out] v the true anomaly
 * return not 0 if success, 0 otherwise
 */
int calculate_true_anomaly(const float M, const float e, const float a,
                           float *r, float *v);

/**
 * calculate true position in space
 * param[in} r the distance
 * param[in} N the longitude of the ascending node
 * param[in} v the true anomaly
 * param[in] w the argument of the perihelion
 * param[in] i the inclination of the ecliptic
 * param[in/out] xh the x position heliocentric, geocentric for moon
 * param[in/out] yh the y position heliocentric, geocentric for moon
 * param[in/out] zh the z position heliocentric, geocentric for moon
 * param[in/out] lonecl the ecliptic longitude
 * param[in/out] latecl the ecliptic latitude
 * return not 0 if success, 0 otherwise
 */
int calculate_position_in_space(const float r, const float N, const float v,
                                const float w, const float i, float *xh,
                                float *yh, float *zh, float *lonecl,
                                float *latecl);

/**
 * calculate the pertubations of the moon
 * param[in} Ms the mean anomaly of the sun
 * param[in} Mm the mean anomaly of the moon
 * param[in} Nm the longitude of the moons node
 * param[in} ws the argument of perihelion for the sun
 * param[in} wm the argument of perihelion for the moon
 * param[in/out] lonecl the corrected ecliptic longitude
 * param[in/out] latecl the corrected ecliptic latitude
 * param[in/out} r the corrected distance
 * return not 0 if success, 0 otherwise
 */
int calculate_pertubations_moon(const float Ms, const float Mm, const float Nm,
                                const float ws, const float wm, float *lonecl,
                                float *latecl, float *r);

/**
 * calculate the pertubations of jupiter saturn and uranus
 * param[in} Mj the mean anomaly of jupiter
 * param[in} Ms the mean anomaly of saturn
 * param[in} Mu the mean anomaly of uranus
 * param[in/out] lonecl_j the corrected longitude of jupiter
 * param[in/out] latecl_j the corrected latitude of jupiter
 * param[in/out] lonecl_s the corrected longitude of saturn
 * param[in/out] latecl_s the corrected latitude of saturn
 * param[in/out] lonecl_u the corrected longitude of uranus
 * param[in/out] latecl_u the corrected latitude of uranus
 * return not 0 if success, 0 otherwise
 */
int calculate_pertubations_planets(const float Mj, const float Ms,
                                   const float Mu, float *lonecl_j,
                                   float *latecl_j, float *lonecl_s,
                                   float *latecl_s, float *lonecl_u,
                                   float *latecl_u);

/**
 * calculate sine with degree argument
 * param[in} x the argument in degrees
 * return the sine value
 */
float sind(const float x);

/**
 * calculate cosine with degree argument
 * param[in} x the argument in degrees
 * return the cosine value
 */
float cosd(const float x);

/**
 * calculate atan2
 * param[in} y the argument
 * param[in} x the argument
 * return the atan2 in degrees
 */
float atan2d(const float y, const float x);
