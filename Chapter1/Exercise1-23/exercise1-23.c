#include <stdio.h>

/* Write a program to remove all comments from a C program. Don't forget to 
 * handle quoted strings and character constants properly. C comments do not 
 * nest.*/


int main(){
    int c = 0;
    int prev_c = 0;
    int inside_comment = 0;
    int ignore_char = 0;

    while(prev_c != EOF){
        // read char
        if(c != EOF)
            c = getchar();

        // check for comment start
        if(prev_c == '/' && c == '*' && inside_comment == 0){
            inside_comment = 1;
        }

        // print prev char
        if(inside_comment == 0 && ignore_char == 0)
            printf("%c",prev_c);

        ignore_char = 0;
        // check for comment end
        if(prev_c == '*' && c == '/' && inside_comment == 1){
            inside_comment = 0;
            ignore_char = 1;
        }
        // update prev char
        prev_c = c;
    }

    return 0;    
}

