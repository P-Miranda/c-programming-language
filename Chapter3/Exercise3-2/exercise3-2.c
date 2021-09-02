#include <stdio.h>

#define MAX_LINE 1000

/* Write a function `escape(s, t)` that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string `t` to 
 * `s`. Use a `switch`. Write a function for the other direction as well, 
 * converting escape sequences into the real characters. */

/* escape: convert white space to visible escape sequences */
void escape(char s[], char t[]){
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){
        switch(s[i]){
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
        i++;
    }
    t[j] = '\0';
    return;
}

/* unescape: convert visible escape sequences to white space */
void unescape(char s[], char t[]){
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){
        switch(s[i]){
            case '\\':
                switch(s[i+1]){
                    case 't':
                        t[j++] = '\t';
                        i++;
                        break;
                    case 'n':
                        t[j++] = '\n';
                        i++;
                        break;
                    default:
                        t[j++] = s[i];
                        break;
                }
                break;
            default:
                t[j++] = s[i];
                break;
        }
        i++;
    }
    t[j] = '\0';
    return;
}

int main(){
    printf("Exercise 3-2\n");
    char s[] = "This\tis\na test string\n";
    char t[MAX_LINE];
    char v[MAX_LINE];

    printf("Original: %s\n", s);
    escape(s, t);
    printf("Escaped: %s\n", t);
    unescape(t, v);
    printf("UnEscaped: %s\n", v);

    return 0;
}
