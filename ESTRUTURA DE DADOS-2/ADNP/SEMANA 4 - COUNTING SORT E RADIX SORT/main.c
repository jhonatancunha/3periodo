#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "countingSort.h"
#include "radixSort.h"
#include <string.h>


Info* vetorAleatorio(int size){
    Info *dados = calloc(size, sizeof(Info));

    srand(time(NULL));
    for(int i = 0; i < size; i++){
      dados[i].chave = rand() % size;
      dados[i].dado =  rand() % size;
    }
    
    return dados;
} 

void print(int *vetor, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", vetor[i]);
  }

  printf("\n\n");
}


int main(int argc, char** argv){

    clock_t t;

    int n = 500000;
    int *v = random_vector(n, n*100, 0);
    
    t = clock();
    radixSort_bin(v, n);
    t = clock() - t;
    printf("It took %f miliseconds for radixSort base 2\n", ((float)t/CLOCKS_PER_SEC));

    v = random_vector(n, n*100, 0);
    t = clock();
    radixSort(v, n);
    t = clock() - t;
    printf("It took %f miliseconds for radixSort base 10\n", ((float)t/CLOCKS_PER_SEC));
    return 0;
}
