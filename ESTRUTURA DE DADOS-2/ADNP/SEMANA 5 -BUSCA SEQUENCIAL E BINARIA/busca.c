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