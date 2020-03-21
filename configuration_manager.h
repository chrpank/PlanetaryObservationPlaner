/**
 * Christian Pankratz 2020.
 */

/**
 * create configuration file
 * return not 0 if success, 0 otherwise
 */
int create_configuration_file();

/**
 * validate configuration file
 * return not 0 if file is valid, 0 otherwise
 */
int validate_configuration_file();

/**
 * set local latitude
 * param[in] latitide the local latitide
 * return not 0 if success, 0 otherwise
 */
int set_local_latitude(const float latitide);

/**
 * set local longitude
 * param[in] longitude the local longitude
 * return not 0 if success, 0 otherwise
 */
int set_local_longitude(const float longitude);

/**
 * set local ut difference
 * param[in] ut_difference the local ut difference
 * return not 0 if success, 0 otherwise
 */
int set_local_ut_difference(const int ut_difference);

/**
 * get local latitude
 * param[in/out] latitide the local latitide
 * return not 0 if success, 0 otherwise
 */
int get_local_latitude(float *latitide);

/**
 * get local longitude
 * param[in/out] longitude the local longitude
 * return not 0 if success, 0 otherwise
 */
int get_local_longitude(float *longitude);

/**
 * get local ut difference
 * param[in/out] ut_difference the local ut difference
 * return not 0 if success, 0 otherwise
 */
int get_local_ut_difference(int *ut_difference);
