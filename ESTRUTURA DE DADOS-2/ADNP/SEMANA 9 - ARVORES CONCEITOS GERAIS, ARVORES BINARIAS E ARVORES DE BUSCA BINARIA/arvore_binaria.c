#include <stdio.h>
#include "arvore.h"

void imprime_pre_ordem(AB *A){
  if(A == NULL) return;
  printf("%d ",A->chave);
  imprime_em_ordem(A->esq);
  imprime_em_ordem(A->dir);
}

void imprime_em_ordem(AB *A){
  if(A == NULL) return;
  imprime_em_ordem(A->esq);
  printf("%d ",A->chave);
  imprime_em_ordem(A->dir);
}

void imprime_pos_ordem(AB *A){
  if(A == NULL) return;
  imprime_em_ordem(A->esq);
  imprime_em_ordem(A->dir);
  printf("%d ",A->chave);
}
