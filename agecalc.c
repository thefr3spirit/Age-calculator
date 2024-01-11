/*The following program calculates your age with month and date precission*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    // declaring the time_now variable to hold current time
    time_t time_now;

    // Using the time function to put the current time into variable
    time(&time_now);

    // tm structure for local time
    struct tm *current_time = localtime(&time_now);

    // declare a pointer for the time as string
    char *time_string = ctime(&time_now);

    // declare variables to store birth credentials
    int year, month, day;

    // prompt the user to enter their birth date info
    printf("Please enter your date of birth (YYYY, MM, DD).\n");
    printf("Year: ");
    scanf("%d", &year);
    printf("Month: ");
    scanf("%d", &month);
    printf("Date: ");
    scanf("%d", &day);

    // variables to store calculated age
    int age_year = current_time->tm_year + 1900 - year;
    int age_month = current_time->tm_mon + 1 - month;
    int age_day = current_time->tm_mday - day;

    // adjust age_month and age_day if negative
    if (age_month < 0) {
        age_year--;
        age_month += 12;
    }

    if (age_day < 0) {
        age_month--;
        age_day += 30; 
    }

    printf("You are %d years, %d months, and %d days old as of %s", age_year, age_month, age_day, time_string);

    return 0;
}
