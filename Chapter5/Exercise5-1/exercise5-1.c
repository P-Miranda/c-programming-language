#include <stdio.h>
#define SIZE 15 /* maximum number of values to get */

/* As written, `getint` treats a `+` or `-` not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input */


/* find all lines matching pattern */
int main(){
    int n, array[SIZE] = {0}, getint(int *);
    int i = 0;

    for(n=0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    /* print found values */
    for(i = 0; i < n ; i++)
        printf("array[%d]: %d\n", i, array[i]);
    
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn){
    int c, sign;

    while(isspace(c = getch())) /*skip white space */
        ;
    
    if(!isdigit(c) && c != EOF && c != '+' && c != '+' && c != '-'){
        /* ungetch(c); /1* it's not a number *1/ */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-'){
        c = getch();
        if(!isdigit(c)){ /* + or - followed by non-digit character */
            ungetch(c);
            *pn = 0;
            return 0;
        }
    }

    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    printf("getint: %d\n", *pn);

    if(c != EOF)
        ungetch(c);

    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void){ /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){ /* push character back on input */
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
