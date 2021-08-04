#include <stdio.h>

/* 
 * Exercise 1-5: Modify the temperature conversion program to print the table
 * in reverse order, that is from 300 degrees to 0
 * */

int main(){
    float fahr, celsius; /* increase precision */
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Fahrenheit(ºF)\tCelsius(ºC)\n");
    fahr = upper;
    while(fahr >= lower){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius); /* Better output with print width */
        fahr = fahr - step;
    }
}
