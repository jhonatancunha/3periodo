#include "heapSort.h"

void troca(int *vetor, int pos1, int pos2){
  int n1 = vetor[pos2];
  vetor[pos2] = vetor[pos1];
  vetor[pos1] = n1;
}

int esq(int i){
  return 2*i+1;
}

int dir(int i) {
  return esq(i)+1;
}

void maxHeapify(int *v, int i, int sizeOfHeap){
  int maior = i;
  int e = esq(i);
  int d = dir(i);


  if((e < sizeOfHeap) && (v[e] > v[i])){
    maior = e;
  }
  if((d < sizeOfHeap) && (v[d] > v[maior])){
    maior = d;
  }
  if(maior != i){
    troca(v, i, maior);
    maxHeapify(v, maior, sizeOfHeap);
  }
}

void buildMaxHeap(int *v, int size){
  for(int i = size/2; i >= 0; i--){
    maxHeapify(v, i, size);
  }
}
