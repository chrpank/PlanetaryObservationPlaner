/**
 * Christian Pankratz 2020.
 */

#include "base_functions.h"
#include <acutest.h>

void calculate_time_scale_day_zero_case_1(void) {
  float *days;

  calculate_time_scale(0, 0, 0, 0, days);
}

void calculate_time_scale_day_zero_case_2(void) {
  float *days;

  calculate_time_scale(0, 0, 0, 0, days);
}

void calculate_time_scale_false_input_year(void) {
  float *days;

  calculate_time_scale(0, 0, 0, 0, days);
}

void calculate_time_scale_false_input_month(void) {
  float *days;

  calculate_time_scale(0, 0, 0, 0, days);
}

void calculate_time_scale_false_input_day(void) {
  float *days;

  calculate_time_scale(0, 0, 0, 0, days);
}

void calculate_time_scale_false_input_ut(void) {
  float *days;

  calculate_time_scale(0, 0, 0, 0, days);
}

TEST_LIST = {{NULL, calculate_time_scale_day_zero_case_1},
             {NULL, calculate_time_scale_day_zero_case_2},
             {NULL, calculate_time_scale_false_input_year},
             {NULL, calculate_time_scale_false_input_month},
             {NULL, calculate_time_scale_false_input_day},
             {NULL, calculate_time_scale_false_input_ut},
             {NULL, NULL}};
