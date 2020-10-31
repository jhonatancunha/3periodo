#pragma once

typedef struct AVL{
  struct AVL esq;
  struct AVL dir;
  int valor;
  int fator_b;
} AVL;