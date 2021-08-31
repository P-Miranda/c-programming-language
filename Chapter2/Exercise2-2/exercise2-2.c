#include <stdio.h>

#define MAX_LINE (100)

/* Write a loop equivalent to the `for` loop above without using `&&` or `||` */

int main(){
    printf("Exercise2-2\n");

    int i = 0;
    int lim = MAX_LINE;
    char s[MAX_LINE];
    char s_new[MAX_LINE];
    int c = 0;

    /* Original for loop */
    for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    s[i] = '\0';

    printf("Original: %s\n", s);
    c = 0;

    /* Loop without && or || */
    for(i=0; (i< lim-1) * ( (c = getchar()) != '\n' ) * (c != EOF); ++i)
        s_new[i] = c;
    s_new[i] = '\0';

    printf("New: %s\n", s_new);

    return 0;
}

