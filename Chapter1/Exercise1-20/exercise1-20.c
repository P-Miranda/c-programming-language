#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define N_SPACES 4 /* number of spaces that replace a tab */

int detab_from_terminal(char line[], int maxline, int n_spaces);

/* Write a program `detab` that replaces tabs in the input with the proper 
 * number of blanks to space to the nest tab stop. Assum a fixed set of tab 
 * stops, say every n columns. Should n be a variable or a symbolic parameter?*/


int main(){
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = detab_from_terminal(line, MAXLINE, N_SPACES)) > 0) {
        printf("%s", line);
    }

    return 0;    
}

/* get_line_from_terminal replace tabs by n spaces */
int detab_from_terminal(char s[], int lim, int n_spaces){
    int c, i;
    int space = 0;

    // check for valid inputs
    if(lim <= 0 || n_spaces <= 0){
        printf("Invalid inputs\n");
        return 0;
    }

    for(i=0; (c=getchar()) != EOF && c!='\n'; ++i){
        if( i < (lim-1)){
            // check for tab
            if(c == '\t'){
                // add n_spaces
                for(space = 0; space < n_spaces; space++){
                    s[i + space] = ' ';
                }
                i = i + n_spaces - 1;
            } else{
                s[i] = c;
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
