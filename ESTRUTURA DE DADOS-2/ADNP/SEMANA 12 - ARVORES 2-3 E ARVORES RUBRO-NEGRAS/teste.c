#include <stdlib.h>
#include "teste.h"

int* vetor_decrescente(int n){
  int *v = calloc(n, sizeof(int));
  int aux = n;

  for(int i = 0; i < n; i++) v[i] = aux--;

  return v;
}
