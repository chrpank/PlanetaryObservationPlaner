/**
 * Christian Pankratz 2020.
 */

/**
 * date data type
 */
typedef struct {
  int year;
  int month;
  int day;
  float ut;
} date;

/**
 * check if date is valid
 * param[in] date the date data type
 * return not 0 if success, 0 otherwise
 */

int is_date_valid(const date date);

/**
 * set date
 * param[in] year the year
 * param[in] month the month
 * param[in] day the day
 * param[in] ut the universal time
 * param[in/out] date the date data type
 * return not 0 if success, 0 otherwise
 */
int set_date(const int year, const int month, const int day, const float ut,
             date *date);

/**
 * time step forward
 * param[in/out] date the date data type
 * param[in] step the step
 * return not 0 if success, 0 otherwise
 */
int step_forward(date *date, const float step);

/**
 * time step backward
 * param[in/out] date the date data type
 * param[in] step the step
 * return not 0 if success, 0 otherwise
 */
int step_backward(date *date, const float step);

/**
 * print the date
 * param[in] date the date data type
 * return not 0 if success, 0 otherwise
 */
int print_date(const date date);

/**
 * set date to system date
 * param[in] date the date data type
 * return not 0 if success, 0 otherwise
 */
int set_date_to_system_date(date *date);

/**
 * check if year is leap year
 * param[in] date the date data type
 * return not 0 if leap year, 0 otherwise
 */
int is_leap_year(const date date);
