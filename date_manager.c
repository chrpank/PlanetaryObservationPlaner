/**
 * Christian Pankratz 2020.
 */

#include "date_manager.h"

int is_date_valid(const date date) { return 1; }

int set_date(const int year, const int month, const int day, const float ut,
             date *date) {
  return 1;
}

int step_forward(date *date, const float step) { return 1; }

int step_backward(date *date, const float step) { return 1; }

int print_date(const date date) { return 1; }

int set_date_to_system_date(date *date) { return 1; }

int is_leap_year(const date date) { return 1; }
