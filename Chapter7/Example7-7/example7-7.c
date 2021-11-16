#include <stdio.h>

int main(int argc, char *argv[]){
    printf("fgets(), fputs() and getline() implementations\n");
    printf("Nothing to run here. Check source file for details\n");
    return 0;
}

/* fgets_: get at most n chars from iop */
char *fgets_(char *s, int n, FILE *iop){
    register int c;
    register char *cs;

    cs = s;
    while(--n > 0 && (c = getc(iop)) != EOF)
        if((*cs++ = c) == '\n')
            break;

    *cs = '\0';
    return (c = EOF && cs == s) ? NULL : s;
}

/* fputs_; put string s on file iop */
int fputs_(char *s, FILE *iop){
    int c;

    while(c = *s++)
        putc(c, iop);
    return ferror(iop) ? EOF : 0;
}

/* get string length */
int strlen_(char s[]){
    int len = 0;
    while(s[len++] != '\0');

    return len-1;
}

/* getline_: read a line, return length */
int getline_(char *line, int max){
    if(fgets_(line, max, stdin) == NULL)
        return 0;
    else
        return strlen_(line);
}
