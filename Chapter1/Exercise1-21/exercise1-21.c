#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define N_SPACES 4 /* number of spaces that replace a tab */

int retab_from_terminal(char line[], int maxline, int n_spaces);

/* Write a program `entab` that replaces strings of blanks by the minimum number
 * of tabs and blanks to acheive the same spacing. Use the same tab stops as for
 * `detab`. When either a tab or a single blank would suffice to reach a tab 
 * stop, which should be given preference? */


int main(){
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = retab_from_terminal(line, MAXLINE, N_SPACES)) > 0) {
        printf("%s", line);
    }

    return 0;    
}

/* get_line_from_terminal replace tabs by n spaces */
int retab_from_terminal(char s[], int lim, int n_spaces){
    int c, i;
    int space = 0;

    // check for valid inputs
    if(lim <= 0 || n_spaces <= 0){
        printf("Invalid inputs\n");
        return 0;
    }

    for(i=0; (c=getchar()) != EOF && c!='\n'; ++i){
        if( i < (lim-1)){
            // count consecutive spaces
            if(c == ' '){
                s[i] = c;
                space++;
                // replace n_spaces by a tab
                if(space == n_spaces){
                    s[i-n_spaces+1] = '\t';
                    i = i - n_spaces + 1;
                    space = 0;
                }
            } else{
                s[i] = c;
                space = 0;
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
