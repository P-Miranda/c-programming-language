#include <stdio.h>

/* Define a macro `swap(t,a,b)` that interchanges two arguments of type `t`. 
 * (Block structure will help.) */

#define swap(t,a,b) { t aux = a; a = b; b = aux;}

int main(){
    int a=1, b=2;
    char c='A', d='B';
    double e=1.2, f=2.1;

    printf("a: %d\tb: %d\n", a, b);
    swap(int,a,b)
    printf("a: %d\tb: %d\n", a, b);

    printf("c: %c\td: %c\n", c, d);
    swap(char,c,d)
    printf("c: %c\td: %c\n", c, d);

    printf("e: %g\tf: %g\n", e, f);
    swap(double,e,f)
    printf("e: %g\tf: %g\n", e, f);


    return 0;
}

