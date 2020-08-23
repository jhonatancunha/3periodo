#include <stdlib.h>
#include "heapSort.h"
#include <stdio.h>

// FILA DE PRIORIDADE
// MAX HEAPIFY
int FP_inicio(int *fp, int n){
  buildMaxHeap(fp, n);
  return fp[0];
}

int FP_remover_maximo(int* fp, int n){
  troca(fp, 0, n-1);
  maxHeapify(fp, 0, n-1);
  return n-1;
}

int FP_inserir(int* fp, int n, int x){
  int newSize = n+1;
  fp[n] = x;

  while(fp[n] > fp[pai(n)]){
      troca(fp, n, pai(n));
      n = pai(n);
  }

  return newSize;
}

// FILA DE PRIORIDADE
// MIN HEAPIFY
int FP_MIN_inicio(int *fp, int n){
  buildMinHeap(fp, n);
  return fp[0];
}

int FP_MIN_remover(int* fp, int n){
  troca(fp, 0, n-1);
  minHeapify(fp, 0, n-1);
  return n-1;
}

int FP_MIN_inserir(int* fp, int n, int x){
  int newSize = n+1;
  fp[n] = x;

  while(fp[n] < fp[pai(n)]){
      if(n <= 0) break;
      troca(fp, n, pai(n));
      n = pai(n);
  }

  return newSize;
}


int pai(int i){
  return (i-1)/2;
}

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

void minHeapify(int* v, int i, int sizeOfHeap){
  int maior = i;
  int e = esq(i);
  int d = dir(i);


  if((e < sizeOfHeap) && (v[e] < v[i])){
    maior = e;
  }
  if((d < sizeOfHeap) && (v[d] < v[maior])){
    maior = d;
  }
  if(maior != i){
    troca(v, i, maior);
    minHeapify(v, maior, sizeOfHeap);
  }
}

void buildMinHeap(int* v, int size){
  for(int i = size/2; i >= 0; i--){
    minHeapify(v, i, size);
  }
}

void heapSort(int *v, int size){
  buildMaxHeap(v, size);
  for(int i = size-1; i > 0; i--){
    troca(v, 0, i);
    buildMaxHeap(v, i);
  }
}