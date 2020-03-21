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

  fprintf(file, "lat=50,lon=010,utd=00\n");
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
      buffer[3] != '=') {
    _file_is_valid = 0;
  }

  if (buffer[7] != 'l' || //
      buffer[8] != 'o' || //
      buffer[9] != 'n' || //
      buffer[10] != '=') {
    _file_is_valid = 0;
  }

  if (buffer[15] != 'u' || //
      buffer[16] != 't' || //
      buffer[17] != 'd' || //
      buffer[18] != '=') {
    _file_is_valid = 0;
  }

  (*file_is_valid) = _file_is_valid;

  return 1;
}

int check_if_configuration_file_exist() { return 0; }

int set_local_latitude(const float latitide) { return 0; }

int set_local_longitude(const float longitude) { return 0; }

int set_local_ut_difference(const int ut_difference) { return 0; }

int get_local_latitude(float *latitide) { return 0; }

int get_local_longitude(float *longitude) { return 0; }

int get_local_ut_difference(int *ut_difference) { return 0; }
