#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* 
Determine if the year is a leap year or not.
The algorithm is as follows:
on every year that is evenly divisible by 4
  except every year that is evenly divisible by 100
    unless the year is also evenly divisible by 400
 */
int isleap(int yr)
{
	int is_div_by_4 = 0;
	int is_div_by_100 = 0;
	int is_div_by_400 = 0;

	is_div_by_4 = yr % 4 == 0;
	is_div_by_100 = yr % 100 == 0;
	is_div_by_400 = yr % 400 == 0;

	if (is_div_by_4 && is_div_by_400 && is_div_by_400) {
		return 1;
	} else if (is_div_by_4 && !is_div_by_100) {
		return 1;
	} else {
		return 0;
	}
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
			if (isleap(atoi(argv[1]))) {
				printf("\n The year %s is a leap year.\n", argv[1]);
			} else {
				printf("\n The year %s is NOT a leap year.\n", argv[1]);
			}
		} else {
			//the argument is a date string, convert to timestamp
			printf("\n You need to put in a year between 0 and 9999\n");
		}
	} else {
		printf("\n You're doing it wrong... This command works as follow:\n\n");
		printf("\t isleap year\n\n");
	}
	return 0;
}