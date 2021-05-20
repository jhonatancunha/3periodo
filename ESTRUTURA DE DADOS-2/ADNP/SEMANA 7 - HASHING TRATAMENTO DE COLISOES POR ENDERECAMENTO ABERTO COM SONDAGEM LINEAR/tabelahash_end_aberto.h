// TABELA HASH ENDEREÇAMENTO ABERTO
#pragma once

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
  ELEMENTO* TH;
} THEA;


// FUNÇÃO QUE CRIA A TABELA DE ENDERAÇAMENTO ABERTO
THEA* THEA_Criar(int m);

// FUNÇÃO DE HASH COM SONDAGEM LINAR
// TRATAMOS A TABELA COMO UMA LISTA CIRCULAR
int THEA_Hash(THEA* TH, int chave, int k);

// FUNÇÃO DE INSERÇÃO DE VALORES E CHAVES DENTRO DA TABELA HASH
int THEA_Inserir(THEA* TH, int chave, int valor);

// FUNÇÃO QUE BUSCA DETERMINADA CHAVE NA TABELA HASH
int THEA_Busca(THEA* TH, int chave);

// FUNÇÃO QUE REMOVE UM ELEMENTO DADO UM DETERMINADA CHAVE
// REMOVER É O MESMO QUE COLOCAR O ELEMENTO COMO APAGADO
void THEA_Remover(THEA* TH, int chave);

// IMPRIME TODA A TABELA HASH DE ENDERAÇAMENTO ABERTO
void THEA_Print(THEA *TH);

int THEA_ClusterMaximo(THEA* TH);
float THEA_TamMedioClusters(THEA* TH);
float THEA_CustoBemSucedida(THEA *TH);
int* random_vector(int n, int max, int seed);
THEA* THEA_CriaRandom(int m, int n, int max, int seed);

int min(THEA* TH);
int max(THEA* TH);
