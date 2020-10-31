//ARVORE RUBRO NEGRA
#pragma once

typedef enum { RUBRO, NEGRO } Link;

typedef struct ARN{
  struct ARN *esq;
  struct ARN *dir;
  int valor;
  int chave;
  Link cor;
} ARN;

void ARN_Inserir(ARN **A, int chave, int valor);
void ARN_Sort(int* v, int n);