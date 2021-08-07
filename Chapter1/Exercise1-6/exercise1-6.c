#include <stdio.h>

/* Verify that the expression getchar() != EOF is 0 or 1 */

int main(){
    int c;

    while( c = (getchar() != EOF) ){
        printf("C: %d\n", c);
    }
    /* print last comparison value in case of false */
    printf("C: %d\n", c);
}
