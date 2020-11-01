#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "teste.h"
#include "rubro_negra/arn.h"
#include "busca_binaria/abb.h"
#include "avl/avl.h"

int main(int argc, char** argv){
  int N[] = {1000, 10000, 100000, 500000};

  printf("VETORES DECRESCENTES\n");

  printf("\nABB_SORT\n");
  for(int i = 0; i < 4; i++){
    int *v = vetor_decrescente(N[i]);
    int n = N[i];

    time_t inicio = clock();
    ABB_Sort(v, n);
    printf("N = %d \t ABB_SORT durou: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC);
  }

  // printf("\nARN_SORT\n");
  // for(int i = 0; i < 4; i++){
  //   int *v = vetor_decrescente(N[i]);
  //   int n = N[i];

  //   time_t inicio = clock();
  //   ARN_Sort(v, n);
  //   printf("N = %d \t ARN_SORT durou: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC);
  // }


  // printf("\nAVLL_SORT\n");
  // for(int i = 0; i < 4; i++){
  //   int *v = vetor_decrescente(N[i]);
  //   int n = N[i];

  //   time_t inicio = clock();
  //   AAVL_Sort(v, n);
  //   printf("N = %d \t AVVL_SORT durou: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC);
  // }
  
  return 0;
}

