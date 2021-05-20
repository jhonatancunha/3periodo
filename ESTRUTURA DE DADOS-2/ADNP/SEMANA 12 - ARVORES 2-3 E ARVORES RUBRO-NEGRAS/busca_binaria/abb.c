#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "abb.h"

AB* ABB_Criar(int chave, AB* esq, AB* dir){
  AB* arvore = (AB*) malloc(sizeof(AB));
  arvore->chave = chave;
  arvore->dir = dir;
  arvore->esq = esq;
  arvore->hNo = 0;

  return arvore;
}

void ABB_Inserir(AB **arvore, int chave){
  if((*arvore) == NULL){
    *arvore = ABB_Criar(chave, NULL, NULL);
    return;
  }else{
    if((*arvore)->chave > chave)
      ABB_Inserir(&(*arvore)->esq, chave);
    else
      ABB_Inserir(&(*arvore)->dir, chave);
  }
}

void ABB_Inserir_Iterativo(AB **T, int chave){
  if(*T == NULL) *T = ABB_Criar(chave, NULL, NULL);
  int i = 0;
  AB **aux = T;
  AB *pai = *aux;

  while(*aux != NULL){
    if(chave > (*aux)->chave) {
      pai = *aux;
      aux = &(*aux)->dir;
    }else if (chave < (*aux)->chave){
      pai = *aux;
      aux = &(*aux)->esq;
    }
    else return;
  }
  
  *aux = ABB_Criar(chave, NULL, NULL);
  (*aux)->pai = pai;

  if(pai->dir == NULL || pai->esq == NULL){
    pai->hNo += 1;
    while(pai != (*T)){
      pai = pai->pai;
      pai->hNo += 1;
    }
  }else if(pai->esq->hNo != pai->dir->hNo){
    pai->hNo +=1;
    while(pai != (*T)){
      pai = pai->pai;
      pai->hNo += 1;
    }
  }
}

void ABB_Destruir(AB **arvore){
  if((*arvore) == NULL) return;
  
  ABB_Destruir(&(*arvore)->esq);
  ABB_Destruir(&(*arvore)->dir);
  free(arvore);
}

int ABB_Altura(AB *A){
  if(A == NULL) return -1;

  int alt_d = ABB_Altura(A->dir);
  int alt_e = ABB_Altura(A->esq);

  if(alt_e < alt_d)
    return alt_d+1;
  else
    return alt_e+1;
}

void ABB_Sort_Iterativo(AB *A, int *v, int n){
  AB **fila = calloc(n, sizeof(AB));
  AB *aux;
  int x = 1;
  int i = 0;
  int z = n-1;
  fila[0] = A;

  while(x > i){
    aux = fila[i++];
    v[n--] = aux->chave;
    if(aux ->esq != NULL) fila[x++] = aux->esq;
    if(aux ->dir != NULL) fila[x++] = aux->dir;
    free(fila[i-1]);
  }

  free(fila);
}

void ABB_Sort(int* v, int n, float *altura){
  AB *A = NULL;
  for(int i = 0; i < n; i++)  ABB_Inserir_Iterativo(&A , v[i]);
  
  if(A->dir == NULL) A->hNo = A->esq->hNo+1;
  else if(A->esq == NULL) A->hNo = A->dir->hNo+1;
  else A->hNo = (A->dir->hNo > A->esq->hNo) ? A->dir->hNo+1: A->esq->hNo+1;


  *altura += A->hNo;
  ABB_Sort_Iterativo(A, v, n);
}
