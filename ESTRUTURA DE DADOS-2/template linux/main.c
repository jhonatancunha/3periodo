#include <stdio.h>
#define N 5

int max(int *vetor, int start, int end){
    return (vetor[start] > vetor[end]) ? start : end;
}

int main(int argc, char** argv){
    int vet[N] = {1 , 2, 50, 2, 8};
    int maior;
    for(int i = N; i > 0; i--){
        maior = max(vet,0, i);
    }


    return 0;
}
