#include <stdlib.h>
#include <stdio.h>
#include "tabelahash_end_aberto.h"

THEA* THEA_Criar(int m){
  THEA *th = malloc(sizeof(m));
  th->m = m;

  ELEMENTO* nos = calloc(m, sizeof(ELEMENTO));
  th->TH = nos;
  for(int i = 0; i < m; i++) th->TH[i].estado = LIVRE;

  return th;
}

int THEA_Inserir(THEA* TH, int chave, int valor){
  int k = 0;
  int hash = THEA_Hash(TH, chave, k);
  int hash_inicial = hash;
  
  while(TH->TH[hash].estado == OCUPADO){
    if(TH->TH[hash].chave == chave) break;
    
    hash = THEA_Hash(TH, chave, ++k);
    if(hash == hash_inicial) return -1;
  }

  TH->TH[hash].valor = valor;
  TH->TH[hash].chave = chave;
  TH->TH[hash].estado = OCUPADO;
  return hash;
}

int THEA_Hash(THEA* TH, int chave, int k){
  return ((chave % TH->m) + k) % TH->m; 
}

int THEA_Busca(THEA* TH, int chave){
  int k = 0;
  int hash = THEA_Hash(TH, chave, k);
  int hash_inicial = hash;

  while(TH->TH[hash].estado != LIVRE){
    if(TH->TH[hash].chave == chave && TH->TH[hash].estado == OCUPADO) return hash;
    hash = THEA_Hash(TH, chave, ++k);
    if(hash_inicial == hash) break;
  }
  
  return -1;
}

void THEA_Remover(THEA* TH, int chave){
  int hash = THEA_Busca(TH, chave);
  if(hash == -1) return;

  TH->TH[hash].estado = APAGADO;
}

void THEA_Print(THEA *TH){
  for(int i = 0; i < TH->m; i++){
    char estado;    
    if(TH->TH[i].estado == OCUPADO){
      estado = 'O';
    }else if(TH->TH[i].estado == LIVRE){
      estado = 'L';
    }else{
      estado = 'A';
    }
    printf("%d: %d, %c\n", i, TH->TH[i].chave, estado);
  }
}
