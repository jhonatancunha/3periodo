#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "tabelahash_end_aberto.h"

#define Max(a, b)  (a > b) ? a : b

THEA* THEA_Criar(int m){
  THEA *th = malloc(sizeof(m));
  th->m = m;
  th->n = 0;

  ELEMENTO* nos = calloc(m, sizeof(ELEMENTO));
  th->TH = nos;
  for(int i = 0; i < m; i++) th->TH[i].estado = LIVRE;

  return th;
}

int THEA_Inserir(THEA* TH, int chave, int valor){
  int k = 0;
  int hash = THEA_Hash(TH, chave, k);
  int hash_inicial = hash;
  int flag = 0;
  
  while(TH->TH[hash].estado == OCUPADO){
    if(TH->TH[hash].chave == chave){
      flag = 1;
      break;
    }
    
    hash = THEA_Hash(TH, chave, ++k);
    if(hash == hash_inicial) return -1;
  }

  if(!flag) TH->n++;
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

  TH->n--;
  TH->TH[hash].estado = APAGADO;
}

void THEA_Print(THEA *TH){
  for(int i = 0; i < TH->m; i++){
    char estado;    
    if(TH->TH[i].estado == OCUPADO)
      estado = 'O';
    else if(TH->TH[i].estado == LIVRE)
      estado = 'L';
    else
      estado = 'A';
    printf("%d: %d, %c\n", i, TH->TH[i].chave, estado);
  }
}

int THEA_ClusterMaximo(THEA* TH){
  int maximo = 0;
  int maior = -1;
  for(int i = 0; i < TH->m; i++){
    if(TH->TH[i].estado == OCUPADO) maximo++;
    else  maximo = 0;
    if(maximo > maior) maior = maximo;
  }

  return maior;
}

float THEA_TamMedioClusters(THEA* TH){
  int tamanho = 0;
  int qtdClusters = 1;
  for(int i = 0; i < TH->m; i++){
    if(TH->TH[i].estado == OCUPADO) tamanho++;
    else if(TH->TH[i-1].estado == OCUPADO)  qtdClusters++;
  }

  return (float)tamanho/qtdClusters;
}

float THEA_CustoBemSucedida(THEA *TH){
  int *T = calloc(TH->m, sizeof(int));
  int indice_cluster = 0;
  int tam_cluster = 0;

  for(int i = 0; i < TH->m; i++){
    if(TH->TH[i].estado == OCUPADO) tam_cluster++;
    else if(TH->TH[i-1].estado == OCUPADO){
      T[indice_cluster++] = tam_cluster;
      tam_cluster = 0;
    }
  }

  if(indice_cluster == 0 && tam_cluster > 0)
    T[indice_cluster++] = tam_cluster;

  
  float custo = 0;
  for(int i = 0; i < indice_cluster; i++)
    custo += (Max((T[i]/2), 1));

  return ((float)1/TH->n)*custo;
}

int min(THEA* TH){
  int menor = INT_MAX;

  for(int i = 0; i < TH->m; i++)
    if(TH->TH[i].estado == OCUPADO)
      if(TH->TH[i].chave < menor)
        menor = TH->TH[i].chave;
  
  return menor;
}

int max(THEA* TH){
  int maior = INT_MIN;

  for(int i = 0; i < TH->m; i++)
    if(TH->TH[i].estado == OCUPADO)
      if(TH->TH[i].chave > maior)
        maior = TH->TH[i].chave;
  
  return maior;
}

int* random_vector(int n, int max, int seed){
  int *v = calloc(n, sizeof(int));
  srand(seed);

  for(int i = 0; i < n; i++)
    v[i] = rand() % max;

  return v;
}

THEA* THEA_CriaRandom(int m, int n, int max, int seed){
  THEA* random = THEA_Criar(m);
  int *chave = random_vector(n, max, seed);

  for(int i = 0; i < n; i++){
    THEA_Inserir(random, chave[i], chave[i]);
  }

  return random;
}
