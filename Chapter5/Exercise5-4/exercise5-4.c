#include <stdio.h>

#define STR_LEN 100 /* max string length */

/* Write the function `strend(s,t)`, which returns 1 if the string `t` occurs at 
 * the end of the string `s`, and zero otherwhise. */

int strend(char *s, char *t);
void strcat_(char *s, char *t);

int main(){
    char t[] = "This is string t";
    char s[STR_LEN] = "I'm string s!";
    char s_small[] = "small string";

    /* s != t and s >= t */
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    printf("strend(s,t): %d\n", strend(s,t));

    /* s ends in t */
    strcat_(s, t);
    printf("strcat(): %s\n", s);
    printf("strend(s,t): %d\n", strend(s,t));

    /* s < t */
    printf("strend(s_small,t): %d\n", strend(s_small,t));

    return 0;
}

/* strend: check for t at the end of s*/
int strend(char *s, char *t){
    char *s_aux = s, *t_aux = t;

    /* go to s end */
    while(*s_aux)
        s_aux++;
    /* go to t end */
    while(*t_aux)
        t_aux++;

    /* check if s >= t */
    if((t_aux - t) > (s_aux - s)){
        printf("error: len(s) < len(t)\n");
        return 0;
    }

    /* compare from end to start */
    while(t_aux >= t){
        if(*t_aux != *s_aux)
            return 0;
        t_aux--;
        s_aux--;
    }

    return 1;
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
