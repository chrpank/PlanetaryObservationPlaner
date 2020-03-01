/**
 * Christian Pankratz 2020.
 */

#include "date_manager.h"

#include <stdio.h>
#include <time.h>

int is_date_valid(const date date) {
  if (date.year <= 1900 || date.year >= 2100) {
    printf("error is_date_valid: the year is invalid\n");
    print_date(date);
    return 0;
  }

  if (date.month < 1 || date.month > 12) {
    printf("error is_date_valid: the month is invalid\n");
    print_date(date);
    return 0;
  }

  int max_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (is_leap_year(date)) {
    max_days[1] = 29;
  }

  if (date.day < 1 || date.day > max_days[date.month - 1]) {
    printf("error is_date_valid: the day is invalid\n");
    print_date(date);
    return 0;
  }

  if (date.ut < 0.0 || date.ut > 24.0) {
    printf("error is_date_valid: the ut is invalid\n");
    print_date(date);
    return 0;
  }

  return 1;
}

int set_date(const int year, const int month, const int day, const float ut,
             date *date) {
  (*date).year = year;
  (*date).month = month;
  (*date).day = day;
  (*date).ut = ut;

  if (is_date_valid((*date)) == 0) {
    printf("error set_date: the function is_date_valid failed\n");
    return 0;
  }

  return 1;
}

int step_forward(date *date, const float step) { return 0; }

int step_backward(date *date, const float step) { return 0; }

void print_date(const date date) { printf("| %d | %d | %d | "); }

int set_system_date(date *date, const int utdiff) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  (*date).year = tm.tm_year + 1900;
  (*date).month = tm.tm_mon + 1;
  (*date).day = tm.tm_mday;
  (*date).ut = tm.tm_hour + tm.tm_min / 60.0 + tm.tm_sec / 3600.0;

  if (step_backward(date, (float)utdiff) == 0) {
    printf("error set_system_date: the function step_backward failed\n");
    return 0;
  }

  if (is_date_valid((*date)) == 0) {
    printf("error set_system_date: the function is_date_valid failed\n");
    return 0;
  }

  return 1;
}

int is_leap_year(const date date) {
  if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
    return 1;
  }
  return 0;
}
