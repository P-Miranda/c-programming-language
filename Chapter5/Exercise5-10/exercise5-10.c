#include <stdio.h>
#include <stdlib.h> /* for atof() */

/* Write the program `expr`, which evaluates a reverse Polish expression from 
 * the command line, where each operator or operand is a separate argument. For
 * example `expr 2 3 4 + *` evaluates 2 x (3+4) */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char s[], char *arg);
void push(double);
double pop(void);
void print_args(int argc, char* argv[]);


/* reverse Polish calculator */
int main(int argc, char *argv[]){
    int type;
    double op2;
    char s[MAXOP];
    int i = 0;

    print_args(argc, argv);

    for(i=1; i<argc;i++){
        switch(getop(s, argv[i])){
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
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    printf("\t%.8g\n", pop());
    
    return 0;
}

void print_args(int argc, char* argv[]){
    int i = 0;

    printf("%s", argv[0]);
    /* Pring args */
    for(i = 1; i<argc; i++)
        printf(" %s", argv[i]);
    printf("\n");
    return;
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

#include <ctype.h>

void strcpy_(char *s, char *t);

/* getop: get next operator or numeric operand */
int getop(char s[], char *arg){
    int i, c;

    /* copy arg to string */
    strcpy_(s, arg);

    c = s[0];
    
    if(!isdigit(c) && c != '.')
        return c; /* not a number */
    
    return NUMBER;
}

void strcpy_(char *s, char *t){
    while(*s++ = *t++)
        ;
}
