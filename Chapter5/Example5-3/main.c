#include <stdio.h>
#include "alloc.h"

int main(){
    char *s = 0;
    int i = 0;

    s = alloc(10);

    for(i=0; i<9; i++)
        s[i] = i + '0';
    s[i] = '\0';

    printf("Allocated string: %s\n", s);

    afree(s);

    return 0;
}
