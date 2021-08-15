#include <stdio.h>

float fahr_to_celsius(float fahr);

/* Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion. */

int main(){
    float fahr; /* increase precision */
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while(fahr <= upper){
        printf("%3.0f\t%6.1f\n", fahr, fahr_to_celsius(fahr)); /* Better output with print width */
        fahr = fahr + step;
    }
}

float fahr_to_celsius(float fahr){
    float celsius = (5.0/9.0) * (fahr - 32.0);
    return celsius;
}
