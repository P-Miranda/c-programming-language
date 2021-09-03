#include <stdio.h>

#define MAX_LINE (100)

/* Write a function `invert(x,p,n)` that returns `x` with the `n` bits that 
 * begin at position `p` inverted (i.e. 1 changed to 0 and vice versa), leaving
 * the others unchanged. */

/* invert: invert a range of bits */
unsigned int invert(unsigned int x, int p, int n){
    /* auxiliar masks */
    unsigned int x_remove_mask = (~0 << (p+n)) | ~(~(1 << n) << p);
    unsigned int x_get_mask = ~x_remove_mask;

    /* get bits from x */
    unsigned int x_bits = x & x_get_mask;
    x_bits = ~x_bits & x_get_mask;

    /* set x bits */
    /* set x bits */
    x = x & x_remove_mask;
    x = x | x_bits;
    return x;
}

int main(){
    printf("Exercise2-7\n");
    unsigned int x = 0xFFF;
    int n = 4;
    int p = 4;

    
    printf("x: %x\n", x);
    printf("p: %d\n", p);
    printf("n: %d\n", n);
    x = invert(x, p, n);
    printf("setbits x: %x\n", x);

    return 0;
}

