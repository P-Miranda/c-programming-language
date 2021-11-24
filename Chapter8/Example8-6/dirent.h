#define NAME_MAX 30     /* longest filename component */
#define DIRSIZ (NAME_MAX+1)  /* use dirent name size as default */ 


/* system dependent */

typedef struct{ /* portable directory entry */
    long ino;       /* inode number */
    char name[NAME_MAX+1];  /* name + '\0' terminator */
} Dirent;

typedef struct{ /* minimal DIR_: no buffering, etc */
    int fd;     /* file descriptor for directory */
    Dirent d;   /* the directory entry */
} DIR_;

DIR_ *opendir_(char *dirname);
Dirent *readdir_(DIR_ *dfd);
void closedir_(DIR_ *dfd);
