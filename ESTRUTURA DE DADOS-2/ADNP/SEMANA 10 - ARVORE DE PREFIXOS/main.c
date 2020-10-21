#include <stdio.h>
#include "trie.h"

int main(int argc, char** argv){
  ASCIITrie *T = NULL;

  AT_Inserir_Iterativo(&T, "", 42);
  AT_Inserir_Iterativo(&T, "o", 1);
  AT_Inserir_Iterativo(&T, "rato", 10);
  AT_Inserir_Iterativo(&T, "roeu", 11);
  AT_Inserir_Iterativo(&T, "a", 2);
  AT_Inserir_Iterativo(&T, "roupa", 12);
  AT_Inserir_Iterativo(&T, "do", 3);
  AT_Inserir_Iterativo(&T, "rei", 13);
  AT_Inserir_Iterativo(&T, "de", 14);
  AT_Inserir_Iterativo(&T, "roma", 15);  



  int check = AT_Limpa(T);
  printf("%s\n", (check == 1) ? "Trie esta limpa!" : "Trie nao esta limpa");


  check = AT_Limpa(T);
  printf("%s\n", (check == 1) ? "Trie esta limpa!" : "Trie nao esta limpa");

  int tamanho = AT_Tamanho(T);
  printf("Tamanho: %d\n", tamanho);


  ASCIITrie *search;
  char *x;

  x = "rei";
  printf("%s: %s\n", (AT_Buscar_Iterativo(T, x) != NULL) ? "Chave encontrada" : "Chave nao encontrada", x);

  x = "goma";
  printf("%s: %s\n", (AT_Buscar(T, x) != NULL) ? "Chave encontrada" : "Chave nao encontrada", x);

  x = "roma";
  printf("%s: %s\n", (AT_Buscar_Iterativo(T, x) != NULL) ? "Chave encontrada" : "Chave nao encontrada", x);
  AT_Imprimir(T);

  printf("\n============\nChave roma foi removida!\n============\n\n");
  AT_Remover_Iterativo(&T, "roma");

  AT_Imprimir(T);
  x = "roma";
  printf("%s: %s\n", (AT_Buscar_Iterativo(T, x) != NULL) ? "Chave encontrada" : "Chave nao encontrada", x);
  
  printf("\n============\nChave roupa foi removida!\n============\n\n");
  AT_Remover_Iterativo(&T, "roupa");  
  AT_Imprimir(T);

  printf("\n============\nChave rei foi removida!\n============\n\n");
  AT_Remover_Iterativo(&T, "rei");

  AT_Imprimir(T);
  printf("\n============\nChave roeu foi removida!\n============\n\n");
  AT_Remover_Iterativo(&T, "roeu");
  AT_Imprimir(T);

  printf("\n============\nChave roeu foi removida!\n============\n\n");
  AT_Remover_Iterativo(&T, "roeu");
   AT_Imprimir(T);

    printf("\n============\nChave rato foi removida!\n============\n\n");
  AT_Remover_Iterativo(&T, "rato");
  AT_Imprimir(T);


  return 0;
}
