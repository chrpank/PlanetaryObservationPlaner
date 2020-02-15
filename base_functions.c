/**
 * Christian Pankratz 2020.
 */

#include "base_functions.h"

int calculate_time_scale(const int year, const int month, const int day,
                         const float ut, float *days) {

  if (year <= 1900 || year >= 2100) {
    return 0;
  }

  if (month < 1 || month > 12) {
    return 0;
  }

  if (day < 1 || day > 31) {
    return 0;
  }

  if (ut < 0 || ut > 24) {
    return 0;
  }

  *days = 367 * year - 7 * (year + (month + 9) / 12) / 4 + 275 * month / 9 +
          day - 730530;

  *days = *days + ut / 24.0;

  return 1;
}

int calculate_value_reduction(const float reduction_factor, float *value) {
  int reduction_successfull = 0;

  if (*value >= 0.0 && *value <= reduction_factor) {
    reduction_successfull = 1;
  }

  if (*value < 0.0) {
    for (int i = 0; i < 1000; i++) {
      *value = *value + reduction_factor;
      if (*value > 0) {
        reduction_successfull = 1;
        break;
      }
    }
  }

  if (*value > reduction_factor) {
    for (int i = 0; i < 1000; i++) {
      *value = *value - reduction_factor;
      if (*value < reduction_factor) {
        reduction_successfull = 1;
        break;
      }
    }
  }

  return reduction_successfull;
}

int calculate_orbital_elements(const char *celestial_object,    //
                               float *longitude_ascending_node, //
                               float *inclination_ecliptic,     //
                               float *argument_perihelion,      //
                               float *semi_major_axis,          //
                               float *eccentricity,             //
                               float *mean_anomaly,             //
                               const float days) {

  int case_found = 0;

  if (!strcmp(celestial_object, "sun")) {
    *longitude_ascending_node = 0.0;
    *inclination_ecliptic = 0.0;
    *argument_perihelion = 282.9404 + 4.70935E-5 * days;
    *semi_major_axis = 1.000000;
    *eccentricity = 0.016709 - 1.151E-9 * days;
    *mean_anomaly = 356.0470 + 0.9856002585 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "moon")) {
    *longitude_ascending_node = 125.1228 - 0.0529538083 * days;
    *inclination_ecliptic = 5.1454;
    *argument_perihelion = 318.0634 + 0.1643573223 * days;
    *semi_major_axis = 60.2666; // earth radii
    *eccentricity = 0.054900;
    *mean_anomaly = 115.3654 + 13.0649929509 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "mercury")) {
    *longitude_ascending_node = 48.3313 + 3.24587E-5 * days;
    *inclination_ecliptic = 7.0047 + 5.00E-8 * days;
    *argument_perihelion = 29.1241 + 1.01444E-5 * days;
    *semi_major_axis = 0.387098;
    *eccentricity = 0.205635 + 5.59E-10 * days;
    *mean_anomaly = 168.6562 + 4.0923344368 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "venus")) {
    *longitude_ascending_node = 76.6799 + 2.46590E-5 * days;
    *inclination_ecliptic = 3.3946 + 2.75E-8 * days;
    *argument_perihelion = 54.8910 + 1.38374E-5 * days;
    *semi_major_axis = 0.723330;
    *eccentricity = 0.006773 - 1.302E-9 * days;
    *mean_anomaly = 48.0052 + 1.6021302244 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "mars")) {
    *longitude_ascending_node = 49.5574 + 2.11081E-5 * days;
    *inclination_ecliptic = 1.8497 - 1.78E-8 * days;
    *argument_perihelion = 286.5016 + 2.92961E-5 * days;
    *semi_major_axis = 1.523688;
    *eccentricity = 0.093405 + 2.516E-9 * days;
    *mean_anomaly = 18.6021 + 0.5240207766 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "jupiter")) {
    *longitude_ascending_node = 100.4542 + 2.76854E-5 * days;
    *inclination_ecliptic = 1.3030 - 1.557E-7 * days;
    *argument_perihelion = 273.8777 + 1.64505E-5 * days;
    *semi_major_axis = 5.20256;
    *eccentricity = 0.048498 + 4.469E-9 * days;
    *mean_anomaly = 19.8950 + 0.0830853001 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "saturn")) {
    *longitude_ascending_node = 113.6634 + 2.38980E-5 * days;
    *inclination_ecliptic = 2.4886 - 1.081E-7 * days;
    *argument_perihelion = 339.3939 + 2.97661E-5 * days;
    *semi_major_axis = 9.55475;
    *eccentricity = 0.055546 - 9.499E-9 * days;
    *mean_anomaly = 316.9670 + 0.0334442282 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "uranus")) {
    *longitude_ascending_node = 74.0005 + 1.3978E-5 * days;
    *inclination_ecliptic = 0.7733 + 1.9E-8 * days;
    *argument_perihelion = 96.6612 + 3.0565E-5 * days;
    *semi_major_axis = 19.18171 - 1.55E-8 * days;
    *eccentricity = 0.047318 + 7.45E-9 * days;
    *mean_anomaly = 142.5905 + 0.011725806 * days;
    case_found = 1;
  }

  if (!strcmp(celestial_object, "neptune")) {
    *longitude_ascending_node = 131.7806 + 3.0173E-5 * days;
    *inclination_ecliptic = 1.7700 - 2.55E-7 * days;
    *argument_perihelion = 272.8461 - 6.027E-6 * days;
    *semi_major_axis = 30.05826 + 3.313E-8 * days;
    *eccentricity = 0.008606 + 2.15E-9 * days;
    *mean_anomaly = 260.2471 + 0.005995147 * days;
    case_found = 1;
  }

  calculate_value_reduction(360.0, longitude_ascending_node);
  calculate_value_reduction(360.0, inclination_ecliptic);
  calculate_value_reduction(360.0, argument_perihelion);
  calculate_value_reduction(360.0, mean_anomaly);

  return case_found;
}

