#include <stdio.h>
#include "tabelahash_end_aberto.h"

int main(int argc, char** argv){
  THEA *t = THEA_Criar(10);

  THEA_Inserir(t, 10, 10);
  THEA_Inserir(t, 21, 21);
  THEA_Inserir(t, 44, 44);
  THEA_Inserir(t, 32, 32);
  THEA_Inserir(t, 12, 12);
  THEA_Inserir(t, 37, 37);
  THEA_Inserir(t, 43, 43);
  printf("===========\n");

  THEA_Print(t);

  printf("maior cluster: %d\n", THEA_ClusterMaximo(t));
  printf("tamanho medio cluster: %.2f\n", THEA_TamMedioClusters(t));
  printf("menor chave: %d\n", min(t));
  printf("maior chave: %d\n", max(t));

  // printf("===========\n");
  // printf("3? %d\n", THEA_Busca(t, 3));
  // printf("10? %d\n", THEA_Busca(t, 10));
  // printf("7? %d\n", THEA_Busca(t, 7));
  // printf("37? %d\n", THEA_Busca(t, 37));
  // printf("43? %d\n", THEA_Busca(t, 43));
  // printf("44? %d\n", THEA_Busca(t, 44));
  // printf("===========\n");

  // THEA_Remover(t, 44);
  // THEA_Print(t);
  
  // printf("===========\n");
  // printf("44? %d\n", THEA_Busca(t, 44));
  // printf("43? %d\n", THEA_Busca(t, 43));
  // printf("===========\n");
  return 0;
}
