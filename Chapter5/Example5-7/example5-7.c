#include <stdio.h>


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

    return 0;
}

static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day of year: set day of year from month & day */
int day_of_year(int year, int month, int day){
    int i, leap;

    leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
    for(i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
    for(i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
