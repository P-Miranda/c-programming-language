#include <stdio.h>

#define MAX_LINE (100)

/* Rewrite the function `lower`, which converts upper case letter to lower case,
 * with a conditional expression instead of `if-else` */


/* lower: convert c to lower case; ASCII only */
int lower(int c){
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}


/* lower_conditional: convert c to lower case; ASCII only */
int lower_conditional(int c){
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}


int main(){
    printf("Exercise2-10\n");
    char x = 'G';
    char y = 'i';

    
    printf("x: %c\t lower:%c\tlower_conditional:%c\n", x, lower(x), lower_conditional(x));
    printf("y: %c\t lower:%c\tlower_conditional:%c\n", y, lower(y), lower_conditional(y));
    return 0;
}

