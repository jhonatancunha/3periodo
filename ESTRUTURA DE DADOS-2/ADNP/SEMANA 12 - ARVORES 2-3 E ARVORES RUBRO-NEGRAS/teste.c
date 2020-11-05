#include <stdlib.h>
#include "teste.h"

int* vetor_decrescente(int n){
  int *v = calloc(n, sizeof(int));
  int aux = n;

  for(int i = 0; i < n; i++) v[i] = aux--;

  return v;
}

int* vetor_random(int n, int seed){
  int *v = calloc(n, sizeof(int));
  srand(rand() % seed);
  for(int i = 0; i < n; i++) v[i] = rand();

  return v;
}
