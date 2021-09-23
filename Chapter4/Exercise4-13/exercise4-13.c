#include <stdio.h>

/* Write a recursive version of the function `reverse(s)`, which reverses the
 * string `s` in place */

void reverse_in_place(char s[]);

int main(){
    char s[] = "Reverse this string";

    printf("Initial string: %s\n", s);
    reverse_in_place(s);
    printf("Reversed string: %s\n", s);
    reverse_in_place(s);
    printf("Reversed back the string: %s\n", s);

    return 0;
}

/* reverse_in_place: reverses the string s in place, recursively */
void reverse_in_place(char s[]){
    int len = 0;
    char start, end;

    /* parse string to get len, start and end chars */
    start = s[0];
    while(s[len] != '\0') /* get string length */
        len++;
    end = s[len-1]; /* get last char */

    /* check for strings with len = 0 or 1 (these don't need reversing) */
    if(len < 2)
        return;

    /* reverse a string without the edges */
    s[len-1] = '\0';
    reverse_in_place(&(s[1])); /* yes, using pointers before chapter 5... */

    /* swap the edges of the string */
    s[0] = end;
    s[len-1] = start;

    return;
}
