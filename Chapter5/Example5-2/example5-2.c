#include <stdio.h>


int strlen_(char *s);

int main(){
    char s[] = "This is a string";

    printf("Strlen: %d\n", strlen_(s));

    return 0;
}

/* strlen: return length of string s */
int strlen_(char *s){
    int n;

    for(n=0; *s!='\0'; s++)
        n++;
    return n;
}
