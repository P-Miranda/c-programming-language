#include <stdio.h>

#define N_CHARS 128
/* Write a program to print a histogram of the frequencies of different 
 * characters in its input. */

int main(){
    int c, i, nextended;
    int c_counter[N_CHARS];
    int h_tick, max_count;

    for(i=0; i<N_CHARS; ++i)
        c_counter[i] = 0;

    while((c = getchar()) != EOF){
        if( c < N_CHARS)
            c_counter[c]++;
        else
            nextended++;
    }

    // Print horizontal histogram of counters
    printf("ch# | %%c | <frequency>\n");
    for(i=0; i<N_CHARS; i++){
        printf("%3d | %c | ", i, i);
        for(h_tick=0; h_tick<c_counter[i]; ++h_tick)
            printf(".");
        printf("\n");
    }
    // Extended ASCII codes
    printf("nex | %c | ", i);
    for(h_tick=0; h_tick<nextended; ++h_tick)
        printf(".");
    printf("\n");

}
