#include <stdio.h>

#define MAX_LINE (100)

/* Write the function `htoi(s)`, which converts a string of hexadecimal digits
 * (including optional 0x or 0X) into its equivalent integer value. The 
 * allowable digits are 0 through 9, a through f and A through F.*/

int htoi(char s[]){
    char c = 0;
    int i = 0;
    int hex_start = 0; /* first char to convert */
    int n = 0;
    int n_iters = 0;

    /* check for 0x or 0X start */
    if (s[0] == '0' && ((s[1] == 'x') || (s[1] == 'X')))
        hex_start = 2;
    else
        hex_start = 0;
    /* Read entire string */
    for(i = hex_start; ((c = s[i]) != '\0') && ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')); ++i){
        /* 0 - 9 */
        if( c >= '0' && c <= '9')
            n = 16 * n + (c - '0');
        /* a - f */
        if( c >= 'a' && c <= 'f')
            n = 16 * n + (c - 'a' + 10);
        /* A - F */
        if( c >= 'A' && c <= 'F')
            n = 16 * n + (c - 'A' + 10);
    }
    return n;
}
int main(){
    printf("Exercise2-3\n");

    char s[MAX_LINE];
    int value = 0;
    char s1[] = "0x01AC3"; /* 6851 */
    char s2[] = "0X01ac3";
    char s3[] = "01aC3";
    char s4[] = "01Ac3oajjnv";
    char s5[] = "oajjnv";

    value = htoi(s1);
    printf("%s -> %d\n", s1, value);
    value = htoi(s2);
    printf("%s -> %d\n", s2, value);
    value = htoi(s3);
    printf("%s -> %d\n", s3, value);
    value = htoi(s4);
    printf("%s -> %d\n", s4, value);
    value = htoi(s5); 
    printf("%s -> %d\n", s5, value);

    return 0;
}

