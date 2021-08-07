#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* Write a program that prints its input one word per line */

int main(){
    int c, prev_c;

    prev_c = -1;
    
    while((c = getchar()) != EOF){
        if( (c == ' ' || c == '\t') && !(prev_c == ' ' || prev_c == '\t'))
            putchar('\n');
        else if(c != ' ' && c != '\t') /* only print if is not whitespace */
            putchar(c);
        prev_c = c;
    }
}
