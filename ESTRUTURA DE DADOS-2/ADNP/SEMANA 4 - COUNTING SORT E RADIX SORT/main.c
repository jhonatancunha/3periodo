#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "radixSort.h"


int main(int argc, char** argv){
    clock_t t;
    int n = 1000000;

    int *v = random_vector(n, n*100, 0);
    t = clock();
    radixSort_bin(v, n);
    t = clock() - t;
    printf("base 2: %f\n", ((float)t/(CLOCKS_PER_SEC/1000)));
   
    v = random_vector(n, n*100, 0);
    t = clock();
    radixSort(v, n);
    t = clock() - t;
    printf("base 10: %f\n", ((float)t/(CLOCKS_PER_SEC/1000)));

    return 0;
}
