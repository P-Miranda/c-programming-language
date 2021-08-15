#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the ihstogram with the bars horizontal; a vertical 
 * orientation is more challenging. */ 

int main(){
    int c, i, nwhite, nother;
    int ndigit[10];
    int h_tick, max_count;

    nwhite = nother = 0;
    for(i=0; i<10; ++i)
        ndigit[i] = 0;

    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9')
            ndigit[c-'0']++;
        else if(c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits =");
    for(i=0; i<10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

    // Print horizontal histogram of counters
    for(i=0; i<10; i++){
        printf("%2d | ", ndigit[i]);
        for(h_tick=0; h_tick<ndigit[i]; ++h_tick)
            printf(".");
        printf("\n");
    }
    printf("nw | ");
    for(h_tick=0; h_tick<nwhite; ++h_tick)
        printf(".");
    printf("\n");
    printf("no | ");
    for(h_tick=0; h_tick<nother; ++h_tick)
        printf(".");
    printf("\n");

    // Print vertical histogram of counters

    // get max height
    max_count = 0;
    for(i=0; i<10; i++)
        if(ndigit[i] > max_count)
            max_count = ndigit[i];
    if(nwhite > max_count)
        max_count = nwhite;
    if(nother > max_count)
        max_count = nother;

    printf("max count: %d\n", max_count);
    /* // print from top to bottom */
    for(; max_count>0; --max_count){
        for(i=0; i<10; ++i){
            if(ndigit[i] >= max_count)
                printf(".\t");
            else
                printf(" \t");
        }

        if(nwhite >= max_count)
            printf(".\t");
        else
            printf(" \t");
        if(nother >= max_count)
            printf(".\t");
        else
            printf(" \t");

        printf("\n");
    }
        
    // print x axis
    for(i=0; i<90; ++i){
        printf("-");
    }
    printf("\n");
    for(i=0; i<10; ++i){
        printf("%2d\t", i);
    }
    printf("nw\tno\n");
}
