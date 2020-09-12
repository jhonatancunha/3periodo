#include "tabelahash_ed.h"
#include "list.h"
#include <stdlib.h>

int THED_hash(THED* tabela, int chave){
  return chave % tabela->M;
}

THED* THED_criar(int m, int alloc_step){
  THED* tabela_hash = malloc(sizeof(THED));
  tabela_hash->M = m;
  tabela_hash->tabela = malloc(sizeof(Lista)*m);
}

void THED_inserir(THED* tabela, int chave, int valor){

}

No* THED_buscar(THED* tabela, int chave){
  int h = THED_hash(tabela, chave);

}

int THED_remover(THED* tabela, int chave){

}