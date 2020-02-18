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

int calculate_value_reduction(const float factor, float *value) {
  int reduction_successfull = 0;

  if (*value >= 0.0 && *value <= factor) {
    reduction_successfull = 1;
  }

  if (*value < 0.0) {
    for (int i = 0; i < 1000; i++) {
      *value = *value + factor;
      if (*value > 0) {
        reduction_successfull = 1;
        break;
      }
    }
  }

  if (*value > factor) {
    for (int i = 0; i < 1000; i++) {
      *value = *value - factor;
      if (*value < factor) {
        reduction_successfull = 1;
        break;
      }
    }
  }

  return reduction_successfull;
}

int calculate_orbital_elements(const char *o, float *N, float *i, float *w,
                               float *a, float *e, float *M, const float d) {

  int case_found = 0;

  if (!strcmp(o, "sun")) {
    *N = 0.0;
    *i = 0.0;
    *w = 282.9404 + 4.70935E-5 * d;
    *a = 1.000000;
    *e = 0.016709 - 1.151E-9 * d;
    *M = 356.0470 + 0.9856002585 * d;
    case_found = 1;
  }

  if (!strcmp(o, "moon")) {
    *N = 125.1228 - 0.0529538083 * d;
    *i = 5.1454;
    *w = 318.0634 + 0.1643573223 * d;
    *a = 60.2666; // earth radii
    *e = 0.054900;
    *M = 115.3654 + 13.0649929509 * d;
    case_found = 1;
  }

  if (!strcmp(o, "mercury")) {
    *N = 48.3313 + 3.24587E-5 * d;
    *i = 7.0047 + 5.00E-8 * d;
    *w = 29.1241 + 1.01444E-5 * d;
    *a = 0.387098;
    *e = 0.205635 + 5.59E-10 * d;
    *M = 168.6562 + 4.0923344368 * d;
    case_found = 1;
  }

  if (!strcmp(o, "venus")) {
    *N = 76.6799 + 2.46590E-5 * d;
    *i = 3.3946 + 2.75E-8 * d;
    *w = 54.8910 + 1.38374E-5 * d;
    *a = 0.723330;
    *e = 0.006773 - 1.302E-9 * d;
    *M = 48.0052 + 1.6021302244 * d;
    case_found = 1;
  }

  if (!strcmp(o, "mars")) {
    *N = 49.5574 + 2.11081E-5 * d;
    *i = 1.8497 - 1.78E-8 * d;
    *w = 286.5016 + 2.92961E-5 * d;
    *a = 1.523688;
    *e = 0.093405 + 2.516E-9 * d;
    *M = 18.6021 + 0.5240207766 * d;
    case_found = 1;
  }

  if (!strcmp(o, "jupiter")) {
    *N = 100.4542 + 2.76854E-5 * d;
    *i = 1.3030 - 1.557E-7 * d;
    *w = 273.8777 + 1.64505E-5 * d;
    *a = 5.20256;
    *e = 0.048498 + 4.469E-9 * d;
    *M = 19.8950 + 0.0830853001 * d;
    case_found = 1;
  }

  if (!strcmp(o, "saturn")) {
    *N = 113.6634 + 2.38980E-5 * d;
    *i = 2.4886 - 1.081E-7 * d;
    *w = 339.3939 + 2.97661E-5 * d;
    *a = 9.55475;
    *e = 0.055546 - 9.499E-9 * d;
    *M = 316.9670 + 0.0334442282 * d;
    case_found = 1;
  }

  if (!strcmp(o, "uranus")) {
    *N = 74.0005 + 1.3978E-5 * d;
    *i = 0.7733 + 1.9E-8 * d;
    *w = 96.6612 + 3.0565E-5 * d;
    *a = 19.18171 - 1.55E-8 * d;
    *e = 0.047318 + 7.45E-9 * d;
    *M = 142.5905 + 0.011725806 * d;
    case_found = 1;
  }

  if (!strcmp(o, "neptune")) {
    *N = 131.7806 + 3.0173E-5 * d;
    *i = 1.7700 - 2.55E-7 * d;
    *w = 272.8461 - 6.027E-6 * d;
    *a = 30.05826 + 3.313E-8 * d;
    *e = 0.008606 + 2.15E-9 * d;
    *M = 260.2471 + 0.005995147 * d;
    case_found = 1;
  }

  calculate_value_reduction(360.0, N);
  calculate_value_reduction(360.0, i);
  calculate_value_reduction(360.0, w);
  calculate_value_reduction(360.0, M);

  return case_found;
}

