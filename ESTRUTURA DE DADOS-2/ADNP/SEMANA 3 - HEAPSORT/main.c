#include <stdio.h>
#include "heapSort.h"
#include <stdlib.h>

void print(int *v, int size){
  printf("==============\n");
  for(int i = 0; i < size; i++){
    printf("%d ", v[i]);
    fflush(stdout);
  }
  printf("\n==============\n");
}
// {6, 12, 7, 9, 10, 20, 5 ,14}
int main(int argc, char** argv){
  int *heapVetor = calloc(1000, sizeof(int));
  int n = 0;
  print(heapVetor, n);

  n = FP_inserir(heapVetor, n, 5);
  print(heapVetor, n);

   n = FP_inserir(heapVetor, n, 0);
  print(heapVetor, n);

   n = FP_inserir(heapVetor, n, 8);
  print(heapVetor, n);

  n =FP_remover_maximo(heapVetor, n);
  print(heapVetor, n);

  int bigger = FP_MIN_inicio(heapVetor, n);
  print(heapVetor, n);
  printf("bigger: %d\n", bigger);

  n = FP_MIN_remover_maximo(heapVetor, n);
  print(heapVetor, n);

  n = FP_MIN_inserir(heapVetor, n, 55);
  n = FP_MIN_inserir(heapVetor, n, 1);
  print(heapVetor, n);
  return 0;
}