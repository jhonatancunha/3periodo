#ifndef __ABB_H__
#define __ABB_H__

#include "arvore_binaria.h"

// FUNÇÃO QUE FAZ BUSCA EM ARVORE BINÁRIA
AB* ABB_Busca(AB *arvore, int chave);

// FUNÇÃO QUE CRIA NÓ EM ARVORE BINÁRIA
AB* ABB_Criar(int chave, AB* esq, AB* dir);

// FUNÇÃO QUE INSERE CHAVE NA ARVORE BINÁRIA
void ABB_Inserir(AB **arvore, int chave);

// FUNÇÃO QUE RETORNA O NUMERO DE NÓS DA ARVORE
int ABB_Tamanho(AB *arvore);

// FUNÇÃO QUE DESALOCA TODOS OS NÓS DA ARVORE
void ABB_Destruir(AB **arvore);

// FUNÇÃO QUE REMOVE NO DA ARVORE
void ABB_Remover(AB **A, int chave);

// FUNÇÃO QUE IMPRIME TODA A TABELA HASH
void ABB_Imprimir(AB *arvore, char* caso);

#endif