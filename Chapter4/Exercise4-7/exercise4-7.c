#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define VARIABLE 'A' /* signal that a variable was found */

/* Write a routine `ungets(s)` that will push back an entire string onto the 
 * input. Should `ungets` know about `buf` and `bufp`, or should it just use 
 * `ungetch`? */

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

/* TODO 
 * add support for capital letters in getop()
 * add case for capital letters
 * add vector for variables and functions to work with it
 * automate storing last printed number into P variable
 * */

int getop(char s[]);
void print_top(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);
void push(double);
double pop(void);

void variable_init(void);
void variable_operation(char s[]);
void variable_store_last_printed(double value);

int strlen_(char s[]);
/* reverse Polish calculator */
int main(){
    int type;
    double op2, op1, res;
    char s[MAXOP];

    variable_init();

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case VARIABLE:
                variable_operation(s);
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
                op1 = pop();
                variable_store_last_printed(op1);
                printf("\t%.8g\n", op1);
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
        variable_store_last_printed(value);
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

int getch(void);
void ungetch(int);
void ungets(char s[]);
int is_capital_letter(char c);

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if(is_capital_letter(c)) /* check for variable */
        return VARIABLE;

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

int is_capital_letter(char c){
    return (c >= 'A' && c <= 'Z');
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

void ungets(char s[]){ /* push string back on input */
    int len = strlen_(s);
    int i = 0;
    if(bufp + len >= BUFSIZE)
        printf("ungets: string does not fit buffer\n");
    else
        for(i = 0; i < len; i++)
            buf[bufp++] = s[i];
}

/* Variable operations */
#define LAST_PRINTED 'P' /* name for variable to store last printed value */
#define N_VARIABLES ('Z'-'A'+1) /* number of variables */

double variable_array[N_VARIABLES]; /* structure with variables */

double variable_get(int var);
void variable_store_stack_top(int var);
void variable_store_value(int var, double value);

void variable_init(void){
    int i = 0;
    for(i=0; i< N_VARIABLES; i++)
        variable_array[i] = 0.0;
    return;
}

/* if var == LAST_PRINTED print last printed value
 * if var == 0: save top of stack to variable
 * if var != 0: print variable
 * */
void variable_operation(char s[]){
    int var = s[0];
    switch(var){
        case LAST_PRINTED:
            printf("Last printed: %f\n", variable_get(LAST_PRINTED));
            break;
        default:
            printf("var default\n");
            if(variable_get(var) == 0.0){
                variable_store_stack_top(var);
            } else {
                printf("%c: %f\n",(char) var, variable_get(var));
            }
            break;
    }
    return; 
}

void variable_store_stack_top(int var){
    int idx = var - VARIABLE;
    double value = 0;
    if(idx >= 0 && idx < N_VARIABLES){
        value = pop();
        push(value);
        variable_array[idx] = value;
    } else
        printf("Error: invalid variable\n");
    return;
}

void variable_store_value(int var, double value){
    int idx = var - VARIABLE;
    if(idx >= 0 && idx < N_VARIABLES){
        variable_array[idx] = value;
    } else
        printf("Error: invalid variable\n");
    return;
}

double variable_get(int var){
    int idx = var - VARIABLE;
    if(idx >= 0 && idx < N_VARIABLES){
        return variable_array[idx];
    } else {
        printf("Error: invalid variable\n");
        return 0.0;
    }
}

void variable_store_last_printed(double value){
    variable_store_value(LAST_PRINTED, value);
    return;
}

int strlen_(char s[]){
    int len = 0;
    while(s[len++] != '\0');
    return len;
}
