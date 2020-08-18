#include <stdio.h>
#include "heapSort.h"

void print(int *v, int size){
  printf("==============\n");
  for(int i = 0; i < size; i++){
    printf("%d ", v[i]);
    fflush(stdout);
  }
  printf("\n==============\n");
}

int main(int argc, char** argv){
  int heapVetor[8] = {6, 12, 7, 9, 10, 20, 5 ,14};
  print(heapVetor, 8);

  buildMaxHeap(heapVetor, 8);

  print(heapVetor, 8);
  return 0;
}