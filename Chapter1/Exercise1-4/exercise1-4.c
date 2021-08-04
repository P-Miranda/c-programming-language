#include <stdio.h>

/* 
 * Exercise 1-4: Write a program to print the corresponding Celsius to 
 * Fahrenheit table.
 * */

int main(){
    float fahr, celsius; /* increase precision */
    float lower, upper, step;

    lower = -17.8;      /* lower limit of temperature */
    upper = 148.9;    /* upper limit */
    step = 11.1;      /* step size */

    printf("Celsius(ºC)\tFahrenheit(ºF)\n");
    celsius = lower;
    while(celsius <= upper){
        /* celsius = (5.0/9.0) * (fahr - 32.0); */
        fahr = ((9.0/5.0) * celsius) + 32.0;
        printf("%6.1f\t\t%3.1f\n", celsius, fahr); /* Better output with print width */
        celsius = celsius + step;
    }
}
