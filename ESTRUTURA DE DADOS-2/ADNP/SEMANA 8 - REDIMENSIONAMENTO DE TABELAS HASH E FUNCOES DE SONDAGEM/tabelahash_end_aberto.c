#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "tabelahash_end_aberto.h"

#define Max(a, b)  (a > b) ? a : b

static void THEA_Redimensionar(THEA* TH, int mNovo){
  int m_primo = mNovo;
  if(m_primo <= 15485863) m_primo = PL_NextPrime(TH->prime_list, mNovo);
  ELEMENTO *nova = calloc(m_primo, sizeof(ELEMENTO)); 
  ELEMENTO *antiga = TH->TH;
  int mAntigo = TH->m;
  TH->TH = nova;
  TH->m = m_primo;
  TH->s = m_primo -1;
  TH->n = 0;
  TH->colisoes = 0;

  for(int i = 0; i < m_primo; i++) nova[i].estado = LIVRE;

  for(int i = 0; i < mAntigo; i++)
    if(antiga[i].estado == OCUPADO)
      THEA_Inserir(TH, antiga[i].chave, antiga[i].valor);
  
  free(antiga);
}

THEA* THEA_Criar(int m, FUNC_HASH tipo_hash){
  prime_list_t *primo_list = PL_Load("primes1.dat", 1000000);
  int novo_m = PL_NextPrime(primo_list, m);
  THEA *th = calloc(novo_m, sizeof(THEA));

  th->prime_list = primo_list;
  th->m = novo_m;
  th->n = 0;
  th->colisoes = 0;

  ELEMENTO* nos = calloc(th->m, sizeof(ELEMENTO));
  th->TH = nos;
  for(int i = 0; i < th->m; i++) th->TH[i].estado = LIVRE;

  switch (tipo_hash){
    case HASH_DUPLO:
      th->hash = THEA_HashDuplo;
      th->s = th->m - 1;
      break;
    case HASH_QUADRATICO:
      th->hash = THEA_HashQuadratica;
      break;
    default:
      th->hash = THEA_HashLinear;
      break;
  }

  return th;
}

int THEA_Inserir(THEA* TH, int chave, int valor){
  if((TH->n+1) > (TH->m/2)) THEA_Redimensionar(TH, TH->m * 2);

  int k = 0;
  int hash = THEA_Hash(TH, chave, k);
  int hash_inicial = hash;
  int flag = 0;
  
  while(TH->TH[hash].estado == OCUPADO){
    TH->colisoes++;


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
  return TH->hash(TH, chave, k);
}

int THEA_HashLinear(THEA* TH, int chave, int k){
  return ((chave % TH->m) + k) % TH->m;
}

int THEA_HashQuadratica(THEA* TH, int chave, int k){
  return ((chave % TH->m) + (k*k)) % TH->m;
}

int THEA_HashDuplo(THEA* TH, int chave, int k){
  int m = TH->m;
  return ((chave % m) + k*((chave % TH->s)+1)) % m;
}

int* random_vector(int n, int max, int seed){
  int *v = calloc(n, sizeof(int));
  srand(seed);

  for(int i = 0; i < n; i++)
    v[i] = rand() % max;

  return v;
}

THEA* THEA_CriaRandom(int m, int n, int max, int seed, FUNC_HASH tipo_hash){
  THEA* random = THEA_Criar(m, tipo_hash);
  int *chave = random_vector(n, max, seed);

  for(int i = 0; i < n; i++){
    THEA_Inserir(random, chave[i], chave[i]);
  }

  return random;
}
