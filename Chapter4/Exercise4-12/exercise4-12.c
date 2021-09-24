#include <stdio.h>
#include <string.h>

/* Adapt the ideias of `printd()` to write a recursive version of `itoa()`; that
 * is, convert an integer into a string by calling a recursive routine */

void itoa(int n, char s[]);
void itoa_recursive(int n, char s[]);
void reverse(char s[]);
void printd(int n);

int main(){
    int value = -1234567;
    char s1[100], s2[100];

    printf("Value: %d\n", value);
    itoa(value, s1);
    printf("itoa: %s\n", s1);
    itoa_recursive(value, s2);
    printf("itoa_recursive: %s\n", s2);
    printf("Printd():");
    printd(value);
    printf("\n");
    return 0;
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

void itoa_recursive(int n, char s[]){
    int idx = 0;
    if(n < 0){ /* check for negative number */
        s[0] = '-';
        n = -n;
    }

    if( n/10 )
        itoa_recursive(n/10, s);
    else
        s[idx+1] = '\0';

    if(s[0] == '-')
        idx++;

    while(s[idx] >= '0' && s[idx] <= '9')
        idx++;

    s[idx] =  n % 10 + '0'; 

    if( n/10 == 0 )
        s[idx+1] = '\0';
}

void printd(int n){
    if(n < 0){
        putchar('-');
        n = -n;
    }

    if( n/10 )
        printd( n/10 );

    putchar( n % 10 + '0' );
}

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

