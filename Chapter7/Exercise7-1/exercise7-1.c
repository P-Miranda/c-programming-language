#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Write a program that converts upper case to lower case or lower case to 
 * upper, depending on the name it is invoked with, as found in `argv[0]`. */

/* lower: convert input to lower case */
int main(int argc, char *argv[]){
    int c;

    printf("argv[0]: %s\n", argv[0]);

    if(strcmp(argv[0], "./lower") == 0){
        printf("lower program\n\n");
        while((c = getchar()) != EOF)
            putchar(tolower(c));
    } else if(strcmp(argv[0], "./upper") == 0){
        printf("upper program\n\n");
        while((c = getchar()) != EOF)
            putchar(toupper(c));
    } else {
        printf("Usage:\n");
        printf("\t[Option 1]: ./lower\n");
        printf("\t\tConver to lower case\n");
        printf("\t[Option 2]: ./upper\n");
        printf("\t\tConver to upper case\n");
    }


    return 0;
}

