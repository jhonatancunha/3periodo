#include "list.h"

Lista* criarLista(int alloc_step){
  Lista *L = malloc(sizeof(Lista));
  L->alloc = alloc_step;
  L->alloc_step = alloc_step;
  L->tam = 0;
  L->max = 0;
  L->nos = calloc(alloc_step, sizeof(No))

  for(int i = 0; i < alloc_step; i++) L->nos[i].ocupado = 0;

  return L;
}

int buscarLista(Lista *L, int chave){
  for(int i = 0; i < L->max; i++)
    if(L->nos[i].chave == chave && L->nos[i].ocupado)
      return i;
  
  return -1;
}

int inserirLista(Lista *L, int chave, int valor){

}

int removerLista(Lista *L, int chave){
  int posicao = buscarLista(L, chave);

  if(posicao != -1){
    L->max--;
    L->nos[posicao].ocupado = 0;
  }

  return posicao;
}

void imprimirLista(Lista *L, int debug){
  printf("TAM: %d, MAX: %d\n", L->tam, L->max);

  for(int i = 0; i < L->max; i++)
    if(L->nos[i].ocupado || debug)
      printf("%d -> %d (%d) \n", L->nos[i].chave, L->nos[i].valor, L->nos[i].ocupado)
}

Lista* enderecoLista(Lista *L, int pos){
  if(pos != -1) return &(L->nos[pos])

  return NULL;
}