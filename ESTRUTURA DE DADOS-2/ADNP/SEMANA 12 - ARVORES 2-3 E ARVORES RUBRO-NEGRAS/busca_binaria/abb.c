#include <stdlib.h>
#include <stdio.h>
#include "abb.h"

AB* ABB_Criar(int chave, AB* esq, AB* dir){
  AB* arvore = (AB*) malloc(sizeof(AB));
  arvore->chave = chave;
  arvore->dir = dir;
  arvore->esq = esq;

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

void ABB_Destruir(AB **arvore){
  if((*arvore) == NULL) return;
  
  ABB_Destruir(&(*arvore)->esq);
  ABB_Destruir(&(*arvore)->dir);
  free(arvore);
}


static void ABB_Sort_R(AB *A, int *v, int *i){
  if(A == NULL) return;
  ABB_Sort_R(A->esq, v, i);
  v[(*i)] = A->chave;
  *i += 1;
  ABB_Sort_R(A->dir, v, i);
  free(A); 
}

void ABB_Sort(int* v, int n){
  AB *A = NULL;
  for(int i = 0; i < n; i++) ABB_Inserir(&A , v[i]);

  int x = 0;
  ABB_Sort_R(A, v, &x);
}

