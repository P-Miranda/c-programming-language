#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Write a program to determine the ranges of `char`, `short`, `int` and `long`
 * variables, both `signed` and `unsigned`, by printing appropriate values from
 * standard headers and by direct comparison. Harder if you compute them: 
 * determine the ranges of the various floating-point types.
 * */

int main(){
    printf("Exercise2-1\n");

    /* Variables */
    char char_cnt = 0, min_char = '0', max_char = '0';
    short int short_cnt = 0, min_short = 0, max_short = 0;
    int int_cnt = 0, min_int = 0, max_int = 0;
    long int long_cnt = 0, min_long = 0, max_long = 0;

    float float_cnt = 0, min_float = 0, max_float = 0;
    double double_cnt = 0, min_double = 0, max_double = 0;

    int char_lap = 0, short_lap = 0;

    /* Iterate thought all values */
    char init_char = '0';
    char_cnt = init_char;
    if(char_cnt > max_char)
        max_char = char_cnt;
    if(char_cnt < min_char)
        min_char = char_cnt;
    char_cnt++;
    while( (char_lap == 0) || (char_cnt < init_char)){
        if(char_cnt > max_char)
            max_char = char_cnt;
        if(char_cnt < min_char)
            min_char = char_cnt;
        char_cnt++;
        if(char_cnt <= 0)
            char_lap = 1;
    }
    printf("Calculated char\n");

    /* Iterate thought all values */
    short init_short = '0';
    short_cnt = init_short;
    if(short_cnt > max_short)
        max_short = short_cnt;
    if(short_cnt < min_short)
        min_short = short_cnt;
    short_cnt++;
    while( (short_lap == 0) || (short_cnt < init_short)){
        if(short_cnt > max_short)
            max_short = short_cnt;
        if(short_cnt < min_short)
            min_short = short_cnt;
        short_cnt++;
        if(short_cnt <= 0)
            short_lap = 1;
    }
    printf("Calculated short\n");

    /* Smarted max value search: Binary search style */
    /* calculate max value */
    int step_int = 1;
    int_cnt = 0;
    while(step_int > 0){
        /* try to increment step */
        while(int_cnt + (step_int<<1) > 0 ){
            step_int = step_int<<1; /* double the step */
        }
        /* small steps loop */
        while(int_cnt + step_int < 0){
            unsigned int step_u = (unsigned int) step_int;
            step_int = (int) (step_u>>1); /* halve the step */
        }
        int_cnt += step_int;
    }
    if(int_cnt > max_int)
        max_int = int_cnt;
    /* calculate min value */
    step_int = 1;
    int_cnt = 0;
    while(step_int > 0){
        /* try to increment step */
        while(int_cnt - (step_int<<1) < 0 ){
            step_int = step_int<<1; /* double the step */
        }
        /* small steps loop */
        while(int_cnt - step_int > 0){
            unsigned int step_u = (unsigned int) step_int;
            step_int = (int) (step_u>>1); /* halve the step */
            /* step_int = step_int>>1; /1* halve the step *1/ */
        }
        int_cnt -= step_int;
    }
    if(int_cnt < min_int)
        min_int = int_cnt;
    printf("Calculated int\n");

        

    /* Smarted max value search: Binary search style */
    /* calculate max value */
    long int step_long = 1;
    long_cnt = 0;
    while(step_long > 0){
        /* try to increment step */
        while(long_cnt + (step_long<<1) > 0 ){
            step_long = step_long<<1; /* double the step */
        }
        /* small steps loop */
        while(long_cnt + step_long < 0){
            unsigned long int step_u = (unsigned long int) step_long;
            step_long = (long int) (step_u>>1); /* halve the step */
        }
        long_cnt += step_long;
    }
    if(long_cnt > max_long)
        max_long = long_cnt;
    /* calculate min value */
    step_long = 1;
    long_cnt = 0;
    while(step_long > 0){
        /* try to increment step */
        while(long_cnt - (step_long<<1) < 0 ){
            step_long = step_long<<1; /* double the step */
        }
        /* small steps loop */
        while(long_cnt - step_long > 0){
            unsigned long int step_u = (unsigned long int) step_long;
            step_long = (long int) (step_u>>1); /* halve the step */
            /* step_long = step_long>>1; /1* halve the step *1/ */
        }
        long_cnt -= step_long;
    }
    if(long_cnt < min_long)
        min_long = long_cnt;
    printf("Calculated long\n");

    /* /1* WIP *1/ */
    /* /1* Max values for float and double *1/ */
    /* /1* Smarted max value search: Binary search style *1/ */
    /* /1* calculate max value *1/ */
    /* float step_float = 1; */
    /* float_cnt = 0; */
    /* while(step_float > 0){ */
    /*     /1* try to increment step *1/ */
    /*     while(float_cnt + (step_float*2) > 0 ){ */
    /*         step_float *= 2; /1* double the step *1/ */
    /*         printf("float_cnt:%f\tstep_float:%f\n", float_cnt, step_float); */
    /*     } */
    /*     /1* small steps loop *1/ */
    /*     while(float_cnt + step_float < 0){ */
    /*         step_float /= 2; */
    /*     } */
    /*     float_cnt += step_float; */
    /* } */
    /* if(float_cnt > max_float) */
    /*     max_float = float_cnt; */
    /* /1* calculate min value *1/ */
    /* step_float = 1; */
    /* float_cnt = 0; */
    /* while(step_float > 0){ */
    /*     /1* try to increment step *1/ */
    /*     while(float_cnt - (step_float*2) < 0 ){ */
    /*         step_float *= 2; /1* double the step *1/ */
    /*     } */
    /*     /1* small steps loop *1/ */
    /*     while(float_cnt - step_float > 0){ */
    /*         step_float /= 2; /1* halve the step *1/ */
    /*     } */
    /*     float_cnt -= step_float; */
    /* } */
    /* if(float_cnt < min_float) */
    /*     min_float = float_cnt; */

        
    printf("Calculated long\n");

    printf("Min char:%d\tMax char:%d\n", min_char, max_char);
    printf("Min short:%d\tMax short:%d\n", min_short, max_short);
    printf("Min int:%d\tMax int:%d\n", min_int, max_int);
    printf("Min long:%ld\tMax long:%ld\n", min_long, max_long);
    
    /* Results from standard headers */
    printf("\n<Limits.h>\n");
    printf("Min char:%d\tMax char:%d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Min short:%d\tMax short:%d\n", SHRT_MIN, SHRT_MIN);
    printf("Min int:%d\tMax int:%d\n", INT_MIN, INT_MAX);
    printf("Min long:%ld\tMax long:%ld\n", LONG_MIN, LONG_MAX);

    printf("\nBonus round:\n");
    printf("Min float:%f\tMax float:%f\n", min_float, max_float);
    printf("Min double:%f\tMax double:%f\n", min_double, max_double);
    return EXIT_SUCCESS;
}

