#include <stdio.h>

/* Write a program to count blanks, tabs and newlines */

int main(){
    int c, nl, nt, nb;

    nl = 0;
    nt = 0;
    nb = 0;

    while((c = getchar()) != EOF){
        if(c == '\n')
            ++nl;
        if(c == ' ')
            ++nb;
        if(c == '\t')
            ++nt;
    }
    printf("Newlines:%d\n", nl);
    printf("Tabs:%d\n", nt);
    printf("Blanks:%d\n", nb);
}
