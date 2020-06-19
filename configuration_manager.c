/**
 * Christian Pankratz 2020.
 */

#include <stdio.h>

#include "configuration_manager.h"

static const int DEBUG_MODE_CONFIGURATION_MANAGER = 1;

const char *CONFIG_FILE_PATH = "pop.cfg";

int load_configuration_file() { return 0; }

int write_configuration_file() { return 0; }

int delete_configuration_file() { return 0; }

int check_if_configuration_file_exist(int *file_exist) { return 0; }

int set_local_latitude(const float latitide) { return 0; }

int set_local_longitude(const float longitude) { return 0; }

int set_local_ut_difference(const int ut_difference) { return 0; }

int get_local_latitude(float *latitide) { return 0; }

int get_local_longitude(float *longitude) { return 0; }

int get_local_ut_difference(int *ut_difference) { return 0; }
