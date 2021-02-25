#pragma once

typedef struct AB{
  struct AB *esq;
  struct AB *dir;
  int chave;
  
  struct AB *pai;
  int hNo;
}AB;

// FUNÇÃO QUE CRIA NÓ EM ARVORE BINÁRIA
AB* ABB_Criar(int chave, AB* esq, AB* dir);

// FUNÇÃO QUE INSERE CHAVE NA ARVORE BINÁRIA
void ABB_Inserir(AB **arvore, int chave);
void ABB_Inserir_Iterativo(AB **T, int chave);

// FUNÇÃO QUE DESALOCA TODOS OS NÓS DA ARVORE
void ABB_Destruir(AB **arvore);

void ABB_Sort(int* v, int n , float *altura);

int ABB_Altura(AB *A);
void ABB_Sort_Iterativo(AB *A, int *v, int n);