// TABELA HASH ENDEREÇAMENTO ABERTO
#pragma once
#include "prime_list.h"

typedef enum FUNC_HASH {
  LINEAR,
  HASH_QUADRATICO,
  HASH_DUPLO
} FUNC_HASH;

typedef enum ESTADO {
  LIVRE,
  OCUPADO,
  APAGADO
} ESTADO;

typedef struct ELEMENTO{
  int chave;
  int valor;
  ESTADO estado;
} ELEMENTO;

typedef struct THEA{
  int m; // TAMANHO TOTAL
  int n; // QUANTIDADE DE POSIÇÕES OCUPADAS
  int s;
  int colisoes;
  ELEMENTO* TH;
  prime_list_t* prime_list;
  int (*hash)(struct THEA* TH, int chave, int k);
} THEA;


// FUNÇÃO QUE CRIA A TABELA DE ENDERAÇAMENTO ABERTO
THEA* THEA_Criar(int m, FUNC_HASH tipo_hash);

// FUNÇÃO DE HASH COM SONDAGEM LINAR
// TRATAMOS A TABELA COMO UMA LISTA CIRCULAR
int THEA_Hash(THEA* TH, int chave, int k);
int THEA_HashLinear(THEA* TH, int chave, int k);
int THEA_HashQuadratica(THEA* TH, int chave, int k);
int THEA_HashDuplo(THEA* TH, int chave, int k);

// FUNÇÃO DE INSERÇÃO DE VALORES E CHAVES DENTRO DA TABELA HASH
int THEA_Inserir(THEA* TH, int chave, int valor);


int* random_vector(int n, int max, int seed);
THEA* THEA_CriaRandom(int m, int n, int max, int seed, FUNC_HASH tipo_hash);

