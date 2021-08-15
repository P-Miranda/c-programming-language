#include <stdio.h>

int power(int m, int n);
int power_arg(int m, int n);

/* test power function*/

int main(){
    int i;

    for(i=0; i<10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

/* power: raise base to n-th power; n>=0 */
int power(int base, int n){
    int i, p;

    p=1;
    for(i=0; i<n; ++i)
        p = p*base;
    return p;
}

/* power_arg: raise base to n-th power; n>=0 
 * Uses the return by value properties of functions */
int power_arg(int base, int n){
    int p;

    for(p=1; n>0; --n)
        p = p*base;
    return p;
}
