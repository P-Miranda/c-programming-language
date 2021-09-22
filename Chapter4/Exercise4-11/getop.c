#include <stdio.h>
#include <ctype.h> /* for atof() */
#include "calc.h"

/* Modify `getop` so that is doesn't need to use `ungetch`. Hint: use an 
 * internal `static` variable. */

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c = ' ';
    static int stored_c = EOF;

    if (stored_c != EOF){
        c = stored_c;
        stored_c = EOF;
    }

    if((s[0] = c) == ' ' || c == '\t')
        while((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    else
        ;

    s[1] = '\0';
    
    if(!isdigit(c) && c != '.')
        return c; /* not a number */
    
    i = 0;
    if(isdigit(c)) /* collect integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    
    if(c == '.') /* collect fraction part */
        while(isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if(c != EOF)
        stored_c = c;

    return NUMBER;
}
