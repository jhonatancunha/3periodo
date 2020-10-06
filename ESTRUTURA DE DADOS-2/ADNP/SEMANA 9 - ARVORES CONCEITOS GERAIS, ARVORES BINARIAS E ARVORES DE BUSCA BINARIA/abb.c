#include <stdlib.h>
#include <stdio.h>
#include "abb.h"

AB* ABB_Criar(int chave, AB* esq, AB* dir){
  AB* arvore = malloc(sizeof(AB));
  arvore->chave = chave;
  arvore->dir = dir;
  arvore->esq = esq;

  return arvore;
}

AB* ABB_Busca(AB *arvore, int chave){
  if(arvore == NULL) return NULL;

  if(chave == arvore->chave) return arvore;

  if(chave < arvore->chave)
    return ABB_Busca(arvore->esq, chave);
  else
    return ABB_Busca(arvore->dir, chave);
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

int ABB_Tamanho(AB *arvore){
  if(arvore == NULL) return 0;
  return 1 + ABB_Tamanho(arvore->esq) + ABB_Tamanho(arvore->dir);
}

void ABB_Destruir(AB **arvore){
  if((*arvore) == NULL) return;
  
  ABB_Destruir(&(*arvore)->esq);
  ABB_Destruir(&(*arvore)->dir);
  free(arvore);
}

static void ABB_Remover_No_Folha(AB *pai, AB *folha){

  if(folha->chave < pai->chave)
    pai->esq = NULL;
  else
    pai->dir = NULL;

  free(folha);
}

static void ABB_Remover_No_Filho_Unico(AB *pai, AB *no){
  if(no->chave < pai->chave){
    if(no->esq != NULL)
      pai->esq = no->esq;
    else
      pai->esq = no->dir;
  }else{
    if(no->esq != NULL)
      pai->dir = no->esq;
    else
      pai->dir = no->dir;
  }

  free(no);
}

static void ABB_Remover_No_Dois_Filhos(AB *no){
  AB* sucessor = no->dir;
  AB* pai_sucessor = no;

  while(sucessor->esq != NULL){
    pai_sucessor = sucessor;
    sucessor = sucessor->esq;
  }

  no->chave = sucessor->chave;

  if(sucessor->dir == NULL && sucessor->esq == NULL)
    ABB_Remover_No_Folha(pai_sucessor, sucessor);
  else
    ABB_Remover_No_Filho_Unico(pai_sucessor, sucessor);

}

void ABB_Remover(AB **A, int chave){
  if((*A) == NULL) return;

  AB *no = (*A);
  AB *pai = (*A);
  while(no->chave != chave){
    pai = no;
    if(chave < no->chave)
      no = no->esq;
    else
      no = no->dir;
  }

  if(no->dir == NULL && no->esq == NULL)
    ABB_Remover_No_Folha(pai, no);
  else if(no->dir == NULL || no->esq == NULL)
    ABB_Remover_No_Filho_Unico(pai, no);
  else
    ABB_Remover_No_Dois_Filhos(no);
}

void ABB_Imprimir(AB *arvore, char* caso){
  FILE *texto = fopen(caso, "w");
  imprime_pre_ordem(arvore, 0, 'r', texto);
  fclose(texto);
}

