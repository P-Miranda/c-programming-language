#include <stdio.h>

#define MAX_LINE (100)

/* Write a function `rightrot(x,n)` that returns the value of the integer `x`
 * rotated to the right by `n` bit positions. */

/* rightrot: rotate x by n bit positions */
unsigned int rightrot(unsigned int x, int n){
    unsigned int right_part = 0;
    unsigned int single_bit = 0;
    int bit = 0;

    while(bit < n){
        single_bit = (((x << 31-bit) >> 31) << (31-n+1+bit));
        right_part = right_part | single_bit;
        bit++;
    }

    /* left part */
    x = x >> n;
    x = x | right_part;
    return x;
}

int main(){
    printf("Exercise2-8\n");
    unsigned int x = 0xFFF;
    int n = 4;

    
    printf("x: %x\n", x);
    printf("n: %d\n", n);
    x = rightrot(x, n);
    printf("setbits x: %x\n", x);

    return 0;
}

