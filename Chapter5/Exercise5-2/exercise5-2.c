#include <stdio.h>
#define SIZE 15 /* maximum number of values to get */

/* Write `getfloat`, the floating-point analog of `getint`. What type does
 * `getfloat` return as its function value?*/


/* find all lines matching pattern */
int main(){
    int n;
    float array_f[SIZE] = {0.0};
    int getfloat(float *);
    int i = 0;

    for(n=0; n < SIZE && getfloat(&array_f[n]) != EOF; n++)
        ;

    /* print found values */
    for(i = 0; i < n ; i++)
        printf("array_f[%d]: %f\n", i, array_f[i]);
    
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(float *pn){
    int c, sign;
    float decimal_exp = 0.0;

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

    /* integer value */
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if(c == '.'){ 
        c = getch();
        if(!isdigit(c)){ /* '.' followed by non-digit character */
            ungetch(c);
        } else {
            /* decimal value */
            for(decimal_exp=10; isdigit(c); c = getch(), decimal_exp*=10)
                *pn = *pn + (1.0*(c - '0')/decimal_exp);
        }
    }

    *pn *= sign;

    printf("getfloat: %f\n", *pn);

    if(c != EOF)
        ungetch(c);

    return c;
}

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
