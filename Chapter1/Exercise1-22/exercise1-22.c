#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define N_SPACES 4 /* number of spaces that replace a tab */
#define COL_LIMIT 20 /* max folded line width */

int fold_from_terminal(char line[], int maxline, int line_limit);

/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of 
 * input. Make sure your program does something intelligent with very long 
 * lines, and if there are no blanks or tabs before the specified column. */


int main(){
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = fold_from_terminal(line, MAXLINE, COL_LIMIT)) > 0) {
        printf("%s", line);
    }

    return 0;    
}

/* get_line_from_terminal fold long lines */
int fold_from_terminal(char s[], int lim, int line_limit){
    int c, i;
    int last_whitespace = 0;
    int line_width = 0;

    // check for valid inputs
    if(lim <= 0 || line_limit <= 0){
        printf("Invalid inputs\n");
        return 0;
    }

    for(i=0, last_whitespace = -1, line_width = 0; (c=getchar()) != EOF && c!='\n'; ++i, ++line_width){
        if( i < (lim-1)){
            // save last white space
            if(c == ' '|| c == '\t'){
                last_whitespace = i;
            } 
            s[i] = c;
            // check for too wide lines
            if(line_width >= line_limit){
                if(last_whitespace >= 0){
                    s[last_whitespace] = '\n';
                    // already count chars after last whitespace
                    line_width = i-last_whitespace; 
                    last_whitespace = -1;
                }
            }
        }
    }

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
