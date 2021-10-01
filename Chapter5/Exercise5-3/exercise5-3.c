#include <stdio.h>

#define STR_LEN 100 /* max string length */

/* Write a pointer version of the function `strcat` that we showd in Chapter2:
 * `strcat(s,t)` copies the string `t` to the end of `s`. */

void strcat_(char *s, char *t);

int main(){
    char t[] = "This is string t";
    char s[STR_LEN] = "I'm string s!";

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    strcat_(s, t);
    printf("strcat(): %s\n", s);

    return 0;
}

/* strcat: concatenate t into s */
void strcat_(char *s, char *t){
    /* go to s end */
    while(*s != '\0')
        s++;
    /* copy t after s */
    while(*s++ = *t++)
        ;
    /* terminate string */
    *s = '\0';
    return;
}
