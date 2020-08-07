/**
 * Copyright 2020 Christian Pankratz.
 */

#ifndef CONFIGURATION_MANAGER_H_
#define CONFIGURATION_MANAGER_H_

/**
 * configuration data type
 * local_latitude the local latitude
 * local_longitude the local longitude
 * ut_difference the difference to universal time
 * object_azimuth the objects goal azimuth
 * object_altitude the objects minimum goal altitude
 * sun_altitude the sun maximum goal altitude
 */

typedef struct
{
	float local_latitude;
	float local_longitude;
	int ut_difference;
	float object_azimuth;
	float object_altitude;
	float sun_altitude;
} config;

/**
 * load configuration file
 * return not 0 if success, 0 otherwise
 */
int load_configuration_file();

/**
 * write configuration file
 * return not 0 if success, 0 otherwise
 */
int write_configuration_file();

/**
 * delete configuration file
 * return not 0 if success, 0 otherwise
 */
int delete_configuration_file();

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
int set_local_ut_difference(const float ut_difference);

/**
 * get local latitude
 * param[in/out] latitide the local latitide
 * return not 0 if success, 0 otherwise
 */
int get_local_latitude(float* latitide);

/**
 * get local longitude
 * param[in/out] longitude the local longitude
 * return not 0 if success, 0 otherwise
 */
int get_local_longitude(float* longitude);

/**
 * get local ut difference
 * param[in/out] ut_difference the local ut difference
 * return not 0 if success, 0 otherwise
 */

int get_local_ut_difference(float* ut_difference);

#endif // CONFIGURATION_MANAGER_H_
