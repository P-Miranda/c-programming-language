#include <stdio.h>

#define MAX_LINE (100)

/* Write a function `setbits(x,p,n,y)` that returns `x` with the `n` bits that 
 * begin at position `p` set to the rightmost `n` bits of `y`, leaving the other
 * bits unchanged. */

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: replace n bits of x, starting from p with the n LSB's from y*/
unsigned int setbits(unsigned int x, int p, int n, unsigned int y){
    /* get n LSB from y */
    unsigned int n_bits_of_y = (y & (~(1 << n))) << (p);

    /* remove [p:p+n-1] bits of n */
    unsigned int x_mask = (~0 << (p+n)) | ~(~(1 << n) << p);
    unsigned int x_cleaned = x & x_mask;

    /* add y bits to x */
    x = x_cleaned | n_bits_of_y;

    return x;

    
}

int main(){
    printf("Exercise2-6\n");
    unsigned int x = 0xFFF;
    unsigned int y = 0x003;
    int n = 4;
    int p = 4;

    
    printf("x: %x\n", x);
    printf("y: %x\n", y);
    printf("p: %d\n", p);
    printf("n: %d\n", n);
    x = setbits(x, p, n, y);
    printf("setbits x: %x\n", x);

    return 0;
}

