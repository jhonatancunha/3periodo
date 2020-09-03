#include <stdio.h>
#include "busca.h"

int main(int argc, char** argv){
    int v[5] = { 1, 3, 6, 55, 152};

    int posicao = busca_bin(v, 0, 4, 22);

    if(posicao != -1){
        printf("Posicao: %d\n", posicao);
    }else{
        printf("Valor nao encontrado!\n");
    }

    // int *v2 = randomVectorUniqueElems(10, 0);
    int v2[4] = {0, 1, 4, 5};
    printf("%d", SelectionMinK(v2, 4, 3));
    
    return 0;
}
