#include <stdio.h>
#include "busca.h"

void print(int *v, int n){
  for (int i = 0; i < n; i++){
    printf ("%d ", v[i]);
  }
}

int main (int argc, char **argv){
  int v[5] = { 3, 1, 26, 2, 55};
  // int *v2 = randomVectorUniqueElems(10, 0);
  // int v2[4] = {0, 1, 4, 5};
  // printf("%d", SelectionMinK(v2, 4, 3));
 
    print(v, 5);
    printf("\n");


  // printf ("%d\n", SelectionMinK(v, 5, 6));
  //  printf ("%d\n", QuickMinK(v, 0, 4, 5));
  printf ("%d\n", HeapMinK(v, 5, 0));
  
  print(v, 5);
  printf("\n");
  return 0;
}
