#include <stdio.h>

#define LINE_SIZE (100)
int getline_(char s[], int lim);

/* read dates from stdin */
int main(){
    int day, month, year;
    char monthname[20] = {0};
    char line[LINE_SIZE] = {0};

    while(getline_(line, LINE_SIZE) > 0){
        if(sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line); /* 25 Dec 1988 form */
        else if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line); /* mm/dd/yy form */
        else
            printf("invalid: %s\n", line); /* invalid form */
    }

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
