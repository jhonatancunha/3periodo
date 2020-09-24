#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_end_aberto.h"

void funcOfTest(int m[], int size){
  int n = 10000;
  int max_var = n*10;
  int seed = 42;

  for(int i = 0; i < size; i++){
    THEA *t = THEA_CriaRandom(m[i], n, max_var, seed);
    printf("M : %d - N: %d - Alpha: %.3f - MAL-SUCEDIDO: %.3f - BEM-SUCEDIDO: %.3f - MAIOR CLUSTER: %d\n\n",
    t->m, t->n, (float)t->n/t->m, THEA_TamMedioClusters(t), THEA_CustoBemSucedida(t), THEA_ClusterMaximo(t));
  }
}

int main(int argc, char** argv){
  // int teste[] = {
  //   9973, 10000, 11987, 12000, 13999, 14000, 15991, 16000, 17989, 
  //   18000, 19997, 20000, 21997, 22000, 23993, 24000, 25999, 26000, 
  //   27997, 28000, 29989, 30000
  // };
  // int size = sizeof(teste)/sizeof(int);
  // funcOfTest(teste, size);
  THEA *t = THEA_Criar(1);
  THEA_Inserir(t, 0, 1);
  THEA_Print(t);

  THEA_Inserir(t, 1, 2);
  THEA_Print(t);

  THEA_Inserir(t, 2, 3);
  THEA_Print(t);
  
  THEA_Inserir(t, 5, 4);

  THEA_Inserir(t, 6, 7);
  THEA_Print(t);
  
  THEA_Inserir(t, 7, 8);
  THEA_Print(t);

  return 0;
}
