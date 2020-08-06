#include <stdio.h>
#define N 5

int max(int *vetor, int start, int end){
    int bigger ;

    for(int i = start; i <= end; i++){
      if(vetor[end] < vetor[i])
        bigger = i;
    }

  printf("bigger %d, start %d, end %d\n", bigger, start, end);
  return bigger;
}

void troca(int *vetor, int bigger, int lastPosition){

  for(int i = 0; i < N; i++){
        printf("%d, ", vetor[i]);
    }

printf("trocou\n");
    int n1 = vetor[lastPosition];
    vetor[lastPosition] = vetor[bigger];
    vetor[bigger] = n1;

    for(int i = 0; i < N; i++){
        printf("%d, ", vetor[i]);
    }

    printf("\n\n");
}

int main(int argc, char** argv){
    int vet[N] = {1 , 33, 50, 7, 8};
    int bigger;
    

    for(int i = 0; i < N; i++){
        printf("%d, ", vet[i]);
    }

    printf("\n\n");

    for(int i = N-1; i > 0; i--){
        bigger = max(vet,0, i);
        troca(vet, bigger, i);
    }
    

    for(int i = 0; i < N; i++){
        printf("%d, ", vet[i]);
    }


    return 0;
}
