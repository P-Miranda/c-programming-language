#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

/* Add access to library functions like sin, exp and pow. See `math.h` in 
 * Appendix B, Section 4. */

/*
 * - print top element ?
 * - duplicate top element !
 * - swap top 2 elements ~
 * - clear the stack \
 * - sin s
 * - exp e 
 * - pow p
 * */

int getop(char s[]);
void print_top(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(){
    int type;
    double op2, op1, res;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%': /* Euclidian implementation (sorry Knuth https://en.wikipedia.org/wiki/Modulo_operation) */
                op2 = pop();
                if(op2 == 0.0){
                    printf("error: mod with zero divisor\n");
                    break;
                }
                op1 = pop();
                res = op1 / op2;
                if(res >= 0.0)
                    push((double)((int) res));
                else
                    push((double)((int) res) + 1.0);
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 'p':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '?':
                print_top();
                break;
            case '!':
                duplicate_top();
                break;
            case '~':
                swap_top();
                break;
            case '\\':
                clear_stack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* print_top: print top element of the stack */
void print_top(void){
    if(sp > 0)
        printf("Stack top: %f\n", val[sp-1]);
    else
        printf("Stack top: <empty>\n");
    return;
}

/* duplicate_top: duplicate top element of the stack */
void duplicate_top(void){
    if(sp > 0)
        push(val[sp-1]);
    else
        printf("Stack empty: cannot duplicate\n");
    return;
}

/* swap_top: swap top two elements of the stack */
void swap_top(void){
    double temp;
    if(sp > 1){
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    } else
        printf("Error: too few items to swap\n");
    return;
}

/* clear_stack: clear stack */
void clear_stack(void){
    sp = 0;
    return;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
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
        ungetch(c);

    return NUMBER;
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


































