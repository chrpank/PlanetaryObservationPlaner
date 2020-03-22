/**
 * Christian Pankratz 2020.
 */

#include <math.h>
#include <stdio.h>

#include "configuration_manager.h"

const char *CONFIG_FILE_PATH = "pop.cfg";

int create_configuration_file() {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "w");

  if (file == NULL) {
    printf("error in create_configuration_file: file could not be created\n");
    return 0;
  }

  fprintf(file, "lat=+050.000,lon=+010.000,utd=00");
  fclose(file);

  return 1;
}

/**
 * helper function to check number in char
 */
int is_number_char(const char number) {
  char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int numbers_count = 10;

  int number_matched = 0;

  for (int i = 0; i < numbers_count; i++) {
    if (number == numbers[i]) {
      number_matched = 1;
      break;
    }
  }

  return number_matched;
}

int validate_configuration_file(int *file_is_valid) {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "r");

  if (file == NULL) {
    printf("error validate_configuration_file: cannot open file\n");
    return 0;
  }

  char buffer[100];
  fscanf(file, "%[^\n]", buffer);
  fclose(file);

  int _file_is_valid = 1;

  /******************************
   ******* check latitude *******
   ******************************/

  /**
   * check latitude praefix
   */
  if (buffer[0] != 'l' || //
      buffer[1] != 'a' || //
      buffer[2] != 't' || //
      buffer[3] != '=') {
    _file_is_valid = 0;
  }

  /**
   * check latitude sign
   */
  if (buffer[4] != '+' && //
      buffer[4] != '-') {
    _file_is_valid = 0;
  }

  /**
   * check latitute 10^2, 10^1, 10^0
   */
  if (is_number_char(buffer[5]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[6]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[7]) == 0) {
    _file_is_valid = 0;
  }

  /**
   * check latitude point
   */
  if (buffer[8] != '.') {
    _file_is_valid = 0;
  }

  /**
   * check latitute 10^-1, 10^-2, 10^-3
   */
  if (is_number_char(buffer[9]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[10]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[11]) == 0) {
    _file_is_valid = 0;
  }

  /**
   * check latitude comma
   */
  if (buffer[12] != ',') {
    _file_is_valid = 0;
  }

  /*******************************
   ******* check longitude *******
   *******************************/

  /**
   * check longitude praefix
   */
  if (buffer[13] != 'l' || //
      buffer[14] != 'o' || //
      buffer[15] != 'n' || //
      buffer[16] != '=') {
    _file_is_valid = 0;
  }

  /**
   * check longitude sign
   */
  if (buffer[17] != '+' && //
      buffer[17] != '-') {
    _file_is_valid = 0;
  }

  /**
   * check longitude 10^2, 10^1, 10^0
   */
  if (is_number_char(buffer[18]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[19]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[20]) == 0) {
    _file_is_valid = 0;
  }

  /**
   * check longitude point
   */
  if (buffer[21] != '.') {
    _file_is_valid = 0;
  }

  /**
   * check longitude 10^-1, 10^-2, 10^-3
   */
  if (is_number_char(buffer[22]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[23]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[24]) == 0) {
    _file_is_valid = 0;
  }

  /**
   * check longitude comma
   */
  if (buffer[25] != ',') {
    _file_is_valid = 0;
  }

  /*************************
   ******* check utd *******
   *************************/

  if (buffer[26] != 'u' || //
      buffer[27] != 't' || //
      buffer[28] != 'd' || //
      buffer[29] != '=') {
    _file_is_valid = 0;
  }

  /**
   * check utd 10^1, 10^0
   */
  if (is_number_char(buffer[30]) == 0) {
    _file_is_valid = 0;
  }

  if (is_number_char(buffer[31]) == 0) {
    _file_is_valid = 0;
  }

  (*file_is_valid) = _file_is_valid;

  return 1;
}

int check_if_configuration_file_exist(int *file_exist) {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "r");

  if (file == NULL) {
    (*file_exist) = 0;
  } else {
    (*file_exist) = 1;
    fclose(file);
  }

  return 1;
}

int set_local_latitude(const float latitide) { return 0; }

int set_local_longitude(const float longitude) { return 0; }

int set_local_ut_difference(const int ut_difference) { return 0; }

int get_local_latitude(float *latitide) { return 0; }

int get_local_longitude(float *longitude) { return 0; }

int get_local_ut_difference(int *ut_difference) { return 0; }
