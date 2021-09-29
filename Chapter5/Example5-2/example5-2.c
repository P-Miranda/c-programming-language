#include <stdio.h>


int strlen_v1(char *s);
int strlen_v2(char *s);

int main(){
    char s[] = "This is a string";

    printf("Strlen_V1: %d\n", strlen_v1(s));
    printf("Strlen_V2: %d\n", strlen_v2(s));

    return 0;
}

/* strlen: return length of string s. Pointer version. */
int strlen_v1(char *s){
    int n;

    for(n=0; *s!='\0'; s++)
        n++;
    return n;
}

/* strlen: return length of string s. Pointer arithmetic version. */
int strlen_v2(char *s){
    char *p = s;

    while(*p != '\0')
        p++;
    return p-s;
}
