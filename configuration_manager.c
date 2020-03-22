/**
 * Christian Pankratz 2020.
 */

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

  fprintf(file, "lat=50.000,lon=010.000,utd=00");
  fclose(file);

  return 1;
}

int validate_configuration_file(int *file_is_valid) {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "r");

  if (file == NULL) {
    printf("error create_configuration_file: file could not be created\n");
    return 0;
  }

  char buffer[100];
  fscanf(file, "%[^\n]", buffer);
  fclose(file);

  int _file_is_valid = 1;

  if (buffer[0] != 'l' || //
      buffer[1] != 'a' || //
      buffer[2] != 't' || //
      buffer[3] != '=' || //
      buffer[6] != '.' || //
      buffer[10] != ',') {
    _file_is_valid = 0;
  }

  if (buffer[11] != 'l' || //
      buffer[12] != 'o' || //
      buffer[13] != 'n' || //
      buffer[14] != '=' || //
      buffer[18] != '.' || //
      buffer[22] != ',') {
    _file_is_valid = 0;
  }

  if (buffer[23] != 'u' || //
      buffer[24] != 't' || //
      buffer[25] != 'd' || //
      buffer[26] != '=') {
    _file_is_valid = 0;
  }

  int buffer_positions[] = {4, 5, 7, 8, 9, 15, 16, 17, 19, 20, 21, 27, 28};
  int buffer_positions_count = 13;

  char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int numbers_count = 10;
  int number_matched = 0;

  for (int buffer_index = 0; buffer_index < buffer_positions_count;
       buffer_index++) {
    number_matched = 0;
    for (int numbers_index = 0; numbers_index < numbers_count;
         numbers_index++) {
      if (buffer[buffer_positions[buffer_index]] == numbers[numbers_index]) {
        number_matched = 1;
        break;
      }
    }
    if (number_matched == 0) {
      _file_is_valid = 0;
      break;
    }
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
