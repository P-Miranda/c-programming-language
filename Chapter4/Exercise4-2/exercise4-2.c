#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/* Extend `atof()` to handle scientific notation of the form `123.45e-6` where
 * a floating point number may followed by `e` or `E` and an optionally signed 
 * exponent. */

int main(){
    printf("Exercise 4-2\n");

    double sum, atof(char []);
    char line[MAXLINE];
    int getline_(char line[], int max);

    sum = 0;
    while(getline_(line,MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* getline_: get line into s, return length */
int getline_(char s[], int lim){
    int c, i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if(c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* atof: convert string s to double */
double atof_(char s[]){
    double val, power;
    double exponent, exponent_sign, exponent_power;
    int i, sign;

    for(i=0; isspace(s[i]); i++) /* skip whitespace */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;

    for(val= 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if(s[i] == '.')
        i++;

    for(power=1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    /* handle scientific notation e or E */
    if(s[i] == 'e' || s[i] == 'E'){
        exponent_sign = (s[i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
            i++;

        for(exponent= 0.0; isdigit(s[i]); i++)
            exponent = 10.0 * exponent + (s[i] - '0');

        if(s[i] == '.')
            i++;

        for(exponent_power=1.0; isdigit(s[i]); i++){
            exponent = 10.0 * exponent + (s[i] - '0');
            exponent_power *= 10.0;
        }

        exponent = exponent_sign * exponent / exponent_power;

        /* val x 10^(exponent) */
        /* TODO */
        return sign * val / power * exponent;
    } else {
        /* not scientific notation format */
        return sign * val / power;
    }

    


    return sign * val / power;
}

/* atoi: convert string s to integet using atof */
int atoi(char s[]){
    double atof(char s[]);

    return (int) atof(s);
}
