#include <stdio.h>
#include <stdlib.h>
#include "hashtable_ed.h"



int main(int argc, char** argv){
  int m = 10;
  int n = 50000;
  int seed = 42;
  THED* th = inser  ir_n_aleatorios(n, m, seed);
  // print_THED(th);

  printf("maior: %d\n\n", THED_MaisLonga(th));
  printf("menor: %d\n", THED_MaisCurta(th));
  printf("media: %f\n", THED_TamMedio(th));
  return 0;
}
