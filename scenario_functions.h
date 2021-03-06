/**
 * Christian Pankratz 2020.
 */

/**
 * scenario calculate azimuthal coordinates
 * param[in] object the object
 * param[in] year the year
 * param[in] month the month
 * param[in] day the day
 * param[in] ut the universal time
 * param[in] lat the local latitude
 * param[in/out] az the azimuth
 * param[in/out] alt the altitude
 */
int scenario_calculate_azimuthal_coordinates(const char* object,
											 const int year,
											 const int month,
											 const int day,
											 const float ut,
											 const float lon,
											 const float lat,
											 float* az,
											 float* alt);
