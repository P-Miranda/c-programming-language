#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line_from_terminal(char line[], int maxline);
void reverse(char s[]);

/* Write a function `reverse(s)` that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time. */

int main(){
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = get_line_from_terminal(line, MAXLINE)) > 0) {
        printf("%s", line);
        reverse(line);
        printf("%s", line);
    }

    return 0;    
}

/* get_line_from_terminal */

int get_line_from_terminal(char s[], int lim){
    int c, i;

    for(i=0; (c=getchar()) != EOF && c!='\n'; ++i)
        if( i < (lim-1))
            s[i] = c;

    if(c == '\n'){
        if(i < (lim-1)){
            s[i] = c;
            ++i;
            s[i] = '\0';
        }
        else {
            s[lim-1] = '\0';
            i = lim-1;
        }
    }

    return i;
}

/* reverse: reverse a string */
void reverse(char s[]){
    int len = 0;
    int i = 0, aux = 0;
    // get string length
    while(s[len]!= '\0'){
        len++;
    } 

    //swap from start to len/2
    for(i=0; (i < len/2) && (len>1); i++){
        aux = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = aux;
    }

    return;
}

