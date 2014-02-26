#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//* Convert a date in format "2014-02-25 12:01:02" to a Unix timestamp */
int date_to_timestamp(char *date_str)
{
	struct tm tm;
	time_t epoch;
	
	if ( strptime(date_str, "%Y-%m-%d %H:%M:%S", &tm) != NULL ) {
  		epoch = mktime(&tm);
  		printf("\n The timestamp for %s is: %li \n\n", date_str, epoch);
	} else {
  		printf("Err, something went wrong");
  	}
  	return 0;
}

/* Convert a Unix timestamp to a date string */
int timestamp_to_date(int t)
{
	char buff[70];
	struct tm ts;
	time_t tmp = (time_t) t;

	(void) gmtime_r(&tmp, &ts);

	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &ts);

	printf("\n The date for timestamp %i is: %s \n\n", t, buff);
	
	return 0;
}

/* Checks if the argument is a string or a number */
int isnumeric(char *str) 
{
	do if (!isdigit(*str)) {
		return 0;
	} while(*++str);

	return 1;
}

int main(int argc, char *argv[])
{
	if (argc == 2) {
		if (isnumeric(argv[1])) {
			//the argument is a number convert to date
			timestamp_to_date(atoi(argv[1]));
		} else {
			//the argument is a date string, convert to timestamp
			date_to_timestamp(argv[1]);
		}
	} else {
		printf("\n You're doing it wrong... This command works as follow:\n\n");
		printf("\t datetool date|timestamp\n\n");
	}
	return 0;
}