int calculate_obliquity_ecliptic(float *ecl, const float d) {
  *ecl = 23.4393 - 3.563E-7 * d;
  return 1;
}

int calculate_local_sidereal_time(const int y, const int m, const int d,
                                  const float UT, const float local_longitude,
                                  float *LST) {
  float dummy;
  float M;
  float w;
  float days;

  if (!calculate_time_scale(y, m, d, 0.0, &days)) {
    return 0;
  }

  if (!calculate_orbital_elements("sun", &dummy, &dummy, &w, &dummy, &dummy, &M,
                                  days)) {
    return 0;
  }

  float Ls = M + w; // mean longitude of the sun

  float correction = (UT / 24.0) * 3.85 / 60.0;

  float GMST0 = Ls / 15.0 + 12.0 + correction;
  float GMST = GMST0 + UT;
  *LST = GMST + local_longitude / 15.0;

  if (!calculate_value_reduction(24.0, LST)) {
    return 0;
  }

  return 1;
}

int calculate_true_anomaly(const float M, const float e, const float a,
                           float *r, float *v) {
  if (M > 360.0 || M < 0.0) {
    return 0;
  }

  if (e > 1.0 || e < 0.0) {
    return 0;
  }

  float rad2deg = (180.0 / M_PI);
  float deg2rad = 1.0 / rad2deg;
  float E0 = M + e * rad2deg * sin(M * deg2rad) * (1.0 + e * cos(M * deg2rad));

  float found_solution = 0;

  float E = 0;
  for (int index = 0; index < 1000; index++) {
    E = E0 - (E0 - e * rad2deg * sin(E0 * deg2rad) - M) /
                 (1.0 - e * cos(E0 * deg2rad));
    E0 = E;
    if (fabs(E0 - E) < 0.001) {
      found_solution = 1;
      break;
    }
  }

  float xv = a * (cos(E * deg2rad) - e);
  float yv = a * (sqrt(1.0 - e * e) * sin(E * deg2rad));

  *v = rad2deg * atan2(yv, xv);

  if (!calculate_value_reduction(360.0, v)) {
    return 0;
  }

  *r = sqrt(xv * xv + yv * yv);

  return found_solution;
}

int calculate_position_in_space(const float r, const float N, const float v,
                                const float w, const float i, float *xh,
                                float *yh, float *zh, float *lonecl,
                                float *latecl) {
  float deg2rad = (M_PI / 180.0);

  // geocentric for moon
  *xh = r * (cos(N * deg2rad) * cos((v + w) * deg2rad) -
             sin(N * deg2rad) * sin((v + w) * deg2rad) * cos(i * deg2rad));

  // geocentric for moon
  *yh = r * (sin(N * deg2rad) * cos((v + w) * deg2rad) +
             cos(N * deg2rad) * sin((v + w) * deg2rad) * cos(i * deg2rad));

  // geocentric for moon
  *zh = r * (sin((v + w) * deg2rad) * sin(i * deg2rad));

  *lonecl = atan2(*yh, *xh);
  *latecl = atan2(*zh, sqrt((*xh) * (*xh) + (*yh) * (*yh)));

  return 1;
}

