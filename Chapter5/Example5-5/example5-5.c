#include <stdio.h>

#define STR_LEN 100 /* max string length */

int strcmp_v1(char *s, char *t);
int strcmp_v2(char *s, char *t);

int main(){
    char t1[] = "This is a string";
    char t2[] = "String number 2";
    char t3[] = "Final string?...";
    char t4[] = "...Another one";
    char s[STR_LEN] = {0};

    printf("strcmp_v1(): %d\n\ts: %s\n\tt: %s\n", strcmp_v1(t1, t2), t1, t2);

    printf("strcmp_v2(): %d\n\ts: %s\n\tt: %s\n", strcmp_v2(t2, t3), t2, t3);

    return 0;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp_v1(char *s, char *t){
    int i;

    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp_v2(char *s, char *t){
    for(; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}
