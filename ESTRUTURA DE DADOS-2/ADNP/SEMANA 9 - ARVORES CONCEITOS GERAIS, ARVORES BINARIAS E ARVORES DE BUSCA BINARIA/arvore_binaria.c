#include <stdio.h>
#include "arvore_binaria.h"

void imprime_pre_ordem(AB *arvore, int tabs, char direcao, FILE *texto){
  if(arvore == NULL) return;
  for(int i = 0; i < tabs; i++) fputc('\t', texto);
  fprintf(texto,"(%c) %d\n",direcao, arvore->chave);
  imprime_pre_ordem(arvore->esq,tabs + 1, 'e', texto);
  imprime_pre_ordem(arvore->dir, tabs + 1, 'd', texto);
}

void imprime_em_ordem(AB *arvore){
  if(arvore == NULL) return;
  imprime_em_ordem(arvore->esq);
  printf("%d ",arvore->chave);
  imprime_em_ordem(arvore->dir);
}

void imprime_pos_ordem(AB *arvore){
  if(arvore == NULL) return;
  imprime_pos_ordem(arvore->esq);
  imprime_pos_ordem(arvore->dir);
  printf("%d ",arvore->chave);
}
