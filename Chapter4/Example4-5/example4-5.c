#include <stdio.h>

/* Recursive implementation of `printd()`*/

void printd(int n);

int main(){
    int value = 1234567890;

    printd(value);
    return 0;
}

/* printd: print n in decimal*/
void printd(int n){
    if(n < 0){
        putchar('-');
        n = -n;
    }

    if( n/10 )
        printd( n/10 );

    putchar( n % 10 + '0' );
}

