#include <stdio.h>

#define MAX_LINE (100)

/* Ina two's complement number system, `x &= (x-1)` deletes the rightmost 1-bit
 * in `x`. Explain why. Use this observation to write a faster version of
 * `bitcount`*/

/* bitcount: count 1 bits in x */
int bitcount(unsigned x){
    int b;
    for(b = 0; x != 0; x >>= 1)
        if(x & 01)
            b++;

    return b;
}

/* 
Val: bin    (x & x-1)
15: 1111    1110
14: 1110    1100
13: 1101    1100
12: 1100    1000
11: 1011    1010
10: 1010    1000
09: 1001    1000
08: 1000    0000
07: 0111    0110
06: 0110    0100
05: 0101    0100
04: 0100    0000
03: 0011    0010
02: 0010    0000
01: 0001    0000
00: 0000

Any value x has a rightmost bit n, x-1 does not have that bit, performing AND
over x AND x-1 removes the rightmost bit at all times
 * */

/* bitcount_faster: faster implementation of bitcount*/
int bitcount_faster(unsigned x){
    int b;
    for(b = 0; x != 0; x &= (x-1))
        b++;

    return b;
}

int main(){
    printf("Exercise2-9\n");
    unsigned int x = 0xFFF;
    int n_bits = 0;

    
    printf("x: %x\n", x);
    n_bits = bitcount(x);
    printf("bitcount x: %d\n", n_bits);
    n_bits = bitcount_faster(x);
    printf("bitcount_faster x: %d\n", n_bits);

    return 0;
}

