#include <stdio.h>

#define MAX_MONTH 12
#define MAX_YEARDAY 365

/* There is no error checking in `day_of_year` and `month_day`. Remedy this 
 * defect. */

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

/* sort input lines */
int main(){
    int pmonth = 0, pday = 0;
    int yeardays[3];

    printf("Day of year %2d/%2d/%4d: %3d\n", 31, 12, 2021, yeardays[0] = day_of_year(2021, 12, 31));
    printf("Day of year %2d/%2d/%4d: %3d\n", 1, 3, 2020, yeardays[1] = day_of_year(2020, 3, 1));
    printf("Day of year %2d/%2d/%4d: %3d\n", 8, 10, 2021, yeardays[2] = day_of_year(2021, 10, 8));

    month_day(2021, yeardays[0], &pmonth, &pday);
    printf("Month Day of %3d: %2d/%2d\n", yeardays[0], pday, pmonth);
    month_day(2020, yeardays[1], &pmonth, &pday);
    printf("Month Day of %3d: %2d/%2d\n", yeardays[1], pday, pmonth);
    month_day(2021, yeardays[2], &pmonth, &pday);
    printf("Month Day of %3d: %2d/%2d\n", yeardays[2], pday, pmonth);

    printf("\nInvalid tests:\n");
    printf("Day of year %2d/%2d/%4d: %3d\n", 42, 10, 2021, day_of_year(2021, 10, 42));
    printf("Day of year %2d/%2d/%4d: %3d\n", 8, 14, 2021, day_of_year(2021, 14, 8));
    printf("Day of year %2d/%2d/%4d: %3d\n", 8, 10, -2021, day_of_year(-2021, 10, 8));

    month_day(2021, 400, &pmonth, &pday);
    printf("Month Day of %3d: %2d/%2d\n", 400, pday, pmonth);
    month_day(2020, -21, &pmonth, &pday);
    printf("Month Day of %3d: %2d/%2d\n", -21, pday, pmonth);

    return 0;
}

static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day of year: set day of year from month & day */
int day_of_year(int year, int month, int day){
    int i, leap;

    /* check for valid date: Month 1-12, day 1-daytab[Month], year > 0 */
    if(year <= 0){
        printf("Error: invalid date. CE Years only.n\n");
        return -1;
    }
    if(month < 1 || month > MAX_MONTH){
        printf("Error: invalid date. Invalid month %d\n.", month);
        return -1;
    }

    leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

    if(day < 1 || day > *(*(daytab+leap)+month)){
        printf("Error: invalid date. Invalid day %d\n.", day);
        return -1;
    }

    for(i = 1; i < month; i++)
        day += *(*(daytab+leap)+i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    /* check for valid date: yearday 1-365/366 */

    leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

    if(yearday < 1 || yearday > MAX_YEARDAY+leap){
        printf("Error: invalid date. Invalid yearday %d\n.", yearday);
        *pmonth = 0;
        *pday = 0;
        return;
    }

    for(i = 1; yearday > *(*(daytab+leap)+i); i++)
        yearday -= *(*(daytab+leap)+i);
    *pmonth = i;
    *pday = yearday;
}
