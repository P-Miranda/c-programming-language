#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_LINE 1000

/* Write a version of `itoa` that acepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough. */

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
void itoa_padded(int n, char s[], int pad){
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do{ /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while((n /= 10) > 0); /* delete it */
    for(;i<pad;i++) /* add minimum padding */
        s[i] = '0';
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main(){
    printf("Exercise 3-6\n");
    int n = 10;
    int n2 = 6543141;
    char s[MAX_LINE];

    itoa_padded(n, s, 5);
    printf("Integer: %d\n", n);
    printf("Argument: %s\n", s);

    itoa_padded(n2, s, 5);
    printf("Integer: %d\n", n2);
    printf("Argument: %s\n", s);
    return 0;
}
