/**
 * Christian Pankratz 2020.
 */

#include "base_functions.h"

int calculate_time_scale(int year, int month, int day, float ut, float *days) {

  if (year <= 1900 || year >= 2100) {
    *days = 0;
    return 0;
  }

  if (month < 1 || month > 12) {
    *days = 0;
    return 0;
  }

  if (day < 1 || day > 31) {
    *days = 0;
    return 0;
  }

  if (ut < 0 || ut > 24) {
    *days = 0;
    return 0;
  }

  *days = 367 * year - 7 * (year + (month + 9) / 12) / 4 + 275 * month / 9 +
          day - 730530;

  *days = *days + ut / 24.0;

  return 1;
}
