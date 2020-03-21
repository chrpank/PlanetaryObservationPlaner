/**
 * Christian Pankratz 2020.
 */

#include <stdio.h>

#include "configuration_manager.h"

const char *CONFIG_FILE_PATH = "pop.cfg";

int create_configuration_file() {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "w");

  if (file != NULL) {
    fprintf(file, "lat=50, local latitude\n");
    fprintf(file, "lon=10, local longitude\n");
    fprintf(file, "utd=00, difference to universal time\n");
    fclose(file);
  }

  return 1;
}

int validate_configuration_file() { return 0; }

int check_if_configuration_file_exist() { return 0; }

int set_local_latitude(const float latitide) { return 0; }

int set_local_longitude(const float longitude) { return 0; }

int set_local_ut_difference(const int ut_difference) { return 0; }

int get_local_latitude(float *latitide) { return 0; }

int get_local_longitude(float *longitude) { return 0; }

int get_local_ut_difference(int *ut_difference) { return 0; }
