#include <stdio.h>
#include <stdlib.h>
#include "bilheteria.h"


int main(int argc, char** argv){
  float vetor = obterDados();
  if(vetor != -1){
    printf("valor final: %f\n", vetor);
  }else{
    printf("Error!\n");
  }
  return 0;
}