#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE (10000)

/* Write a program to compare two files, printing the first line where they
 * differ. */

/* TODO:
 * check for 3 arguments
 * check if args 2 and 3 are valid files and can be opened
 * read 1 line at a time from each file
 * compare them
 * if equal next until end
 * if differ
 *      print each file
 *      exit*/

int main(int argc, char *argv[]){
    FILE *fp1 = NULL, *fp2 = NULL;
    size_t len1 = 0, len2 = 0;
    char line1[MAXLINE], line2[MAXLINE];
    char *line1_ptr = line1, *line2_ptr = line2;

    /* check for arguments and open files */
    if(argc < 3){
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(0);
    } else {
        fp1 = fopen(argv[1], "r");
        fp2 = fopen(argv[2], "r");
        if( (fp1 == NULL) || (fp2 == NULL) ){
            fprintf(stderr, "IO Error: Could not open files\n");
            exit(1);
        }
    }

    /* Compare files */
    while( (getline(&line1_ptr, &len1, fp1) != -1) && (getline(&line2_ptr, &len2, fp2) != -1) ){
        if(strcmp(line1_ptr, line2_ptr) != 0){
            fprintf(stdout, ">%s\n", line1_ptr);
            fprintf(stdout, "<%s\n", line2_ptr);

            /* Close files */
            fclose(fp1);
            fclose(fp2);
            exit(1);
        }
    }
    /* Close files */
    fclose(fp1);
    fclose(fp2);

    exit(0);
}
