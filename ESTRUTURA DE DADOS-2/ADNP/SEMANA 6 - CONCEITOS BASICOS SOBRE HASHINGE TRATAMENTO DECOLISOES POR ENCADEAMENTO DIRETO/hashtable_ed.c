#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"
#include <limits.h>

int THED_Hash(THED* HT, int chave){
    return chave % HT->m;
}

THED* THED_Criar(int m, int alloc_step){
    THED *nova;
    int i;

    nova = malloc(sizeof(THED));
    nova->m = m;
    nova->t = malloc(sizeof(ILIST*) * m);
    for(i = 0; i < m; i++)
        nova->t[i] = ILIST_Criar(alloc_step);

    return nova;
}

void THED_Inserir(THED* HT, int chave, int valor){
    int hash = THED_Hash(HT, chave);
    ILIST_Inserir(HT->t[hash], chave, valor);
}

void THED_Remover(THED* HT, int chave){
    int hash = THED_Hash(HT, chave);
    ILIST_Remover(HT->t[hash], chave);

}

INOH* THED_Buscar(THED* HT, int chave){
    int hash = THED_Hash(HT, chave);
    int pos = ILIST_Buscar(HT->t[hash], chave);
    
    if(pos == -1) return NULL;
    return ILIST_Endereco(HT->t[hash], pos);
}

THED* inserir_n_aleatorios(int n, int m, int seed){
    THED *th = THED_Criar(m, n);

    srand(seed);
    for(int i = 0; i < n; i++){
        int valor_chave = rand() % (10*n);
        THED_Inserir(th, valor_chave, valor_chave);
    }

    return th;
}

int THED_MaisCurta(THED* TH){
    int menor = INT_MAX;

    for(int i = 0; i < TH->m; i++){
        if(menor > TH->t[i]->tam && TH->t[i]->tam > 0){
            menor = TH->t[i]->tam;
        }
    }

    return menor;
}

int THED_MaisLonga(THED* TH){
int maior = INT_MIN;

    for(int i = 0; i < TH->m; i++){
        if(maior < TH->t[i]->tam){
            maior = TH->t[i]->tam;
        }
    }

    return maior;
}

float THED_TamMedio(THED* TH){
    float soma = 0;

    for(int i = 0; i < TH->m; i++){
        soma += TH->t[i]->tam;
    }

    return soma/TH->m;
}

void print_THED(THED *TH){
  printf("============\n");
  for(int i = 0;i < TH->m; i++){
    printf("%d -> ", i);
    for(int j = 0; j < TH->t[i]->max; j++){
      if(TH->t[i]->nos[j].ocupado){
        printf("%d - ", TH->t[i]->nos[j].valor);
      }
    }
   printf("\n"); 
  }
}
