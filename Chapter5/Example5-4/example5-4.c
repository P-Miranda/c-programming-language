#include <stdio.h>

#define STR_LEN 100 /* max string length */

void strcpy_v1(char *s, char *t);
void strcpy_v2(char *s, char *t);
void strcpy_v3(char *s, char *t);
void strcpy_v4(char *s, char *t);

int main(){
    char t1[] = "This is a string";
    char t2[] = "String number 2";
    char t3[] = "Final string?...";
    char t4[] = "...Another one";
    char s[STR_LEN] = {0};

    strcpy_v1(s, t1);
    printf("strcpy_v1(): Copied string: %s\n", s);

    strcpy_v2(s, t2);
    printf("strcpy_v2(): Copied string: %s\n", s);

    strcpy_v3(s, t3);
    printf("strcpy_v3(): Copied string: %s\n", s);

    strcpy_v4(s, t4);
    printf("strcpy_v4(): Copied string: %s\n", s);

    return 0;
}

/* strcpy: copy t to s; array subscript version */
void strcpy_v1(char *s, char *t){
    int i;
    i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

/* strcpy: copy t to s; pointer version 1 */
void strcpy_v2(char *s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy_v3(char *s, char *t){
    while((*s++ = *t++) != '\0')
        ;
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy_v4(char *s, char *t){
    while(*s++ = *t++)
        ;
}
