#include <stdio.h>

#define STR_LEN 100 /* max string length */

/* Write versions of the library functions `strncpy_()`, `strncat_()` and 
 * `strncmp_()`, which operate on at most the first n characters of their 
 * argument strings. For example, `strncpy_(s, t, n)` copies at most n characters
 * of t to s. Full descriptions are in Appendix B. */

char *strncpy_(char *s, char *t, int n);
char *strncat_(char *s, char *t, int n);
int strncmp_(char *s, char *t, int n);

int main(){
    char s_cpy[STR_LEN];
    char t[] = "This is string t";
    char s[STR_LEN] = "I'm string s!";
    char s_small[] = "small string";
    char s_a[] = "aaaazzzz";
    char s_b[] = "aaaabbbb";
    char s_c[] = "aaaaZZZZ";

    /* strncpy */
    printf("strncpy_(): %s\n", strncpy_(s_cpy, t, 3));
    printf("strncpy_(): %s\n", strncpy_(s_cpy, t, 30));

    /* /1* strncat *1/ */
    /* printf("strncat_(): %s\n", strncat_(s, t, 4)); */
    /* printf("strncat_(): %s\n", strncat_(s, t, 20)); */

    /* /1* s != t and s >= t *1/ */
    /* printf("strncmp_(%s, %s, %d): %d\n",s_a, s_b, 4, strncmp_(s_a, s_b, 4)); */
    /* printf("strncmp_(%s, %s, %d): %d\n",s_a, s_b, 10, strncmp_(s_a, s_b, 10)); */
    /* printf("strncmp_(%s, %s, %d): %d\n",s_a, s_c, 4, strncmp_(s_a, s_c, 4)); */
    /* printf("strncmp_(%s, %s, %d): %d\n",s_a, s_c, 10, strncmp_(s_a, s_c, 10)); */

    return 0;
}


/* strncpy_(): copy at most n characters of string t to s; return s. Pad with 
 * '\0's if t has fewer than n characters. */
char * strncpy_(char *s, char *t, int n){
    char *s_aux = s;
    int i = 0;
    printf("strcpy start\n");

    for(i=0; t[i]!='\0' && i<n; i++){
        s[i] = t[i];
        printf("%d: %s\n", i, s);
    }

    /* for(; (*s_aux++ = *t++) && n; n--){ */
    /*     printf("%d: %s\n", n, s); */
    /* } */
    
    printf("strcpy after copy: %s\n", s);
    while(i<n){
        s[i++] = '\0';
    }

    printf("strcpy terminate string\n");

    return s;
}

/* strncat_(): concatenate at most n characters of string t to end of s, 
 * terminate s with '\0's, return s. */
char * strncat_(char *s, char *t, int n){
    /* go to s end */
    while(*s != '\0')
        s++;
    /* copy t after s */
    while((*s++ = *t++) && n--)
        ;
    /* terminate string */
    *s = '\0';
    return s;
}

/* strncmp_(): compare at most n characters of string t to string s; return <0 if
 * s<t, 0 if s==t, or >0 if s>t. */
int strncmp_(char *s, char *t, int n){
    for(; (*s == *t) && n; s++, t++, n--)
        if(*s == '\0')
            return 0;
    return *s - *t;
}

