#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_LINE 1000

/* In a two's complement number representation, our version of `itoa` does not
 * handle largest negative number, that is, the value of `n` equal to 
 * -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
 *  regardless of the machine on which it runs. */

/* The largest negative number is not supported, since the simetric number 
 * cannot be represented using two's complement and the same number of bits.
 * We cannot simple use longs, since for some machines a long can have the same
 * size of an int. */

/* reverse: reverse string s in place */
void reverse(char s[]){
    int c, i, j;
    for(i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do{ /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while((n /= 10) > 0); /* delete it */
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int int_mod(int n, int div){
    int mod = n - ((n/div)*div);
    if(mod < 0)
        mod = -mod;
    return mod;
}

/* itoa_improved: convert n to characters in s */
void itoa_improved(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        ; 
    i = 0;
    do{ /* generate digits in reverse order */
        s[i++] = int_mod(n, 10) + '0'; /* get next digit */
    } while((n /= 10) != 0); /* delete it */
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(){
    printf("Exercise 3-4\n");
    int n = INT_MIN;
    char s[MAX_LINE];

    itoa_improved(n, s);
    printf("Integer: %d\n", n);
    printf("Argument: %s\n", s);

    return 0;
}
