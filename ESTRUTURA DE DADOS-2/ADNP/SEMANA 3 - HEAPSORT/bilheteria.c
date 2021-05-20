#include <stdlib.h>
#include <stdio.h>
#include "bilheteria.h"
#include "heapSort.h"


float obterLucro() {
  FILE* arquivo = fopen("case7.txt", "r");   
  if(arquivo == NULL) return -1;

  int primeiraLinha[2];
  int *assentos = (int*) calloc(1000, sizeof(int));
  char *algarismo = (char*) calloc(1000, sizeof(char));
  int fileirasDisponiveis = 0;


  // VARIAVEIS AUXILIARES
  char caractereAuxiliar = fgetc(arquivo);
  int i = 0;
  int j = 0;

  // PRIMEIRA LINHA
  while(caractereAuxiliar != '\n'){
    if(caractereAuxiliar != ' ') algarismo[i++] = caractereAuxiliar;
    caractereAuxiliar = fgetc(arquivo);

  //VERIFICA SE EXISTE MAIS ALGUM ALGARISMO ANTES DE ADICIONAR NA FILA
    if(caractereAuxiliar == ' ' || caractereAuxiliar == '\n'){
      if(atoi(algarismo) > 1000 || atoi(algarismo) < 1){
        printf("Erro na primeira linha: numero > 1000 ou numero < 1\n");
        printf("valor: %d\n", atoi(algarismo));
        return -1;
      }

      primeiraLinha[j++] = atoi(algarismo);
      free(algarismo);
      algarismo = (char*) calloc(1000, sizeof(char));
      i = 0;
    }
  };

  int somaCadeiras = 0;
  // SEGUNDA LINHA
  while(caractereAuxiliar != EOF){
    if(caractereAuxiliar != ' ' && caractereAuxiliar != '\n') algarismo[i++] = caractereAuxiliar;
    caractereAuxiliar = fgetc(arquivo);
    
    //VERIFICA SE EXISTE MAIS ALGUM ALGARISMO ANTES DE ADICIONAR NA FILA
    if(caractereAuxiliar == ' ' || caractereAuxiliar == EOF){
      if(atoi(algarismo) > 1000 || atoi(algarismo) < 1){
        printf("Erro na segunda linha: numero > 1000 ou numero < 1\n");
        printf("valor: %d\n", atoi(algarismo));
        return -1;
      }
      somaCadeiras += atoi(algarismo);
      fileirasDisponiveis = FP_MIN_inserir(assentos, fileirasDisponiveis, atoi(algarismo));
      free(algarismo);
      algarismo = (char*) calloc(1000, sizeof(char));
      i = 0;
    }
  };
  
  // VERIFICA SE A QUANTIDADE DE FILEIRAS INFORMADAS NA PRIMEIRA LINHA
  // CONDIZ COM A QUANTIADEDE INFORMADA NA SEGUNDA
  if(primeiraLinha[0] < fileirasDisponiveis){
    printf("Erro primeira linha: numero de fileiras menor que indicado na segunda linha.\n");
    printf("%d < %d\n", primeiraLinha[0], fileirasDisponiveis);
    return -1;
  }
  
  // SE A QUANTIDADE DE CADEIRAS DISPONIVEIS FOR MAIOR QUE A QUANTIDADE DE PESSOAS RETORNA ERRO
  if(somaCadeiras < primeiraLinha[1]){
    printf("Erro: quantidade de pessoas ultrapassa quantiaded de assentos disponiveis.\n");
    printf("%d < %d\n", somaCadeiras, primeiraLinha[1]);
    return -1;
  }
 
  fclose(arquivo);
  return calculoLucro(primeiraLinha[1], assentos, fileirasDisponiveis);
}

float calculoLucro(int pessoasFila, int *assentos, int fileirasDisponiveis){
  float lucroTotal = 0;

  while(fileirasDisponiveis > 0){
    int fileiraMenosAssentos = FP_MIN_inicio(assentos, fileirasDisponiveis);
    fileirasDisponiveis = FP_MIN_remover(assentos, fileirasDisponiveis);

    while(fileiraMenosAssentos > 0 && pessoasFila > 0){
      int aux = 100 + (100/fileiraMenosAssentos);
      lucroTotal += aux;
      fileiraMenosAssentos--;
      pessoasFila--;
    }
  }


  return lucroTotal;
}
