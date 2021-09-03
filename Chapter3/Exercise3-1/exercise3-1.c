#include <stdio.h>

/* Our binary search makes two tests inside the loop, when one would suffice 
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 * */

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high){
        mid = (low+high)/2;
        if(x < v[mid])
            high = mid-1;
        else if(x > v[mid])
            low = mid+1;
        else /* found match */
            return mid;
    }
    return -1; /* found no match */
}

/* binsearch_1test: only one test inside the loop */
int binsearch_1test(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high){
        mid = (low+high)/2;
        if(x < v[mid])
            high = mid-1;
        else 
            low = mid+1;
    }
    return (x == v[mid]) ? mid : -1;
}

int main(){
    printf("Exercise 3-1\n");

    return 0;
}
