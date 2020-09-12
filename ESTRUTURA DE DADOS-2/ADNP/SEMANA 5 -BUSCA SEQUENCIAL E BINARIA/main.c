#include <stdio.h>
#include <time.h>
#include "busca.h"


void print(int *v, int n){
  for (int i = 0; i < n; i++){
    printf ("%d ", v[i]);
  }
}

int main (int argc, char **argv){
  clock_t t;

  int n = 500000;
  int k = n;

  int *selection = randomVectorUniqueElems(n, 42);
  int *quick = randomVectorUniqueElems(n, 42);
  int *heap = randomVectorUniqueElems(n, 42);
  
   printf("selection: %d\n", selection[k-1]);
  printf("quick: %d\n", quick[k-1]);
   printf("heap: %d\n", heap[k-1]);
  printf(" N = %d , K = %d\n", n, k);

  t = clock();
  printf("==================\n");
  printf("SelectionMinK: %d-esima posicaoo: ", k);
  printf ("%d\n", SelectionMinK(selection, n, k));
  t = clock() - t;
  printf("Levou %f segundos para executar!\n", (float)t/(CLOCKS_PER_SEC));
  printf("==================\n\n");


  t = clock();
  printf("QuickMinK: %d-esima posicaoo: ", k);
  printf ("%d\n", QuickMinK(quick, 0, n-1, k));
  t = clock() - t;
  printf("Levou %f segundos para executar!\n", (float)t/(CLOCKS_PER_SEC));
  printf("==================\n\n");


  t = clock();
  printf("HeapMinK: %d-esima posicaoo: ", k);
  printf ("%d\n", HeapMinK(heap, n, k));
  t = clock() - t;
  printf("Levou %f segundos para executar!\n", (float)t/(CLOCKS_PER_SEC));
  printf("==================\n");

  return 0;
}
