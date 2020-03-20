/**
 * Christian Pankratz 2020.
 */

#include "date_manager.h"
#include "base_functions.h"

#include <math.h>
#include <stdio.h>
#include <time.h>

static const int DEBUG_MODE_DATE_MANAGER = 0;

int is_date_valid(const date date) {
  if (date.year <= 1900 || date.year >= 2100) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error is_date_valid: the year is invalid\n");
      print_date(date);
    }
    return 0;
  }

  if (date.month < 1 || date.month > 12) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error is_date_valid: the month is invalid\n");
      print_date(date);
    }
    return 0;
  }

  int max_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (is_leap_year(date)) {
    max_days[1] = 29;
  }

  if (date.day < 1 || date.day > max_days[date.month - 1]) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error is_date_valid: the day is invalid\n");
      print_date(date);
    }
    return 0;
  }

  if (date.ut < 0.0 || date.ut > 24.0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error is_date_valid: the ut is invalid\n");
      print_date(date);
    }
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
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error set_date: the function is_date_valid failed\n");
    }
    return 0;
  }

  return 1;
}

int step_forward(date *date, const float step) {
  if (step > 12.0 || step < 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error step_forward: timestep is not in the range 0-12 hours\n");
    }
    return 0;
  }

  if (is_date_valid(*date) == 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error step_forward: date invalid\n");
    }
    return 0;
  }

  float ut = (*date).ut;
  ut += step;
  if (ut <= 24.0) {
    (*date).ut = ut;
    if (is_date_valid(*date) == 0) {
      if (DEBUG_MODE_DATE_MANAGER) {
        printf("error step_forward: date invalid\n");
      }
      return 0;
    }
    return 1;
  }

  ut += 24.0;
  calculate_value_reduction(24.0, &ut);
  (*date).ut = ut;

  int day = (*date).day;
  day++;

  int max_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (is_leap_year(*date)) {
    max_days[1] = 29;
  }

  if (day <= max_days[(*date).month - 1]) {
    (*date).day = day;
    if (is_date_valid(*date) == 0) {
      if (DEBUG_MODE_DATE_MANAGER) {
        printf("error step_forward: date invalid\n");
      }
      return 0;
    }
    return 1;
  }

  (*date).day = 1;

  int month = (*date).month;
  month++;
  if (month < 12) {
    (*date).month = month;
    if (is_date_valid(*date) == 0) {
      if (DEBUG_MODE_DATE_MANAGER) {
        printf("error step_forward: date invalid\n");
      }
      return 0;
    }
    return 1;
  }

  (*date).month = 1;
  (*date).year++;

  if (is_date_valid(*date) == 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error step_forward: date invalid\n");
    }
    return 0;
  }

  return 1;
}

int step_backward(date *date, const float step) {
  if (step > 12.0 || step < 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error step_backward: timestep is not in the range 0-12 hours\n");
    }
    return 0;
  }

  if (is_date_valid(*date) == 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error step_backward: date invalid\n");
    }
    return 0;
  }

  float ut = (*date).ut;
  ut -= step;
  if (ut >= 0.0) {
    (*date).ut = ut;
    if (is_date_valid(*date) == 0) {
      if (DEBUG_MODE_DATE_MANAGER) {
        printf("error step_backward: date invalid\n");
      }
      return 0;
    }
    return 1;
  }

  ut += 24;
  (*date).ut = ut;

  int day = (*date).day;
  day--;

  int max_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (is_leap_year(*date)) {
    max_days[1] = 29;
  }

  if (day > 0) {
    (*date).day = day;
    if (is_date_valid(*date) == 0) {
      if (DEBUG_MODE_DATE_MANAGER) {
        printf("error step_backward: date invalid\n");
      }
      return 0;
    }
    return 1;
  }

  int month = (*date).month;
  month--;
  if (month > 0) {
    (*date).month = month;
    (*date).day = max_days[month - 1];
    if (is_date_valid(*date) == 0) {
      if (DEBUG_MODE_DATE_MANAGER) {
        printf("error step_backward: date invalid\n");
      }
      return 0;
    }
    return 1;
  }

  (*date).day = 31;
  (*date).month = 12;
  (*date).year--;

  if (is_date_valid(*date) == 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error step_backward: date invalid\n");
    }
    return 0;
  }

  return 1;
}

void print_date(const date date) {
  int hour = (int)floor(date.ut);
  int min = (int)floor((date.ut - hour) * 60.0);

  printf("%2.0f.%2.0f.%2.0f  %2.0f:%2.0f \n", (float)date.day,
         (float)date.month, (float)date.year, (float)hour, (float)min);
}

int set_system_date(date *date, const int utdiff) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  (*date).year = tm.tm_year + 1900;
  (*date).month = tm.tm_mon + 1;
  (*date).day = tm.tm_mday;
  (*date).ut = tm.tm_hour + tm.tm_min / 60.0 + tm.tm_sec / 3600.0;

  if (step_backward(date, (float)utdiff) == 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error set_system_date: the function step_backward failed\n");
    }
    return 0;
  }

  if (is_date_valid((*date)) == 0) {
    if (DEBUG_MODE_DATE_MANAGER) {
      printf("error set_system_date: the function is_date_valid failed\n");
    }
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
