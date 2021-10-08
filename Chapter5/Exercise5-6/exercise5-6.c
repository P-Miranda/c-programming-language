#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max #lines to be sorted */
#define ALLOCSIZE 10000 /* size of available space*/

/* Rewrite `readlines` to stores lines in an array supplied by `main`, rather 
 * than calling `alloc` to maintain storage. How much faster is the program? */

char *lineptr[MAXLINES];/* pointers to text lines */

int readlines(char* lineptr[], int nlines, char* linebuf, int lbufsize);
void writelines(char*lineptr[], int nlines);
void writelines_(char*lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(){
    int nlines; /* number of input lines read */
    char linebuf[ALLOCSIZE]; /* big array to store lines */

    if((nlines = readlines(lineptr, MAXLINES, linebuf, ALLOCSIZE)) >= 0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int getline_(char*, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *linebuf, int lbufsize){
    int len, nlines;
    char *p, line[MAXLINES];
    char *freeline = linebuf;

    nlines = 0;
    while((len = getline_(line, MAXLEN)) > 0)
        if(nlines >= maxlines ||((p = freeline)-linebuf) >= ALLOCSIZE)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            freeline += len; /* update pointer to next free char */
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


/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right) /* do nothing if array contains */
        return;     /* fewer than two elements */
    swap(v, left, (left+right)/2);
    last = left;
    for(i = left+1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j){
    char *temp;

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


