#include "syscalls.h"

/* getchar: unbuffered single character input */
int getchat(void){
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF; /* 0: stdin */
}

/* getchar: simple buffered version */
int getchar(void){
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if(n == 0){ /* buffer is empty */
        n = read(0, buf, BUFSIZ);
        bufp = buf;
    }

    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
