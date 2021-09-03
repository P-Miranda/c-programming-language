#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_LINE 1000

/* Write the function `itob(n,s,b)` that converts the integer `n` into a base 
 * `b` character representation in the string `s`. In particular, `iob(n,s,16)`
 * formats `n` as a hexadecimal integer in s. */

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

char digit_mod(int n, int div){
    int mod = n - ((n/div)*div);
    char digit;
    if(mod < 0)
        mod = -mod;
    /* get digit from mod value */
    if(mod < 10)
        digit = mod + '0';
    else /* A-Z digits */
        digit = mod - 10 + 'A';
    return digit;
}

/* itob: convert n to strint in base b */
void itob(int n, char s[], int b){
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        ; 
    i = 0;
    do{ /* generate digits in reverse order */
        s[i++] = digit_mod(n,b); /* get next digit */
    } while((n /= b) != 0); /* delete it */
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(){
    printf("Exercise 3-5\n");
    int n = INT_MAX;
    char s[MAX_LINE];
    char sb[MAX_LINE];

    itoa_improved(n, s);
    printf("Integer: %d\n", n);
    printf("Argument: %s\n", s);
    itob(n,sb,16);
    printf("Integer: %x\n", n);
    printf("Argument: %s\n", sb);


    return 0;
}
