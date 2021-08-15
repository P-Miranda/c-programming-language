#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define CHAR_THRESHOLD 80 /* lines over this size will be printed */

int print_lines_over_threshold(char line[], int maxline);

/* Write a program to print all input lines that are longer than 80 characters.*/

int main(){
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while((len = print_lines_over_threshold(line, MAXLINE)) > 0);

    return 0;    
}

/* print_lines_over_threshold: read a line into s, return length */
int print_lines_over_threshold(char s[], int lim){
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
        else
            s[lim-1] = '\0';
    }
    // print if is over 80 chars
    if(i > CHAR_THRESHOLD)
        printf("%s", s);
    return i;
}

