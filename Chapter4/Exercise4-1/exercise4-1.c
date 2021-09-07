#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

/* Write the function `strrindex(s,t)` which returns the position of the 
 * rightmost occurence of `t` in `s`, or -1 if there is none. */

int strlen_(char s[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

int main(){
    printf("Exercise 4-1\n");

    char s1[] = "I could try, but would I?";
    int rindex = -3;

    rindex = strrindex(s1, pattern);

    printf("Found pattern at index %d\n", rindex);
    
    return 0;
}

/* get string length */
int strlen_(char s[]){
    int len = 0;
    while(s[len++] != '\0');

    return len-1;
}

/* strrindex: return index of rightmost occurence of t in s, -1 if none */
int strrindex(char s[], char t[]){
    int i, j, k;

    for(i = strlen_(s)-1; s[i] != '\0'; i--){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k] && s[j-1] != '\0'; j++, k++)
            ;
        
        if(k>0 && t[k] == '\0')
            return i;
    }
    return -1;
}
