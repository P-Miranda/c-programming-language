#include <stdio.h>

/* 
 * Exercise 1-3: Modify the temperature conversion program to print a heading
 * above the table
 * */

int main(){
    float fahr, celsius; /* increase precision */
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Fahrenheit(ºF)\tCelsius(ºC)\n");
    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius); /* Better output with print width */
        fahr = fahr + step;
    }
}
