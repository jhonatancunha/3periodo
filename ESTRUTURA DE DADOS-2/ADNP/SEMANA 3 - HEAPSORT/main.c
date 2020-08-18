#include <stdio.h>

void troca(int *v, int pos1, int pos2){
  int n1 = vetor[pos2];
  vetor[pos2] = vetor[pos1];
  vetor[pos1] = n1;
}

int esq(i) return 2*i+1;

int dir(i) return esq(i)+1;

void maxHeapify(int *v, int i, int sizeOfHeap){
  int e, d;
  int maior = i;
  e = esq(i);
  d = dir(i);
  if((e < sizeOfHeap) && (v[e] > v[i])){
    maior = e;
  }
  if((d < sizeOfHeap) && (v[d] > v[maior])){
    maior = d;
  }

  if(maior != i){
    troca(v, i, maior)
  }

  maxHeapify(v, maior, sizeOfHeap);
}

int main(int argc, char** argv){
  return 0;
}