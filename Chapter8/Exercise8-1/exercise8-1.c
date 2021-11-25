#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/* #include <stdlib.h> */

#define READ_FLAG (0)
#define WRITE_FLAG (1)

int fopen_(char *fname, int rw);

/* cat: concatenate files, version 2 */
int main(int argc, char *argv[]){
    int *fd;
    void filecopy(FILE*, FILE*);
    char *prog = argv[0]; /* program name for errors */

    if(argc == 1) /* no args; copy standard input */
        filecopy(stdin, stdout);
    else
        while(--argc > 0)
            if((fd = fopen_(*++argv, READ_FLAG)) == -1){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy_(fd, stdout);
                fclose_(fd);
            }
    if(ferror(stdout)){
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }

    exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp){
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

#defile PERMS 0666  /* RW for owner, group, others */

/* fopen_: low level implementation of fopen */
int fopen_(char *fname, int rw){
    if(rw == READ_FLAG)
        return open(fname, O_RDONLY, 0);
    else if(rw == WRITE_FLAG)
        return creat(fname, PERMS);
    else
        return -1;
}

/* fclose_: low level implementation of fclose */
void fclose_(int fd){
    /* TODO */
}

/* TODO
 * complete fclose_
 * fwrite_
 * test */
