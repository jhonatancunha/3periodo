#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_end_aberto.h"


void funcOfTest(int m[], int size, FUNC_HASH tipo_hash){
  int n = 10000;
  int max_var = n*10;
  int seed = 42;

  for(int i = 0; i < size; i++){
    THEA *t = THEA_CriaRandom(m[i], n, max_var, seed, tipo_hash);
    printf("M : %d - N: %d - Alpha: %.3f - MAL-SUCEDIDO: %.3f - BEM-SUCEDIDO: %.3f - MAIOR CLUSTER: %d\n\n",
    t->m, t->n, (float)t->n/t->m, THEA_TamMedioClusters(t), THEA_CustoBemSucedida(t), THEA_ClusterMaximo(t));
  }
}

int main(int argc, char** argv){
  int m = 5;
  int n = 100;
  int seed = 42;

  THEA *linear;
  THEA *quadratico;
  THEA *duplo;

  printf("\n========= N %d =========\n", n);
  linear = THEA_CriaRandom(m, n, 10*n, seed, LINEAR);
  printf("LINEAR: %d\n", linear->colisoes);
  quadratico = THEA_CriaRandom(m, n, 10*n, seed, HASH_QUADRATICO);
  printf("QUADRATICO: %d\n", quadratico->colisoes);
  duplo = THEA_CriaRandom(m, n, 10*n, seed, HASH_DUPLO);
  printf("DUPLO: %d\n", duplo->colisoes);

  free(linear);
  free(quadratico);
  free(duplo);

  n = 1000;
  printf("\n========= N %d =========\n", n);
  linear = THEA_CriaRandom(m, n, 10*n, seed, LINEAR);
  printf("LINEAR: %d\n", linear->colisoes);
  quadratico = THEA_CriaRandom(m, n, 10*n, seed, HASH_QUADRATICO);
  printf("QUADRATICO: %d\n", quadratico->colisoes);
  duplo = THEA_CriaRandom(m, n, 10*n, seed, HASH_DUPLO);
  printf("DUPLO: %d\n", duplo->colisoes);

  free(linear);
  free(quadratico);
  free(duplo);
  
  n = 10000;
  printf("\n========= N %d =========\n", n);
  linear = THEA_CriaRandom(m, n, 10*n, seed, LINEAR);
  printf("LINEAR: %d\n", linear->colisoes);
  quadratico = THEA_CriaRandom(m, n, 10*n, seed, HASH_QUADRATICO);
  printf("QUADRATICO: %d\n", quadratico->colisoes);
  duplo = THEA_CriaRandom(m, n, 10*n, seed, HASH_DUPLO);
  printf("DUPLO: %d\n", duplo->colisoes);

  free(linear);
  free(quadratico);
  free(duplo);

  n = 100000;
  printf("\n========= N %d =========\n", n);
  linear = THEA_CriaRandom(m, n, 10*n, seed, LINEAR);
  printf("LINEAR: %d\n", linear->colisoes);
  quadratico = THEA_CriaRandom(m, n, 10*n, seed, HASH_QUADRATICO);
  printf("QUADRATICO: %d\n", quadratico->colisoes);
  duplo = THEA_CriaRandom(m, n, 10*n, seed, HASH_DUPLO);
  printf("DUPLO: %d\n", duplo->colisoes);

  free(linear);
  free(quadratico);
  free(duplo);

  n = 1000000;
  printf("\n========= N %d =========\n", n);
  linear = THEA_CriaRandom(m, n, 10*n, seed, LINEAR);
  printf("LINEAR: %d\n", linear->colisoes);
  quadratico = THEA_CriaRandom(m, n, 10*n, seed, HASH_QUADRATICO);
  printf("QUADRATICO: %d\n", quadratico->colisoes);
  duplo = THEA_CriaRandom(m, n, 10*n, seed, HASH_DUPLO);
  printf("DUPLO: %d\n", duplo->colisoes);
   return 0;
}
