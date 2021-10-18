#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define MAX_NLINES (200)
#define DEFAULT_NLINES (10)

/* Write the program `tail`, which prints the last `n` lines of its input. By 
 * default, `n` is 10, let us say, but it can be changed by an optional 
 * argument, so that `tail -n` prints the last `n` lines. The program should
 * behave retionally no matter how unreasonable the input of the value of `n`.
 * Write the program so it makes the best use of available storage; lines should
 * be stored as in the sorting program of section 5.6, not in a two-dimensional
 * array of fixed size. */

int readlines(char *lineptr[], int maxlines);
int atoi(char s[]);

int main(int argc, char *argv[]){
    char *line_ptr[MAX_NLINES] = {0};
    int n_lines = 10, n_lines_arg = 0;
    char c = 0;
    int lineno = 0;
    int idx = 0;

    /* check command line arguments */
    while(--argc > 1 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
                case 'n':
                    if( (n_lines_arg = atoi(argv[1])) > 0)
                        n_lines = (n_lines_arg > MAX_NLINES) ? MAX_NLINES : n_lines_arg;
                    else
                        n_lines = DEFAULT_NLINES;
                    break;
                default:
                    printf("tail: illegal option %c\n", c);
                    argc = 0;
                    break;
            }

    /* get lines from input */
    if(argc > 1)
        printf("Usage: tail [-n <nlines>]\n");
    else
        if((lineno = readlines(line_ptr, MAX_NLINES)) >= 0){
            /* Print last nlines */
            printf("\n\n");
            if(lineno < n_lines)
                n_lines = lineno;
            for(idx = lineno - n_lines; idx < lineno; idx++)
                printf("%s\n", line_ptr[idx]);
        }

    return 0;
}

#define MAXLEN 1000 /* max length of any input line */
int getline_(char*, int);
char *alloc(int n); /* return pointer to n characters */

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while((len = getline_(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
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

/* atoi: convert s to integer */
int atoi(char s[]){
    int i, n;
    n = 0;
    for(i=0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

#define ALLOCSIZE 10000 /* size of available space*/

void afree(char *p); /* free storage pointed to by p */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n){ /* return pointer to n characters */
    if(allocbuf + ALLOCSIZE - allocp >= n){ /* if fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough space */
        return 0;
}

void afree(char *p){ /* free storage pointed to by p */
    if( p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
