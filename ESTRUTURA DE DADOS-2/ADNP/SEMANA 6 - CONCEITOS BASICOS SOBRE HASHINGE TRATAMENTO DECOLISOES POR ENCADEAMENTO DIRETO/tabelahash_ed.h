#pragma once

typedef struct THED{
  int M;
  Lista** tabela;
} THED;

THED* THED_criar(int m, int alloc_step);
int THED_hash(THED* tabela, int chave);
void THED_inserir(THED* tabela, int chave, int valor);
No* THED_buscar(THED* tabela, int chave);
int THED_remover(THED* tabela, int chave);