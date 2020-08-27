#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "countingSort.h"

Info* vetorAleatorio(int size){
    Info *dados = calloc(size, sizeof(Info));

    srand(time(NULL));
    for(int i = 0; i < size; i++){
      dados[i].chave = rand() % size;
      dados[i].dado =  rand() % size;
    }
    
    return dados;
} 

void print(Info *vetor, int size){
  for(int i = 0; i < size; i++){
    printf("VALOR: %d - CHAVE: %d\n", vetor[i].dado, vetor[i].chave);
  }
}


int main(int argc, char** argv){
    Info *vetor = vetorAleatorio(11);
    
    print(vetor, 11);
    countingSort(vetor, 11);

    printf("\n\n");
    print(vetor, 11);
    return 0;
}
