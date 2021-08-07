#include <stdio.h>

/* Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and 
 * backspaces visible in an unambiguous way. */

int main(){
    int c;

    while((c = getchar()) != EOF){
        /* detect special cases */
        if((c == '\t')){
            putchar('\\');
            putchar('t');
        }
        else if((c == '\b')){
            putchar('\\');
            putchar('b');
            /* Note: if you don't see backspaces if probably because your 
             * terminal is in Canonical Mode Input Processing, which means that
             * only sends characters after each line.
             * Source: https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap11.html#tag_11_01_06 */
        }
        else if((c == '\\')){
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
}
