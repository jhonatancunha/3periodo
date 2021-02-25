#pragma once

typedef struct AAVL{
  struct AAVL *dir;
  struct AAVL *esq;
  int chave;
  int dado;
  int fb;
}AAVL;

void AAVL_Inserir(AAVL** A, int chave, int dado);
void AAVL_Sort(int* v, int n, float *altura);
int AAVL_Altura(AAVL *A);