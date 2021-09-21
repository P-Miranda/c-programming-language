#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

/* An alternate organization uses `getline_` to read an entire input line; this
 * makes `getch` and `ungetch` unnecessary. Revise the calculator to use this
 * approach */

/*
 * - print top element ?
 * - duplicate top element !
 * - swap top 2 elements ~
 * - clear the stack \
 * - sin s
 * - exp e 
 * - pow p
 * - variables Cappital letters (A, B, C... P: last printed)
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
    double value = 0;
    if(sp > 0) {
        value = val[sp-1];
        printf("Stack top: %f\n", value);
    } else
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

#define MAXLINE (100)
char buf[MAXLINE]; /* buffer line */
int bufp = 0; /* buffer pointer */

void getline_(void);

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;

    /* try to get line if necessary */
    getline_();

    /* TODO: getop needs to manage the bufp pointer */

    while((s[0] = c = buf[bufp++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if(!isdigit(c) && c != '.')
        return c; /* not a number */
    
    i = 0;
    if(isdigit(c)) /* collect integer part */
        while(isdigit(s[++i] = c = buf[bufp++]))
            ;
    
    if(c == '.') /* collect fraction part */
        while(isdigit(s[++i] = c = buf[bufp++]))
            ;

    s[i] = '\0';

    if(c != EOF)
        bufp--;

    return NUMBER;
}

int buflen = 0; /* length of current line in buffer */

void getline_(void){

    /* check if current line has chars to be read */
    if(bufp < buflen){
        return; /* do nothing */
    } else {
        /* read new line */
        bufp = 0;
        buflen = 0;
        /* read characters until new line */
        while(((buf[buflen++] = getchar()) != '\n') && (buflen < MAXLINE));
        buf[buflen] = '\0'; /* terminate string */
        return;
    }
}
