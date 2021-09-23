#include <stdio.h>

/* Recursive implementation of `quicksort()`*/

void qsort(int v[], int left, int right);
void print_values(int v[], int nvalues);

int main(){
    int values[] = {4, 8, 2, 7, 5, 9, 0, 1, 3, 6};
    int nvalues = 10;

    printf("Random values\n");
    print_values(values, nvalues);
    qsort(values, 0, nvalues-1);
    printf("Sorted values\n");
    print_values(values, nvalues);
    return 0;
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[], int left, int right){
    int i, last;
    void swap(int v[], int i, int j);

    if(left >= right) /* do nothing if array contains */
        return;     /* fewer than two elements */
    swap(v, left, (left + right)/2); /* move partition elem */
    last = left;    /* to v[0] */
    for(i = left+1; i<=right; i++){ /* partition */
        if(v[i] < v[left])
            swap(v, ++last, i);
    }
    swap(v, left, last); /* restore partition elem */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j){
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void print_values(int v[], int nvalues){
    int i=0;

    printf("\n");
    for(i=0; i<nvalues; i++)
        printf("[%d] %d\n", i, v[i]);
    printf("\n");
}
