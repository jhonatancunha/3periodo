#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_end_aberto.h"

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
