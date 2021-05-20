#include <stdlib.h>
#include <stdio.h>
#include "teste.h"
#include <time.h>


#include "busca_binaria/abb.h"

void ord_vetor_tree(int* N,int tamN, int qtdVet, int* (cria_vet)(int n), void (ordernar)(int *v, int n, float *altura)){
  for(int i = 0; i < tamN; i++){
    float media_segundos = 0;
    int n = N[i];
    float altura = 0;
    for(int x = 0; x < qtdVet; x++){
      int *v = cria_vet(n);

      time_t inicio = clock();
      ordernar(v, n, &altura);
      free(v);
      media_segundos += (float)(clock()-inicio)/(double)CLOCKS_PER_SEC;
    }
    printf("N: %d - tempo medio: %f - altura media: %f\n", N[i], media_segundos/qtdVet, altura/qtdVet);
  }
}

void letra_i(int* (cria_vet)(int n),int n){
  int *v = cria_vet(n);
  int middle = n/2;
  int esq_i = middle-1;
  int dir_i = middle+1;

  AB *A = NULL;
  ABB_Inserir_Iterativo(&A , v[middle]);
  

  for(int i = 0; i <= middle; i++){
    if(esq_i >= 0) ABB_Inserir_Iterativo(&A , v[esq_i--]);
    if(dir_i < n) ABB_Inserir_Iterativo(&A , v[dir_i++]);
  }

  if(A->dir == NULL) A->hNo = A->esq->hNo+1;
  else if(A->esq == NULL) A->hNo = A->dir->hNo+1;
  else A->hNo = (A->dir->hNo > A->esq->hNo) ? A->dir->hNo+1: A->esq->hNo+1;

  printf("altura %d\n", A->hNo);

  ABB_Sort_Iterativo(A, v,n);
}

int* vetor_decrescente(int n){
  int *v = calloc(n, sizeof(int));
  int aux = n;

  for(int i = 0; i < n; i++) v[i] = aux--;

  return v;
}

int* vetor_random(int n){
  int *v = calloc(n, sizeof(int));
  srand(rand());
  for(int i = 0; i < n; i++) v[i] = rand();

  return v;
}
