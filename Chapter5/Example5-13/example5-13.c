#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXSTRING 200

/* Some examples to input:
 * x () * [] * () * char
 *      char (*(*x())[])()
 * meaning: "x is a function returnign a pointer to an array of pointers to 
 *          functions returning char"
 * */

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;  /* type of last token */
char token[MAXTOKEN];   /* last token string */
char name[MAXTOKEN];    /* identifier name */
char datatype[MAXTOKEN];/* data type = char, int, etc. */
char out[MAXTOKEN]; /* output string */

/* convert word description to declaration */
int main(int argc, char *argv[]){
    int type;
    char temp[MAXSTRING];

    while(gettoken() != EOF){
        strcpy(out, token);
        while((type = gettoken()) != '\n')
            if(type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if(type == '*'){
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if(type == NAME){
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
        printf("%s\n", out);
    }
    return 0;
}

int getch(void); /* get a (possibly pushed back) character */
void ungetch(int c); /* push character back on input */

/* gettoken: return next token */
int gettoken(void){
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while((c = getch()) == ' ' || c == '\t')
        ;

    if(c == '('){
        if((c = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if(c == '[') {
        for(*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if(isalpha(c)) {
        for(*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else 
        return tokentype = c;
}


#include <stdio.h>

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
