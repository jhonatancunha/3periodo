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
    return 0;
}
