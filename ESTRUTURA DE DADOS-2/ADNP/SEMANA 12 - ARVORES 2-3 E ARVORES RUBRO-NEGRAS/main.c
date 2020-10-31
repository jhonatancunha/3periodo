#include <stdio.h>
#include <stdlib.h>

#include "rubro_negra/arn.h"
#include "busca_binaria/abb.h"

void imprime_pre_ordem(ARN *arvore, int tabs, char direcao){
  if(arvore == NULL) return;
  for(int i = 0; i < tabs; i++) printf("\t");
  printf("(%c) %d\n",direcao, arvore->chave);
  imprime_pre_ordem(arvore->esq,tabs + 1, 'e');
  imprime_pre_ordem(arvore->dir, tabs + 1, 'd');
}

void  ARN_Imprimir(ARN *arvore){
  imprime_pre_ordem(arvore, 0, 'r');
}

int main(int argc, char** argv){

    int v[] = {50, 20, 30, 5, 1, 99};
    int n = 6;

    ABB_Sort(v, n);
    return 0;
}

