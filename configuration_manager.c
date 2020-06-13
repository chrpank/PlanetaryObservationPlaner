/**
 * Christian Pankratz 2020.
 */

#include <math.h>
#include <stdio.h>

#include "configuration_manager.h"

static const int DEBUG_MODE_CONFIGURATION_MANAGER = 1;

const char *CONFIG_FILE_PATH = "pop.cfg";

static const int BUFFER_SIZE = 100;

const char *STD_CONFIG = "lat=+050.000,lon=+010.000,utd=00";

static const int POS_LAT_SIGN = 4;
static const int POS_LAT_10_1 = 5;  // 10^+2
static const int POS_LAT_10_2 = 6;  // 10^+1
static const int POS_LAT_10_3 = 7;  // 10^+0
static const int POS_LAT_10_4 = 9;  // 10^-1
static const int POS_LAT_10_5 = 10; // 10^-2
static const int POS_LAT_10_6 = 11; // 10^-3

static const int POS_LON_SIGN = 17;
static const int POS_LON_10_1 = 18; // 10^+2
static const int POS_LON_10_2 = 19; // 10^+1
static const int POS_LON_10_3 = 20; // 10^+0
static const int POS_LON_10_4 = 22; // 10^-1
static const int POS_LON_10_5 = 23; // 10^-2
static const int POS_LON_10_6 = 24; // 10^-3

static const int POS_UTD_10_1 = 30; // 10^+1
static const int POS_UTD_10_2 = 31; // 10^+0

int create_configuration_file() {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "w");

  if (file == NULL) {
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error in create_configuration_file: file could not be created\n");
    }
    return 0;
  }

  fprintf(file, STD_CONFIG);
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
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: cannot open file\n");
    }
    return 0;
  }

  char buffer[BUFFER_SIZE];
  fscanf(file, "%[^\n]", buffer);
  fclose(file);

  int _file_is_valid = 1;

  /******************************
   ******* check latitude *******
   ******************************/

  /**
   * check latitude sign
   */
  if (buffer[POS_LAT_SIGN] != '+' && //
      buffer[POS_LAT_SIGN] != '-') {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected latitude sign "
             "format\n");
    }
  }

  /**
   * check latitute 10^2, 10^1, 10^0
   */
  if (is_number_char(buffer[POS_LAT_10_1]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected latitude 10^2 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LAT_10_2]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected latitude 10^1 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LAT_10_3]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected latitude 10^0 "
             "format\n");
    }
  }

  /**
   * check latitute 10^-1, 10^-2, 10^-3
   */
  if (is_number_char(buffer[POS_LAT_10_4]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected latitude 10^-1 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LAT_10_5]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected latitude 10^-2 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LAT_10_6]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected latitude 10^-3 "
             "format\n");
    }
  }

  /*******************************
   ******* check longitude *******
   *******************************/

  /**
   * check longitude sign
   */
  if (buffer[POS_LON_SIGN] != '+' && //
      buffer[17] != '-') {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected longitude sign "
             "format\n");
    }
  }

  /**
   * check longitude 10^2, 10^1, 10^0
   */
  if (is_number_char(buffer[POS_LON_10_1]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected longitude 10^2 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LON_10_2]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected longitude 10^1 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LON_10_3]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected longitude 10^0 "
             "format\n");
    }
  }

  /**
   * check longitude 10^-1, 10^-2, 10^-3
   */
  if (is_number_char(buffer[POS_LON_10_4]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected longitude 10^-1 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LON_10_5]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected longitude 10^-2 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_LON_10_6]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected longitude 10^-3 "
             "format\n");
    }
  }

  /*************************
   ******* check utd *******
   *************************/

  /**
   * check utd 10^1, 10^0
   */
  if (is_number_char(buffer[POS_UTD_10_1]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected utd 10^1 "
             "format\n");
    }
  }

  if (is_number_char(buffer[POS_UTD_10_2]) == 0) {
    _file_is_valid = 0;
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error validate_configuration_file: unexpected utd 10^0 "
             "format\n");
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

/**
 * helper function to write config-value
 */
int write_configuration_value(const int postion, const char value) {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "r");

  if (file == NULL) {
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error in write_configuration_value: file could not be created\n");
    }
    return 0;
  }

  char buffer[BUFFER_SIZE];
  fscanf(file, "%[^\n]", buffer);
  fclose(file);

  buffer[postion] = value;

  file = fopen(CONFIG_FILE_PATH, "w");
  fprintf(file, buffer);
  fclose(file);

  return 1;
}

/**
 * helper function to read config-value
 */
int read_configuration_value(const int postion, char *value) {
  FILE *file;
  file = fopen(CONFIG_FILE_PATH, "r");

  if (file == NULL) {
    if (DEBUG_MODE_CONFIGURATION_MANAGER) {
      printf("error in write_configuration_value: file could not be created\n");
    }
    return 0;
  }

  char buffer[BUFFER_SIZE];
  fscanf(file, "%[^\n]", buffer);
  fclose(file);

  *value = buffer[postion];

  return 1;
}

int set_local_latitude(const float latitide) { return 0; }

int set_local_longitude(const float longitude) { return 0; }

int set_local_ut_difference(const int ut_difference) { return 0; }

int get_local_latitude(float *latitide) { return 0; }

int get_local_longitude(float *longitude) { return 0; }

int get_local_ut_difference(int *ut_difference) { return 0; }
