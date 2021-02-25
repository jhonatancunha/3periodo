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
  // ord_vetor_tree(N, 4, 1, vetor_decrescente, ABB_Sort);

  printf("\nARN_SORT\n");
  ord_vetor_tree(N, 4, 1, vetor_decrescente, ARN_Sort);

  printf("\nAVLL_SORT\n");
  ord_vetor_tree(N, 4, 1, vetor_decrescente, AAVL_Sort);




  printf("\n\nVETORES ALETAORIOS\n");

  printf("\nABB_SORT\n");
  ord_vetor_tree(N, 4, 10, vetor_random, ABB_Sort);

  printf("\nARN_SORT\n");
  ord_vetor_tree(N, 4, 10, vetor_random, ARN_Sort);

  printf("\nAVLL_SORT\n");
  ord_vetor_tree(N, 4, 10, vetor_random, AAVL_Sort);
 


  return 0;
}

