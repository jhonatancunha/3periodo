#include <stdio.h>
#include <stdlib.h>
#include "bilheteria.h"
#include <time.h>


int main(int argc, char** argv){
  
  clock_t time;

  time = clock();
  float vetor = obterLucro();
  time = clock() - time;


  if(vetor != -1){
    printf("Tempo: %f\n", ((float)time/CLOCKS_PER_SEC));
    printf("valor final: R$ %.2f\n", vetor);
  }else{
    printf("Error!\n");
  }
  return 0;
}