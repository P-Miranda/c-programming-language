#include <stdio.h>
#include "syscalls.h"

/* get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n){
    if(lseek(fd, pos, 0) >= 0) /* get to pos */
        return read(fd, buf, n);
    else
        return -1;
}

int main(){
    printf("Check source code for implementation details\n");
    return 0;
}
