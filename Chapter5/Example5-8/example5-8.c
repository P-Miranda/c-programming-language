#include <stdio.h>


void echo_1(int argc, char*argv[]);
void echo_2(int argc, char*argv[]);

/* echo command line arguments; 1st version */
int main(int argc, char *argv[]){
    int i;

    echo_1(argc, argv);
    echo_2(argc, argv);

    return 0;
}

/* echo command line arguments: 1st version */
void echo_1(int argc, char*argv[]){
    int i;

    for(i=1; i<argc; i++)
        printf("%s%s", argv[i], (i<argc-1) ? " " : "");
    printf("\n");
    return;
}

/* echo command line arguments: 2nd version */
void echo_2(int argc, char*argv[]){
    while(--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return;
}
