#include <stdio.h>

/* copy input to output; 1st version */

int main(){
    /* Note: we use and int instead of a char, since the EOF is not a char code */
    int c;

    c = getchar();
    while(c != EOF){
        putchar(c);
        c = getchar();
    }
}
