#include "helpers.h"

#define SECONDS_IN_A_YEAR 31536000
#define SECONDS_IN_A_LEAP_YEAR 31622400

// Register containing the unix time of the RTC
volatile unsigned long long* rtc_phys = (volatile unsigned long long *)(RTC_PHYS);

static unsigned long long get_year_utime(unsigned long long utime)
{
	unsigned long long year = 1970;

	while (utime >= SECONDS_IN_A_YEAR) {
		//To check if is a leap year
		if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) {
			if (utime >= SECONDS_IN_A_LEAP_YEAR) {
				utime -= SECONDS_IN_A_LEAP_YEAR;
				year++;
			} else {
				break;
			}
		} else {
			utime -= SECONDS_IN_A_YEAR;
			year++;
		}
	}

	return year;
}

void print_year()
{
	volatile unsigned long long rtc_unix = *rtc_phys;
	print_num(get_year_utime(rtc_unix), 10);
	printf("\n");
}
