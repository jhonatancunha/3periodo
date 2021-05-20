#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "radixSort.h"

void counting_sort_bin(int *v, int size, int pos, int *temp){
  int i, t, acumulador = 0;
  int  c[2] = {0, 0};

  #define DIGIT_BIN(X) (X >> pos) & 1

  for(i = 0; i < size; i++){
    c[DIGIT_BIN(v[i])]++;
  }

  // SOMA DE PREFIXO
  c[1] = c[0];
  c[0] = 0;


  for(i = 0; i < size; i++){
    int chave = DIGIT_BIN(v[i]);
    int indice = c[chave];
    temp[indice] = v[i];
    c[chave]++;
  }

  memcpy(v, temp, size * sizeof(int));
}

void radixSort_bin(int* v, int size){
  int k = maxRadix(v, size);

  int *temp = malloc(sizeof(int) * size);
  int pos = 0;
  while(k > 0){
    counting_sort_bin(v, size, pos, temp);
    k = k/2;
    pos++;
  }

  free(temp);
}

int maxRadix(int *v, int size){
  int maior = v[0];

  for(int i = 0; i < size; i++){
    if(v[i] > maior){
      maior = v[i];
    }
  }

  return maior;
}

int* random_vector(int n, int max, int seed){
  int *vector = calloc(n, sizeof(int));

    srand(seed);
    for(int i = 0; i < n; i++){
      vector[i] =  rand() % max;
    }
    
    return vector;
}

void counting_sort(int *v, int size, int divisor, int base, int *temp){
  int i, t, c[base], acumulador = 0;
  memset(c, 0, base * sizeof(int));

  #define DIGIT(X) (X / divisor) % base

  for(i = 0; i < size; i++){
    c[DIGIT(v[i])]++;
  }

  // SOMA DE PREFIXO
  for(i = 0; i < base; i++){
    t = c[i];
    c[i] = acumulador;
    acumulador += t;
  }

  for(i = 0; i < size; i++){
    int chave = DIGIT(v[i]);
    int indice = c[chave];
    temp[indice] = v[i];
    c[chave]++;
  }

  memcpy(v, temp, size * sizeof(int));
}

void radixSort(int* v, int size){
  int k = maxRadix(v, size);
  int divisor = 1;

  int *temp = malloc(sizeof(int) * size);

  while(k > 0){
    counting_sort(v, size, divisor, 10, temp);
    divisor *= 10;
    k = k/10;
  }

  free(temp);
}
