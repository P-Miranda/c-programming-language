#include <stdio.h>

/* Write a program to copy its input to its output, replacing each string of one
 * or more blanks by a single blank */

int main(){
    int c, prev_c;

    prev_c = -1;

    while((c = getchar()) != EOF){
        if((c == ' ') && (prev_c == ' '));
            /* do not print two consecutive spaces */
        else
            putchar(c);
        prev_c = c;
    }
}
