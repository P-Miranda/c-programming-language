#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/* #include <stdlib.h> */

#define READ_FLAG (0)
#define WRITE_FLAG (1)

int fopen_(char *fname, int rw);

/* cat: concatenate files, low level implementation */
int main(int argc, char *argv[]){
    int fd;
    void filecopy_(int, int);
    char *prog = argv[0]; /* program name for errors */

    if(argc == 1) /* no args; copy standard input */
        filecopy_(STDIN_FILENO, STDOUT_FILENO);
    else
        while(--argc > 0)
            if((fd = fopen_(*++argv, READ_FLAG)) == -1){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                return 1;
            } else {
                filecopy_(fd, STDOUT_FILENO);
                close(fd);
            }
    if(ferror(stdout)){
        fprintf(stderr, "%s: error writing stdout\n", prog);
        return 2;
    }

    return 0;
}

/* filecopy_: copy file ifd to file ofd */
void filecopy_(int ifd, int ofd){
    int n;
    char buf;

    while((n = read(ifd, &buf, 1)) > 0)
        write(1, &buf, ofd);

}

#define PERMS 0666  /* RW for owner, group, others */

/* fopen_: low level implementation of fopen */
int fopen_(char *fname, int rw){
    if(rw == READ_FLAG)
        return open(fname, O_RDONLY, 0);
    else if(rw == WRITE_FLAG)
        return creat(fname, PERMS);
    else
        return -1;
}
