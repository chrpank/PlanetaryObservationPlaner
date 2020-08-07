/**
 * Christian Pankratz 2020.
 */

#include <stdio.h>

#include "base_functions.h"

static const int DEBUG_MODE_SCENARIO_FUNCTIONS = 1;

int scenario_calculate_azimuthal_coordinates(const char* object,
											 const int year,
											 const int month,
											 const int day,
											 const float ut,
											 const float lon,
											 const float lat,
											 float* az,
											 float* alt)
{
	int success = 1;

	/****************************************************************************/
	// calculate_time_scale

	float d;
	if(calculate_time_scale(year, month, day, ut, &d) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_time_scale failed");
		}
		success = 0;
	}

	/****************************************************************************/
	// calculate_orbital_elements

	float N_obj, i_obj, w_obj, a_obj, e_obj, M_obj;
	if(calculate_orbital_elements(object, &N_obj, &i_obj, &w_obj, &a_obj, &e_obj, &M_obj, d) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_orbital_elements failed");
		}
		success = 0;
	}

	float N_sun, i_sun, w_sun, a_sun, e_sun, M_sun;
	if(calculate_orbital_elements("sun", &N_sun, &i_sun, &w_sun, &a_sun, &e_sun, &M_sun, d) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_orbital_elements failed");
		}
		success = 0;
	}

	/****************************************************************************/
	// calculate_obliquity_ecliptic

	float ecl;
	if(calculate_obliquity_ecliptic(&ecl, d) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_obliquity_ecliptic failed");
		}
		success = 0;
	}

	/****************************************************************************/
	// calculate_local_sidereal_time

	float LST;
	if(calculate_local_sidereal_time(year, month, day, ut, lon, &LST) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_local_sidereal_time failed");
		}
		success = 0;
	}

	/****************************************************************************/
	// calculate_true_anomaly

	float r_obj, v_obj;
	if(calculate_true_anomaly(M_obj, e_obj, a_obj, &r_obj, &v_obj) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_true_anomaly failed");
		}
		success = 0;
	}

	float r_sun, v_sun;
	if(calculate_true_anomaly(M_sun, e_sun, a_sun, &r_sun, &v_sun) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_true_anomaly failed");
		}
		success = 0;
	}

	/****************************************************************************/
	// calculate_position_in_space

	float xh_obj, yh_obj, zh_obj, lonecl_obj, latecl_obj;
	if(calculate_position_in_space(r_obj,
								   N_obj,
								   v_obj,
								   w_obj,
								   i_obj,
								   &xh_obj,
								   &yh_obj,
								   &zh_obj,
								   &lonecl_obj,
								   &latecl_obj) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_position_in_space failed");
		}
		success = 0;
	}

	float xh_sun, yh_sun, zh_sun, lonecl_sun, latecl_sun;
	if(calculate_position_in_space(r_sun,
								   N_sun,
								   v_sun,
								   w_sun,
								   i_sun,
								   &xh_sun,
								   &yh_sun,
								   &zh_sun,
								   &lonecl_sun,
								   &latecl_sun) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_position_in_space failed");
		}
		success = 0;
	}

	/****************************************************************************/
	// calculate_pertubations_moon

	if(strcmp(object, "moon") == 0)
	{
		if(calculate_pertubations_moon(
			   M_sun, M_obj, N_obj, w_sun, w_obj, &lonecl_obj, &latecl_obj, &r_obj) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_pertubations_moon failed");
			}
			success = 0;
		}
	}

	/****************************************************************************/
	// calculate_pertubations_planets

	if(strcmp(object, "jupiter") == 0)
	{
		float M_sat, dummy;
		if(calculate_orbital_elements(
			   "saturn", &dummy, &dummy, &dummy, &dummy, &dummy, &M_sat, d) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_orbital_elements failed");
			}
			success = 0;
		}

		if(calculate_pertubations_planets(
			   M_obj, M_sat, dummy, &lonecl_obj, &latecl_obj, &dummy, &dummy, &dummy, &dummy) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_pertubations_planets failed");
			}
			success = 0;
		}
	}

	if(strcmp(object, "saturn") == 0)
	{
		float M_jup, dummy;
		if(calculate_orbital_elements(
			   "jupiter", &dummy, &dummy, &dummy, &dummy, &dummy, &M_jup, d) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_orbital_elements failed");
			}
			success = 0;
		}

		if(calculate_pertubations_planets(
			   M_jup, M_obj, dummy, &dummy, &dummy, &lonecl_obj, &latecl_obj, &dummy, &dummy) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_pertubations_planets failed");
			}
			success = 0;
		}
	}

	if(strcmp(object, "uranus") == 0)
	{
		float M_sat, dummy;
		if(calculate_orbital_elements(
			   "saturn", &dummy, &dummy, &dummy, &dummy, &dummy, &M_sat, d) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_orbital_elements failed");
			}
			success = 0;
		}

		float M_jup;
		if(calculate_orbital_elements(
			   "jupiter", &dummy, &dummy, &dummy, &dummy, &dummy, &M_jup, d) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_orbital_elements failed");
			}
			success = 0;
		}

		if(calculate_pertubations_planets(
			   M_jup, M_sat, M_obj, &dummy, &dummy, &dummy, &dummy, &lonecl_obj, &latecl_obj) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_pertubations_planets failed");
			}
			success = 0;
		}
	}

	/****************************************************************************/
	// calculate_geocentric_coordinates_moon and planets

	float xg_obj, yg_obj, zg_obj;
	if(strcmp(object, "moon") == 0)
	{
		if(calculate_geocentric_coordinates_moon(
			   lonecl_obj, latecl_obj, r_obj, &xg_obj, &yg_obj, &zg_obj) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_geocentric_coordinates_moon failed");
			}
			success = 0;
		}
	}
	else
	{
		if(calculate_geocentric_coordinates_planet(
			   lonecl_obj, latecl_obj, r_obj, lonecl_sun, r_sun, &xg_obj, &yg_obj, &zg_obj) == 0)
		{
			if(DEBUG_MODE_SCENARIO_FUNCTIONS)
			{
				printf("error scenario_calculate_azimuthal_coordinates: the function "
					   "calculate_geocentric_coordinates_planet "
					   "failed");
			}
			success = 0;
		}
	}

	/****************************************************************************/
	// calculate_equatorial_coordinates

	float RA_obj, Dec_obj, rg_obj;
	if(calculate_equatorial_coordinates(xg_obj, yg_obj, zg_obj, ecl, &RA_obj, &Dec_obj, &rg_obj) ==
	   0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_equatorial_coordinates failed");
		}
		success = 0;
	}

	/****************************************************************************/
	// calculate_azimuthal_coordinates

	if(calculate_azimuthal_coordinates(RA_obj, Dec_obj, LST, lat, az, alt) == 0)
	{
		if(DEBUG_MODE_SCENARIO_FUNCTIONS)
		{
			printf("error scenario_calculate_azimuthal_coordinates: the function "
				   "calculate_azimuthal_coordinates failed");
		}
		success = 0;
	}

	return success;
}
