/**
 * Christian Pankratz 2020.
 */

#include "date_manager.h"
#include <acutest.h>

void test_template(void) { TEST_CHECK(1 == 1); }

void test_is_date_valid(void) {

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

void test_set_date(void) {
  date date;
  date.year = 0;
  date.month = 0;
  date.day = 0;
  date.ut = 0.0;

  TEST_CHECK(set_date(2000, 1, 1, 1.0, &date) != 0);
  TEST_CHECK(date.year != 0);
  TEST_CHECK(date.month != 0);
  TEST_CHECK(date.day != 0);
  TEST_CHECK(date.ut != 0.0);

  date.year = 0;
  date.month = 0;
  date.day = 0;
  date.ut = 0.0;

  TEST_CHECK(set_date(2500, 13, 33, 25.0, &date) == 0);
  TEST_CHECK(date.year != 0);
  TEST_CHECK(date.month != 0);
  TEST_CHECK(date.day != 0);
  TEST_CHECK(date.ut != 0.0);
}

void test_step_forward(void) {
  date date;

  /**
   * ut change
   */
  date.year = 2000;
  date.month = 1;
  date.day = 1;
  date.ut = 2.0;

  TEST_CHECK(step_forward(&date, 1.0) != 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 1);
  TEST_CHECK(date.day == 1);
  TEST_CHECK(date.ut == 3.0);

  /**
   * ut and day change
   */
  date.year = 2000;
  date.month = 1;
  date.day = 1;
  date.ut = 23.0;

  TEST_CHECK(step_forward(&date, 2.0) != 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 1);
  TEST_CHECK(date.day == 2);
  TEST_CHECK(date.ut == 1.0);

  /**
   * ut, day and month change
   */
  date.year = 2000;
  date.month = 1;
  date.day = 31;
  date.ut = 23.0;

  TEST_CHECK(step_forward(&date, 2.0) != 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 2);
  TEST_CHECK(date.day == 1);
  TEST_CHECK(date.ut == 1.0);

  /**
   * ut, day, month and year change
   */
  date.year = 2000;
  date.month = 12;
  date.day = 31;
  date.ut = 23.0;

  TEST_CHECK(step_forward(&date, 2.0) != 0);
  TEST_CHECK(date.year == 2001);
  TEST_CHECK(date.month == 1);
  TEST_CHECK(date.day == 1);
  TEST_CHECK(date.ut == 1.0);

  /**
   * case 24.0 ut
   */
  date.year = 2000;
  date.month = 12;
  date.day = 31;
  date.ut = 24.0;

  TEST_CHECK(step_forward(&date, 1.0) != 0);
  TEST_CHECK(date.year == 2001);
  TEST_CHECK(date.month == 1);
  TEST_CHECK(date.day == 1);
  TEST_CHECK(date.ut == 1.0);

  /**
   * leap year case 1
   */
  date.year = 2020;
  date.month = 2;
  date.day = 28;
  date.ut = 24.0;

  TEST_CHECK(step_forward(&date, 1.0) != 0);
  TEST_CHECK(date.year == 2020);
  TEST_CHECK(date.month == 2);
  TEST_CHECK(date.day == 29);
  TEST_CHECK(date.ut == 1.0);

  /**
   * leap year case 2
   */
  date.year = 2020;
  date.month = 2;
  date.day = 29;
  date.ut = 24.0;

  TEST_CHECK(step_forward(&date, 1.0) != 0);
  TEST_CHECK(date.year == 2020);
  TEST_CHECK(date.month == 3);
  TEST_CHECK(date.day == 1);
  TEST_CHECK(date.ut == 1.0);

  /**
   * invalid date
   */
  date.year = 2000;
  date.month = 12;
  date.day = 31;
  date.ut = 25.0;

  TEST_CHECK(step_forward(&date, 1.0) == 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 12);
  TEST_CHECK(date.day == 31);
  TEST_CHECK(date.ut == 25.0);
}

void test_step_backward(void) {
  date date;

  /**
   * ut change
   */
  date.year = 2000;
  date.month = 1;
  date.day = 1;
  date.ut = 2.0;

  TEST_CHECK(step_backward(&date, 1.0) != 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 1);
  TEST_CHECK(date.day == 1);
  TEST_CHECK(date.ut == 1.0);

  /**
   * ut and day change
   */
  date.year = 2000;
  date.month = 12;
  date.day = 1;
  date.ut = 1.0;

  TEST_CHECK(step_backward(&date, 2.0) != 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 11);
  TEST_CHECK(date.day == 30);
  TEST_CHECK(date.ut == 23.0);

  /**
   * ut, day and month change
   */
  date.year = 2000;
  date.month = 11;
  date.day = 30;
  date.ut = 1.0;

  TEST_CHECK(step_backward(&date, 2.0) != 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 11);
  TEST_CHECK(date.day == 29);
  TEST_CHECK(date.ut == 23.0);

  /**
   * ut, day, month and year change
   */
  date.year = 2000;
  date.month = 1;
  date.day = 1;
  date.ut = 1.0;

  TEST_CHECK(step_backward(&date, 2.0) != 0);
  TEST_CHECK(date.year == 1999);
  TEST_CHECK(date.month == 12);
  TEST_CHECK(date.day == 31);
  TEST_CHECK(date.ut == 23.0);

  /**
   * case 0.0 ut
   */
  date.year = 2000;
  date.month = 12;
  date.day = 31;
  date.ut = 0.0;

  TEST_CHECK(step_backward(&date, 1.0) != 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 12);
  TEST_CHECK(date.day == 30);
  TEST_CHECK(date.ut == 23.0);

  /**
   * leap year case 1
   */
  date.year = 2020;
  date.month = 2;
  date.day = 29;
  date.ut = 0.0;

  TEST_CHECK(step_backward(&date, 1.0) != 0);
  TEST_CHECK(date.year == 2020);
  TEST_CHECK(date.month == 2);
  TEST_CHECK(date.day == 28);
  TEST_CHECK(date.ut == 23.0);

  /**
   * invalid date
   */
  date.year = 2000;
  date.month = 12;
  date.day = 31;
  date.ut = 25.0;

  TEST_CHECK(step_backward(&date, 1.0) == 0);
  TEST_CHECK(date.year == 2000);
  TEST_CHECK(date.month == 12);
  TEST_CHECK(date.day == 31);
  TEST_CHECK(date.ut == 25.0);
}

TEST_LIST = {{"test_template.......", test_template},
             {"test_is_date_valid..", test_is_date_valid},
             {"test_set_date.......", test_set_date},
             {"test_step_forward...", test_step_forward},
             {"test_step_backward..", test_step_backward},
             {NULL, NULL}};
