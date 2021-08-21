#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int remove_trailing_whitespace(char line[], int maxline);

/* Write a program to remove trailing blanks and tabs from each line of input, 
 * and to delete entirely blank lines */

int main(){
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = remove_trailing_whitespace(line, MAXLINE)) > 0) {
        printf("%s", line);
    }

    return 0;    
}

/* remove_trailing_whitespace: remove trailing whitespace at the end of each 
 * line and empty lines */

int remove_trailing_whitespace(char s[], int lim){
    int c, i;
    int line_len = 0;

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
    line_len = i;

    /* Re-read line from end to start to remove spaces and tabs */
    while(i>=0) {
        // get char
        c = s[i];
        // check for whitespace
        if(c == '\0' || c == '\n' || c == ' ' || c == '\t') {
            // remove char
            s[i] = '\0';
        }
        else {
            // terminate line with \n
            s[i+1] = '\n';
            // last non-whitespace character - we can print line
            break;
        }
        --i;
    }
    return line_len;
}

