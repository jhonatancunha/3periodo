#include <stdlib.h>
#include <stdio.h>
#include "bilheteria.h"
#include "heapSort.h"


float obterDados() {
  FILE* arquivo = fopen("ingressos.txt", "r");   
  if(arquivo == NULL) return -1;

  int primeiraLinha[2];
  int *assentos = (int*) calloc(1000, sizeof(int));
  char *numeroParcial = (char*) calloc(1000, sizeof(char));
  int assentosOcupados = 0;


  // VARIAVEIS AUXILIARES
  char aux = fgetc(arquivo);
  int i = 0;
  int j = 0;

  while(aux != '\n'){
    if(aux != ' ') numeroParcial[i++] = aux;
    aux = fgetc(arquivo);

    if(aux == ' ' || aux == '\n'){
      if(atoi(numeroParcial) > 1000) return -1;

      primeiraLinha[j++] = atoi(numeroParcial);
      free(numeroParcial);
      numeroParcial = (char*) calloc(1000, sizeof(char));
      i = 0;
    }
  };

  while(aux != EOF){
    if(aux != ' ' && aux != '\n') numeroParcial[i++] = aux;
    aux = fgetc(arquivo);
    
    //verificar se existe mais algarismos no numero
    if(aux == ' ' || aux == EOF){
      if(atoi(numeroParcial) > 1000) return -1;

      assentosOcupados = FP_MIN_inserir(assentos, assentosOcupados, atoi(numeroParcial));
      free(numeroParcial);
      numeroParcial = (char*) calloc(1000, sizeof(char));
      i = 0;
    }
  };
  
  if(primeiraLinha[0] < assentosOcupados){
    return -1;
  }
 
  print(assentos, assentosOcupados);
  fclose(arquivo);
  return calculoLucro(primeiraLinha[1], assentos, assentosOcupados);
}

float calculoLucro(int pessoasFila, int *assentos, int assentosOcupados){
  float lucroTotal = 0;
  while(assentosOcupados > 0){
    int minimo = FP_MIN_inicio(assentos, assentosOcupados);
    assentosOcupados = FP_MIN_remover(assentos, assentosOcupados);

    while(minimo > 0 && pessoasFila > 0){
      int aux = 100 + (100/minimo);
      lucroTotal += aux;
      minimo--;
      pessoasFila--;
    }
  }


  return lucroTotal;
}

void print(int *v, int size){
  printf("==============\n");
  for(int i = 0; i < size; i++){
    printf("%d ", v[i]);
    fflush(stdout);
  }
  printf("\n==============\n");
}