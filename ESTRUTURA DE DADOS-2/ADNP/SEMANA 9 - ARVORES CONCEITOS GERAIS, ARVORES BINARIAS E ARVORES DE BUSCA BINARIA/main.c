#include <stdio.h>
#include "abb.h"

int main(int argc, char** argv){
    // CASO A
    AB *caso_a = NULL;
    ABB_Inserir(&caso_a, 70);
    ABB_Inserir(&caso_a, 39);
    ABB_Inserir(&caso_a, 88);

    ABB_Remover(&caso_a, 70);
    ABB_Imprimir(caso_a, "caso_a.txt");

    // CASO B
    AB *caso_b = NULL;
    ABB_Inserir(&caso_b, 10);
    ABB_Inserir(&caso_b, 4);
    ABB_Inserir(&caso_b, 20);
    ABB_Inserir(&caso_b, 6);
    ABB_Inserir(&caso_b, 2);
    ABB_Inserir(&caso_b, 3);
    ABB_Inserir(&caso_b, 5);
    ABB_Inserir(&caso_b, 7);

    ABB_Remover(&caso_b, 10);
    ABB_Remover(&caso_b, 4);
    ABB_Remover(&caso_b, 5);
    ABB_Imprimir(caso_b, "caso_b.txt");

    // CASO C
    AB *caso_c = NULL;
    ABB_Inserir(&caso_c, 30);
    ABB_Inserir(&caso_c, 50);
    ABB_Inserir(&caso_c, 40);
    ABB_Inserir(&caso_c, 47);
    ABB_Inserir(&caso_c, 15);
    ABB_Inserir(&caso_c, 20);
    ABB_Inserir(&caso_c, 25);
    ABB_Inserir(&caso_c, 17);
    ABB_Inserir(&caso_c, 19);
    ABB_Inserir(&caso_c, 4);
    ABB_Inserir(&caso_c, 7);
    ABB_Inserir(&caso_c, 0);

    ABB_Remover(&caso_c, 0);
    ABB_Remover(&caso_c, 30);
    ABB_Remover(&caso_c, 15);
    ABB_Remover(&caso_c, 20);
    ABB_Imprimir(caso_c, "caso_c.txt");
    return 0;
}