int calculate_pertubations_moon(const float Ms, const float Mm, const float Nm,
                                const float ws, const float wm, float *lonecl,
                                float *latecl, float *r) {
  float deg2rad = (M_PI / 180.0);

  float Ls = Ms + ws;      // mean Longitude of the sun  (Ns=0)
  float Lm = Mm + wm + Nm; // mean longitude of the moon
  float D = Lm - Ls;       // mean elongation of the moon
  float F = Lm - Nm;       // argument of latitude for the moon

  *lonecl += -1.2740 * sin(deg2rad * (Mm - 2 * D))      //
             + 0.658 * sin(deg2rad * (2 * D))           //
             - 0.186 * sin(deg2rad * (Ms))              //
             - 0.059 * sin(deg2rad * (2 * Mm - 2 * D))  //
             - 0.057 * sin(deg2rad * (Mm - 2 * D + Ms)) //
             + 0.053 * sin(deg2rad * (Mm + 2 * D))      //
             + 0.046 * sin(deg2rad * (2 * D - Ms))      //
             + 0.041 * sin(deg2rad * (Mm - Ms))         //
             - 0.035 * sin(deg2rad * (D))               //
             - 0.031 * sin(deg2rad * (Mm + Ms))         //
             - 0.015 * sin(deg2rad * (2 * F - 2 * D))   //
             + 0.011 * sin(deg2rad * (Mm - 4 * D));

  *latecl += -0.1730 * sin(deg2rad * (F - 2 * D))      //
             - 0.055 * sin(deg2rad * (Mm - F - 2 * D)) //
             - 0.046 * sin(deg2rad * (Mm + F - 2 * D)) //
             + 0.033 * sin(deg2rad * (F + 2 * D))      //
             + 0.017 * sin(deg2rad * (2 * Mm + F));

  *r += -0.580 * cos(deg2rad * (Mm - 2 * D)) //
        - 0.46 * cos(deg2rad * (2 * D));     //

  return 1;
}

int calculate_pertubations_planets(const float Mj, const float Ms,
                                   const float Mu, float *lonecl_j,
                                   float *latecl_j, float *lonecl_s,
                                   float *latecl_s, float *lonecl_u,
                                   float *latecl_u) {
  float deg2rad = (M_PI / 180.0);

  *lonecl_j += -0.3320 * sin(deg2rad * (2 * Mj - 5 * Ms - 67.6)) //
               - 0.056 * sin(deg2rad * (2 * Mj - 2 * Ms + 21))   //
               + 0.042 * sin(deg2rad * (3 * Mj - 5 * Ms + 21))   //
               - 0.036 * sin(deg2rad * (Mj - 2 * Ms))            //
               + 0.022 * cos(deg2rad * (Mj - Ms))                //
               + 0.023 * sin(deg2rad * (2 * Mj - 3 * Ms + 52))   //
               - 0.016 * sin(deg2rad * (Mj - 5 * Ms - 69));

  *lonecl_s += +0.8120 * sin(deg2rad * (2 * Mj - 5 * Ms - 67.6)) //
               - 0.229 * cos(deg2rad * (2 * Mj - 4 * Ms - 2))    //
               + 0.119 * sin(deg2rad * (Mj - 2 * Ms - 3))        //
               + 0.046 * sin(deg2rad * (2 * Mj - 6 * Ms - 69))   //
               + 0.014 * sin(deg2rad * (Mj - 3 * Ms + 32));

  *latecl_s += -0.0200 * cos(deg2rad * (2 * Mj - 4 * Ms - 2)) //
               + 0.018 * sin(deg2rad * (2 * Mj - 6 * Ms - 49));

  *lonecl_u += +0.0400 * sin(deg2rad * (Ms - 2 * Mu + 6))  //
               + 0.035 * sin(deg2rad * (Ms - 3 * Mu + 33)) //
               - 0.015 * sin(deg2rad * (Mj - Mu + 20));

  return 1;
}
