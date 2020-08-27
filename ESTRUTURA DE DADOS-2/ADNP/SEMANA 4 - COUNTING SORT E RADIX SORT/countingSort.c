#include <stdlib.h>
#include <string.h>
#include "countingSort.h"

void countingSort(Info *v, int size){
  int k = max(v, size);
  int *c = calloc(k+1, sizeof(int));
  Info *s = calloc(size, sizeof(Info));

  for(int i = 0; i < size; i++){
    int indice = v[i].chave;
    c[indice] += 1;
  }

  int acumulador = 0;
  for(int i = 0; i <= k; i++){
    int t = c[i];
    c[i] = acumulador;
    acumulador += t;
  }

  for(int i = 0; i < size; i++){
    int chave = v[i].chave;
    int indice = c[chave];
    s[indice].dado = v[i].dado;
    s[indice].chave = v[i].chave;
    c[chave]++;
  }

  memcpy(v, s, sizeof(Info) * size);

  free(c);
  free(s);
}

int max(Info *v, int size){
  int maior = v[0].chave;

  for(int i = 1; i < size; i++){
    if(maior < v[i].chave){
      maior = v[i].chave;
    }
  }

  return maior;
}