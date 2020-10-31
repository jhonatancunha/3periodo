#include "arn.h"
#include <stdlib.h>

static ARN* ARN_Criar(int chave, int valor){
  ARN *no = malloc(sizeof(ARN));
  no->chave = chave;
  no->valor = valor;
  no->cor = RUBRO;
  no->dir = NULL;
  no->esq = NULL;

  return no;
}

static inline int eh_rubro(ARN *A){
  if(A == NULL) return 0;
  return (A->cor == RUBRO) ? 1 : 0;
}

static void rot_dir(ARN **A){
  ARN *h = *A;
  ARN *x = h->esq;
  
  h->esq = x->dir;
  x->dir = h;
  x->cor = h->cor;
  h->cor = RUBRO;

  *A = x;
}

static void rot_esq(ARN **A){
  ARN *h = *A;
  ARN *x = h->dir;

  h->dir = x->esq;
  x->esq = h;
  x->cor = h->cor;
  h->cor = RUBRO;

  *A = x;
}

static void invercao_cores(ARN *A){
  A->cor = RUBRO;
  A->esq->cor = NEGRO;
  A->dir->cor = NEGRO;
}

void ARN_Inserir_Recursivo(ARN **A, int chave, int valor){
  if(*A == NULL){
    *A = ARN_Criar(chave, valor);
    return;
  }

  if(chave < (*A)->chave) 
    ARN_Inserir_Recursivo(&(*A)->esq, chave, valor);
  if(chave > (*A)->chave)
    ARN_Inserir_Recursivo(&(*A)->dir, chave, valor);

  if(eh_rubro((*A)->dir) && !eh_rubro((*A)->esq)){
    rot_esq(A);
  }
  
  if(eh_rubro((*A)->esq) && eh_rubro((*A)->esq->esq)){
    rot_dir(A);
  }

  if(eh_rubro((*A)->esq) && eh_rubro((*A)->dir)){
    invercao_cores(*A);
  }
}

void ARN_Inserir(ARN **A, int chave, int valor){
  ARN_Inserir_Recursivo(A, chave, valor);
  (*A)->cor = NEGRO;
}

static void ARN_Sort_R(ARN *A, int *v, int *i){
  if(A == NULL) return;
  ARN_Sort_R(A->esq, v, i);
  v[(*i)] = A->chave;
  *i += 1;
  ARN_Sort_R(A->dir, v, i);
  free(A); 
}

void ARN_Sort(int* v, int n){
  ARN *A = NULL;
  for(int i = 0; i < n; i++) ARN_Inserir(&A , v[i], 0);

  int x = 0;
  ARN_Sort_R(A, v, &x);
}
