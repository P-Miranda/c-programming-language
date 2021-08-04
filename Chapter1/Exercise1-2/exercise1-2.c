#include <stdio.h>

/* 
 * Exercise 1-2: Experiment to find out what happens when printf's argument
 * string contains \c, where c is some character not listed above.
 * (Listed above: \n, \t, \b, \\)
 * */
int main(){
    printf("Exercise 1-2\n");
    printf("\n\n\n");
    /* valid printf escape sequences */
    printf("\a");           /* Alert (Beep, bell)*/
    printf("\b");           /* Backspace */
    printf("\e");           /* Escape character */
    printf("\f");           /* Formfeed Page Break */
    printf("\n");           /* Newline */
    printf("\r");           /* Carriage Return */
    printf("\t");           /* Horizontal Tab */
    printf("\v");           /* Vertical Tab */
    printf("\\");           /* Backslash */
    printf("\'");           /* Apostrophe / single quotation */
    printf("\"");           /* Double quotation */
    printf("\?");           /* Question mark */
    printf("\123");         /* Byte in octal form */
    printf("\xFF");         /* Byte in hexadecimal form */
    printf("\uFFFF");       /* Unicode bellow 10000 hexadecimal */
    printf("\uFFFFFFFF");   /* Unicode in hexadecimal */
    
}
