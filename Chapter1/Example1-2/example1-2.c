#include <stdio.h>

/* printf Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300;
    floating-point version (multiple improvements)
    */

int main(){
    float fahr, celsius; /* increase precision */
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius); /* Better output with print width */
        fahr = fahr + step;
    }
}
