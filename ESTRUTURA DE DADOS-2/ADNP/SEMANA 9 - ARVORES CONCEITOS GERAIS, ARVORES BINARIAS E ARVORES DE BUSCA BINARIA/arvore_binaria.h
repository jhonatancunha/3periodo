#pragma once

typedef struct AB{
  struct AB *esq;
  struct AB *dir;
  int chave;
}AB;

// Funções de impressão de percurso árvore binária
void imprime_pre_ordem(AB *arvore, int tabs, char direcao, FILE *texto);
// Funções de impressão de percurso árvore binária
void imprime_em_ordem(AB *arvore);
// Funções de impressão de percurso árvore binária
void imprime_pos_ordem(AB *arvore);

