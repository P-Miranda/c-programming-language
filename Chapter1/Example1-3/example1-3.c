#include <stdio.h>

/* Symbolic Constants Example (DEFINE) */
/* Also, program written using for() loop */



/* printf Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300;
    floating-point version (multiple improvements)
    */

#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit          */
#define STEP 20     /* step size            */

int main(){
    int fahr;

    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP){
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
