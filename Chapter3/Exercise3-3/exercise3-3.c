#include <stdio.h>

#define MAX_LINE 1000

/* Write a function `expand(s1,s2)` that expands shorthand notations like `a-z`
 * in the string s1 into the equivalent compleste list `abc...xyz` in `s2`. 
 * Allow for letters of either case and digits, and be prepared to handle cases
 * like `a-b-c and a-z0-9` and -a-z`. Arrange that a leading of trailing `-` is
 * taken literally. */

/* Auxiliar functions */
int areLetters(char c1, char c2){
    return ((c1>='a') && (c1<='z') && (c2>='a') && (c2<='z'))*(c2-c1);
}

int areCapLetters(char c1, char c2){
    return ((c1>='A') && (c1<='Z') && (c2>='A') && (c2<='Z'))*(c2-c1);
}

int areNumbers(char c1, char c2){
    return ((c1>='0') && (c1<='9') && (c2>='0') && (c2<='9'))*(c2-c1);
}

/* expand: expand shorthand notations for a-z, A-Z and 0-9 */
void expand(char s1[], char s2[]){
    int i = 0, j = 0;
    int diff = 0;
    int expand = 0;

    while(s1[i] != '\0'){
        switch(s1[i]){
        case '-':
            /* check for valid shorthand notation */
            if(i == 0){
                s2[j++] = s1[i];
                break;
            } else if((diff = (areLetters(s1[i-1],s1[i+1]) + areCapLetters(s1[i-1],s1[i+1]) + areNumbers(s1[i-1],s1[i+1])))){
                switch(diff){
                    case 0:
                        i++;
                        break;
                    case 1:
                        s2[j++] = s1[i+1];
                        i++;
                        break;
                    default:
                        if(diff > 0){
                            for(expand = 0; expand < diff-1; expand++){
                                s2[j++] = s1[i-1] + expand + 1;
                            }
                            i++;
                        } else {
                            s2[j++] = s1[i];
                        }
                        break;
                }
            }
            break;
        default: /* by default copy content to string */
            s2[j++] = s1[i];
            break;
        }
        i++;
    }
    s2[j] = '\0';
}



int main(){
    printf("Exercise 3-3\n");
    char s1[] = "a-z0-9";
    char sa[] = "a-a";
    char sb[] = "a-b";
    char sc[] = "b-a";
    char s2[MAX_LINE];

    printf("Original: %s\n", s1);
    expand(s1,s2);
    printf("Expanded: %s\n", s2);

    printf("Original: %s\n", sa);
    expand(sa,s2);
    printf("Expanded: %s\n", s2);

    printf("Original: %s\n", sb);
    expand(sb,s2);
    printf("Expanded: %s\n", s2);

    printf("Original: %s\n", sc);
    expand(sc,s2);
    printf("Expanded: %s\n", s2);
    return 0;
}