int calculate_obliquity_ecliptic(float *obliquity_ecliptic, const float days) {
  *obliquity_ecliptic = 23.4393 - 3.563E-7 * days;
  return 1;
}

int calculate_local_sidereal_time(const int year,              //
                                  const int month,             //
                                  const int day,               //
                                  const float universal_time,  //
                                  const float local_longitude, //
                                  float *local_sidereal_time) {
  float dummy_value;
  float mean_anomaly_sun;
  float argument_perihelion_sun;
  float days;

  if (!calculate_time_scale(year, month, day, 0.0, &days)) {
    return 0;
  }

  if (!calculate_orbital_elements("sun",                    //
                                  &dummy_value,             //
                                  &dummy_value,             //
                                  &argument_perihelion_sun, //
                                  &dummy_value,             //
                                  &dummy_value,             //
                                  &mean_anomaly_sun,        //
                                  days)) {
    return 0;
  }

  float longitude_sun = mean_anomaly_sun + argument_perihelion_sun;
  float correction = (universal_time / 24.0) * 3.85 / 60.0;
  float greenwich_mean_sidereal_time_0 =
      longitude_sun / 15.0 + 12.0 + correction;
  float greenwich_mean_sidereal_time =
      greenwich_mean_sidereal_time_0 + universal_time;
  *local_sidereal_time = greenwich_mean_sidereal_time + local_longitude / 15.0;

  if (!calculate_value_reduction(24.0, local_sidereal_time)) {
    return 0;
  }

  return 1;
}

int calculate_true_anomaly(const float mean_anomaly,    //
                           const float eccentricity,    //
                           const float semi_major_axis, //
                           float *distance,             //
                           float *true_anomaly) {
  if (mean_anomaly > 360.0 || mean_anomaly < 0.0) {
    return 0;
  }
  if (eccentricity > 1.0 || eccentricity < 0.0) {
    return 0;
  }

  float radians_to_degree = (180.0 / M_PI);
  float degree_to_radians = 1.0 / radians_to_degree;
  float eccentric_anomaly_0 =
      mean_anomaly +
      eccentricity * radians_to_degree * sin(mean_anomaly * degree_to_radians) *
          (1.0 + eccentricity * cos(mean_anomaly * degree_to_radians));

  float found_solution = 0;
  float eccentric_anomaly = 0;
  for (int index = 0; index < 1000; index++) {
    eccentric_anomaly =
        eccentric_anomaly_0 -
        (eccentric_anomaly_0 -
         eccentricity * radians_to_degree *
             sin(eccentric_anomaly_0 * degree_to_radians) -
         mean_anomaly) /
            (1.0 - eccentricity * cos(eccentric_anomaly_0 * degree_to_radians));
    eccentric_anomaly_0 = eccentric_anomaly;
    if (fabs(eccentric_anomaly_0 - eccentric_anomaly) < 0.001) {
      found_solution = 1;
      break;
    }
  }

  float true_anomaly_x =
      semi_major_axis *
      (cos(eccentric_anomaly * degree_to_radians) - eccentricity);
  float true_anomaly_y =
      semi_major_axis * (sqrt(1.0 - eccentricity * eccentricity) *
                         sin(eccentric_anomaly * degree_to_radians));

  *true_anomaly = atan2(true_anomaly_y, true_anomaly_x);
  *true_anomaly *= radians_to_degree;
  if (!calculate_value_reduction(360.0, true_anomaly)) {
    return 0;
  }

  *distance =
      sqrt(true_anomaly_x * true_anomaly_x + true_anomaly_y * true_anomaly_y);

  return found_solution;
}

int calculate_position_in_space(const float distance,                 //
                                const float longitude_ascending_node, //
                                const float true_anomaly,             //
                                const float argument_perihelion,      //
                                const float inclination_ecliptic,     //
                                float *x_heliocentric,                //
                                float *y_heliocentric,                //
                                float *z_heliocentric,                //
                                float *ecliptic_longitude,            //
                                float *ecliptic_latitude) {
  float degree_to_radians = (M_PI / 180.0);

  *x_heliocentric = // geocentric for moon
      distance *
      (cos(longitude_ascending_node * degree_to_radians) *
           cos((true_anomaly + argument_perihelion) * degree_to_radians) -
       sin(longitude_ascending_node * degree_to_radians) *
           sin((true_anomaly + argument_perihelion) * degree_to_radians) *
           cos(inclination_ecliptic * degree_to_radians));
  *y_heliocentric = // geocentric for moon
      distance *
      (sin(longitude_ascending_node * degree_to_radians) *
           cos((true_anomaly + argument_perihelion) * degree_to_radians) +
       cos(longitude_ascending_node * degree_to_radians) *
           sin((true_anomaly + argument_perihelion) * degree_to_radians) *
           cos(inclination_ecliptic * degree_to_radians));
  *z_heliocentric = // geocentric for moon
      distance *
      (sin((true_anomaly + argument_perihelion) * degree_to_radians) *
       sin(inclination_ecliptic * degree_to_radians));

  *ecliptic_longitude = atan2(*y_heliocentric, *x_heliocentric);
  *ecliptic_latitude =
      atan2(*z_heliocentric, sqrt((*x_heliocentric) * (*x_heliocentric) +
                                  (*y_heliocentric) * (*y_heliocentric)));

  return 1;
}
