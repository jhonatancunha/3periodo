#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "countingSort.h"
#include "radixSort.h"

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
    // Info *vetor = vetorAleatorio(11);
    
    // print(vetor, 11);
    // countingSort(vetor, 11);

    // printf("\n\n");
    // print(vetor, 11);

    int size = 9;
    int v[9] = {104, 114, 134, 34, 204, 107, 77, 89, 99};
    print(v, size);
    radixSort(v, size);
    print(v, size);
    return 0;
}
