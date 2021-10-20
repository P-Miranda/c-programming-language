#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

/* Modify the sort program to handle a `-r` flag, which indicates sorting in 
 * reverse (decreasing) order. Be sure that `-r` works with `-n`. */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(void *, void *);

/* sort input lines */
int main(int argc, char *argv[]){
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0; /* 1 if reverse order */
    int c;

    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
                case 'r':
                    reverse = 1;
                    break;
                case 'n':
                    numeric = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    break;
            }

    printf("Line sort: Reverse %d\t Numeric %d\n", reverse, numeric);

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort_((void *) lineptr, 0, nlines-1, numeric ? numcmp : strcmp, reverse);
        writelines(lineptr, nlines);
        return 0;
    } else{
        printf("input too big to sort\n");
        return 1;
    }
}

/* qsort_: sort v[left]...v[right] into increasing order */
void qsort_(void *v[], int left, int right, int (*comp)(void *, void *), int reverse){
    int i, last;
    void swap(void *v[], int, int);

    if(left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */

    swap(v, left, (left + right)/2);
    last = left;
    for(i = left+1; i<= right; i++)
        if(reverse^((*comp)(v[i], v[left]) < 0))
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_(v, left, last-1, comp, reverse);
    qsort_(v, last+1, right, comp, reverse);
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(void *s1, void *s2){
    double v1, v2;
    v1 = atof((char*)s1);
    v2 = atof((char*)s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j){
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

#define MAXLEN 1000 /* max length of any input line */
int getline_(char*, int);
char *alloc(int n); /* return pointer to n characters */

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLINES];

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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
    int i;
    for(i = 0; i < nlines; i++){
        printf("%d: %s\n", i, lineptr[i]);
    }
}

/* writelines: write output lines (alternative version) */
void writelines_(char *lineptr[], int nlines){
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
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
