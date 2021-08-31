#include <stdio.h>

#define MAX_LINE (100)

/* Write the function `any(s1, s2)`, which returns the first location in the 
 * string `s1` where any character from the string `s2` occurs, or -1 if `s1`
 * contains no characters from `s2`. (The standard library function `strpbrk`
 * does the same job but returns a pointer to the location. */

int any(char s1[], char s2[]){
    int idx = -1;
    int i = 0;
    int j = 0;

    /* check all characters in s2 */
    for(i = 0; s2[i] != '\0'; ++i){
        j = 0;
        /* check for char in s1 */
        while(s1[j++] != '\0')
            if((s1[j] == s2[i]) && ((idx < 0) || j < idx))
                idx = j;
    }
    return idx;
}

int main(){
    printf("Exercise2-5\n");

    int idx = 0;
    char s1[] = "O carro do meu chefe tem um furo no pneu.";

    char s2[] = "o";
    char s3[] = "oa";
    char s4[] = "carro";

    
    printf("Original: %s\n", s1);

    idx = any(s1, s2);
    printf("any: %s: %d\n", s2, idx);
    idx = any(s1, s3);
    printf("any: %s: %d\n", s3, idx);
    idx = any(s1, s4);
    printf("any: %s: %d\n", s4, idx);

    return 0;
}

