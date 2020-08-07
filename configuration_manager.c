/**
 * Christian Pankratz 2020.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "configuration_manager.h"

static const int DEBUG_MODE_CONFIGURATION_MANAGER = 1;

const char* CONFIG_FILE_PATH = "pop.cfg";

const int index_lat = 0;
const int index_lon = 1;
const int index_utd = 2;
float config_buffer[3];

int load_configuration_file()
{
	FILE* file;
	int buffer_length = 40;
	char line_buffer[buffer_length];

	file = fopen(CONFIG_FILE_PATH, "r");

	if(file == NULL)
	{
		printf("load_configuration_file: file open has failed");
		return 0;
	}

	for(int index = 0; index < 3; index++)
	{
		fgets(line_buffer, buffer_length, file);
		float value = strtof(line_buffer, NULL);

		if(index == index_lat)
		{
			config_buffer[index_lat] = value;
		}

		if(index == index_lon)
		{
			config_buffer[index_lon] = value;
		}

		if(index == index_utd)
		{
			config_buffer[index_utd] = value;
		}
	}

	fclose(file);
	return 1;
}

int write_configuration_file()
{
	FILE* file;
	file = fopen(CONFIG_FILE_PATH, "w");

	if(file == NULL)
	{
		printf("write_configuration_file: file open has failed");
		return 0;
	}

	for(int index = 0; index < 3; index++)
	{

		if(index == index_lat)
		{
			fprintf(file, "%f\n", config_buffer[index_lat]);
		}

		if(index == index_lon)
		{
			fprintf(file, "%f\n", config_buffer[index_lon]);
		}

		if(index == index_utd)
		{
			fprintf(file, "%f\n", config_buffer[index_utd]);
		}
	}

	fclose(file);
	return 1;
}

int delete_configuration_file()
{
	FILE* file;
	file = fopen(CONFIG_FILE_PATH, "r");

	if(file != NULL)
	{
		fclose(file);

		if(remove(CONFIG_FILE_PATH) != 0)
		{
			printf("delete_configuration_file: unable to delete the file");

			return 0;
		}
	}

	return 1;
}

int set_local_latitude(const float latitide)
{
	config_buffer[index_lat] = latitide;

	return 1;
}

int set_local_longitude(const float longitude)
{
	config_buffer[index_lon] = longitude;

	return 1;
}

int set_local_ut_difference(const float ut_difference)
{
	config_buffer[index_utd] = ut_difference;

	return 1;
}

int get_local_latitude(float* latitide)
{
	*latitide = config_buffer[index_lat];

	return 1;
}

int get_local_longitude(float* longitude)
{
	*longitude = config_buffer[index_lon];

	return 1;
}

int get_local_ut_difference(float* ut_difference)
{
	*ut_difference = config_buffer[index_utd];

	return 1;
}
