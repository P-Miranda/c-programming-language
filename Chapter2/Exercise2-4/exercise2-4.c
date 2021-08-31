#include <stdio.h>

#define MAX_LINE (100)

/* Write an alterante version of `squeeze(s1, s2)` that deletes each character
 * in `s1` that matches any character in the string `s2`. */

void squeeze(char s1[], char s2[]){
    char c, del_c;
    int i = 0, j = 0;
    int k = 0;
    
    /* check all s2 characters */
    while((del_c = s2[k++]) != '\0'){
        /* delete a char from s1 */
        i = j = 0;
        while((c = s1[j++]) != '\0')
            if(c != del_c)
                s1[i++] = c;
        /* terminate string */
        s1[i] = '\0';
    }

    return;
}

int main(){
    printf("Exercise2-4\n");

    char s1[] = "O carro do meu chefe tem um furo no pneu.";

    char s2[] = "o";
    char s3[] = "oa";
    char s4[] = "carro";

    
    printf("Original: %s\n", s1);

    squeeze(s1, s2);
    printf("squeeze: %s: %s\n", s2, s1);
    squeeze(s1, s3);
    printf("squeeze: %s: %s\n", s3, s1);
    squeeze(s1, s4);
    printf("squeeze: %s: %s\n", s4, s1);

    return 0;
}

