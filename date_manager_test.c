/**
 * Christian Pankratz 2020.
 */

#include "date_manager.h"
#include <acutest.h>

void template_test(void) { TEST_CHECK(1 == 1); }

void is_date_valid_test(void) {

  int valid_year = 2020;
  int valid_month = 3;
  int valid_day = 14;
  int valid_ut = 11.0;

  int invalid_year_1 = 1900;
  int invalid_year_2 = 2100;

  int invalid_day_1 = 0;
  int invalid_day_2 = 32;

  int invalid_month_1 = 0;
  int invalid_month_2 = 13;

  int invalid_ut_1 = -1.0;
  int invalid_ut_2 = 25.0;

  date date;

  // check valid date
  date.day = valid_day;
  date.month = valid_month;
  date.year = valid_year;
  date.ut = valid_ut;
  TEST_CHECK(is_date_valid(date) != 0);

  // check invalid year 1
  date.day = valid_day;
  date.month = valid_month;
  date.year = invalid_year_1;
  date.ut = valid_ut;
  TEST_CHECK(is_date_valid(date) == 0);

  // check invalid year 2
  date.day = valid_day;
  date.month = valid_month;
  date.year = invalid_year_2;
  date.ut = valid_ut;
  TEST_CHECK(is_date_valid(date) == 0);

  // check invalid month 1
  date.day = valid_day;
  date.month = invalid_month_1;
  date.year = valid_year;
  date.ut = valid_ut;
  TEST_CHECK(is_date_valid(date) == 0);

  // check invalid month 2
  date.day = valid_day;
  date.month = invalid_month_2;
  date.year = valid_year;
  date.ut = valid_ut;
  TEST_CHECK(is_date_valid(date) == 0);

  // check invalid day 1
  date.day = invalid_day_1;
  date.month = valid_month;
  date.year = valid_year;
  date.ut = valid_ut;
  TEST_CHECK(is_date_valid(date) == 0);

  // check invalid day 2
  date.day = invalid_day_2;
  date.month = valid_month;
  date.year = valid_year;
  date.ut = valid_ut;
  TEST_CHECK(is_date_valid(date) == 0);

  // check invalid ut 1
  date.day = valid_day;
  date.month = valid_month;
  date.year = valid_year;
  date.ut = invalid_ut_1;
  TEST_CHECK(is_date_valid(date) == 0);

  // check invalid ut 2
  date.day = valid_day;
  date.month = valid_month;
  date.year = valid_year;
  date.ut = invalid_ut_2;
  TEST_CHECK(is_date_valid(date) == 0);
}

TEST_LIST = {{NULL, template_test}, {NULL, is_date_valid_test}, {NULL, NULL}};
