#include <stdlib.h>
#include <string.h>
#include "busca.h"

int busca_seq(int *v, int size, int x){
  for(int i = 0; i < size; i++){
    if(v[i] == x) return i;
  }

  return -1;
}

// int busca_bin(int*v, int size, int x){
//   int meio = (size-1)/2;

//   if(v[meio] == x){
//     return meio;
//   }else if(v[meio] < x){
//     for(int i = size; i > meio; i--){
//       if(v[i] == x) return i;
//     }
//   }else if(v[meio] > x){
//     for(int i = 0; i < meio; i++){
//       if(v[i] == x) return i;
//     }
//   }

//   return -1;
// }


int busca_bin(int*vetor, int limiteEsquerdo, int limiteDireito, int valor){
  if(limiteDireito <  limiteEsquerdo) return -1;

  int meio = (limiteEsquerdo + limiteDireito) / 2;

  if(vetor[meio] == valor){
    return meio;
  }

  if(valor > vetor[meio]){
    return busca_bin(vetor, meio+1, limiteDireito, valor);
  }

  if(valor < vetor[meio]){
    return busca_bin(vetor, limiteEsquerdo, meio-1, valor);
  }
}

int SelectionMinK(int *v, int n, int k){
  int *copia = calloc(n, sizeof(int));
  int j = k;
  memcpy(copia, v, sizeof(int) * n);

  for(int i = 0; i < n; i++){
    int minK = encontreMinK(copia, i, n, i);
    troca(copia, i, minK);
    j--;
    if(j == 0) break;
  }

  return copia[k-1];
}

int encontreMinK(int *v, int i, int tamanho, int indiceMenor){
  for(int j = i; j < tamanho; j++){
    if(v[j] < v[indiceMenor]){
      indiceMenor = j;
    }
  }

  return indiceMenor;
}


int* randomVectorUniqueElems(int n, int seed){
  int* v = (int*) calloc(n, sizeof(int));
  srand(seed);

  for(int i = 0; i < n; i++) v[i] = i+1;
  embaralhar(v, 0, n);

  return v;
}

void embaralhar(int *v, int inicio, int fim){
  for(int i = fim-1; i > inicio; i--){
    int j = rand() % (i+1);
    j = (j <= inicio) ? inicio+1 : j;
    troca(v, i, j);  
  }
}

void troca(int* v, int pos1, int pos2){
  int aux = v[pos1];
  v[pos1] = v[pos2];
  v[pos2] = aux;
}