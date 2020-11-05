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
  // ARN *a = NULL;
  // ARN_Inserir(&a, 47, 47);
  // ARN_Inserir(&a, 32, 32);
  // ARN_Inserir(&a, 5, 5);
  // ARN_Inserir(&a, 15, 15);
  // ARN_Inserir(&a, 40, 40);
  // ARN_Inserir(&a, 68, 68);
  // ARN_Inserir(&a, 60, 60);
  // ARN_Inserir(&a, 54, 54);
  // ARN_Inserir(&a, 50, 50);
  // ARN_Inserir(&a, 61, 61);
  // ARN_Inserir(&a, 88, 88);
  // ARN_Inserir(&a, 75, 75);
  // ARN_Inserir(&a, 90, 90);
  

  // printf("altura: %d\n", ARN_Altura(a));


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
    float altura = 0;
    int *v = vetor_decrescente(N[i]);
    int n = N[i];

    time_t inicio = clock();
    ARN_Sort(v, n, &altura);
    free(v);
    printf("N = %d \t ARN_SORT durou: %f - altura negra: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC, altura);
  }


  // printf("\nAVLL_SORT\n");
  // for(int i = 0; i < 4; i++){
  //   int *v = vetor_decrescente(N[i]);
  //   int n = N[i];

  //   time_t inicio = clock();
  //   AAVL_Sort(v, n);
  // free(v);
  //   printf("N = %d \t AVVL_SORT durou: %f\n", n,(clock()-inicio)/(double)CLOCKS_PER_SEC);
  // }
  
  // printf("\n\nVETORES ALETAORIOS SEED %d\n", seed);

  // printf("\nABB_SORT\n");
  // for(int i = 0; i < 4; i++){
  //   float media_segundos = 0;
  //   float altura = 0;
  //   int n = N[i];
  //   for(int x = 0; x < 10; x++){
  //     int *v = vetor_random(N[i], seed);

  //     time_t inicio = clock();
  //     ABB_Sort(v, n, &altura);
  //     free(v);
  //     media_segundos += (float)(clock()-inicio)/(double)CLOCKS_PER_SEC;
  //   }
  //   printf("N: %d - tempo medio: %f - altura media: %f\n", N[i], media_segundos/10, altura/10);
  // }

  printf("\nARN_SORT\n");
  for(int i = 0; i < 4; i++){
    float media_segundos = 0;
    float altura = 0;
    int n = N[i];
    for(int x = 0; x < 10; x++){
      int *v = vetor_random(N[i], seed);

      time_t inicio = clock();
      ARN_Sort(v, n, &altura);
      free(v);
      media_segundos += (float)(clock()-inicio)/(double)CLOCKS_PER_SEC;
    }
    printf("N: %d - tempo medio: %f - altura media: %f\n", N[i], media_segundos/10, altura/10);
  }

  // printf("\nAVLL_SORT\n");
  // for(int i = 0; i < 4; i++){
  //   float media_segundos = 0;
  //   int n = N[i];
  //   for(int x = 0; x < 4; x++){
  //     int *v = vetor_random(n, 42);

  //     time_t inicio = clock();
  //     AAVL_Sort(v, n);
  //     free(v);
  //     media_segundos += (float)(clock()-inicio)/(double)CLOCKS_PER_SEC;
  //   }
  //   printf("N: %d - tempo medio: %f\n", N[i], media_segundos/10);
  // }

  return 0;
}

