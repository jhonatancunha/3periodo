#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "teste.h"
#include "rubro_negra/arn.h"
#include "busca_binaria/abb.h"
#include "avl/avl.h"

int main(int argc, char** argv){
  int N[] = {1000, 10000, 100000, 500000};
  int seed = 42;

  printf("VETORES DECRESCENTES\n");

  // printf("\nABB_SORT\n");
  // for(int i = 0; i < 4; i++){
  //   int *v = vetor_decrescente(N[i]);
  //   int n = N[i];

  //   time_t inicio = clock();
  //   ABB_Sort(v, n);
  // free(v);
  //   printf("N = %d \t ABB_SORT durou: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC);

  // }

  printf("\nARN_SORT\n");
  for(int i = 0; i < 4; i++){
    int *v = vetor_decrescente(N[i]);
    int n = N[i];

    time_t inicio = clock();
    ARN_Sort(v, n);
  free(v);
    printf("N = %d \t ARN_SORT durou: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC);
  }


  printf("\nAVLL_SORT\n");
  for(int i = 0; i < 4; i++){
    int *v = vetor_decrescente(N[i]);
    int n = N[i];

    time_t inicio = clock();
    AAVL_Sort(v, n);
  free(v);
    printf("N = %d \t AVVL_SORT durou: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC);
  }
  
  printf("\n\nVETORES ALETAORIOS SEED %d\n", seed);

  printf("\nABB_SORT\n");
  for(int i = 0; i < 4; i++){
    float media_segundos = 0;
    int n = N[i];
    for(int x = 0; x < 10; x++){
      int *v = vetor_random(N[i], seed);

      time_t inicio = clock();
      ABB_Sort(v, n);
      free(v);
      media_segundos += (float)(clock()-inicio)/(double)CLOCKS_PER_SEC;
    }
    printf("N: %d - tempo medio: %f\n", N[i], media_segundos/10);
  }

  printf("\nARN_SORT\n");
  for(int i = 0; i < 4; i++){
    float media_segundos = 0;
    int n = N[i];
    for(int x = 0; x < 10; x++){
      int *v = vetor_random(N[i], seed);

      time_t inicio = clock();
      ARN_Sort(v, n);
      free(v);
      media_segundos += (float)(clock()-inicio)/(double)CLOCKS_PER_SEC;
    }
    printf("N: %d - tempo medio: %f\n", N[i], media_segundos/10);
  }

  printf("\nAVLL_SORT\n");
  for(int i = 0; i < 4; i++){
    float media_segundos = 0;
    int n = N[i];
    for(int x = 0; x < 4; x++){
      int *v = vetor_random(n, 42);

      time_t inicio = clock();
      AAVL_Sort(v, n);
      free(v);
      media_segundos += (float)(clock()-inicio)/(double)CLOCKS_PER_SEC;
    }
    printf("N: %d - tempo medio: %f\n", N[i], media_segundos/10);
  }

  return 0;
}

