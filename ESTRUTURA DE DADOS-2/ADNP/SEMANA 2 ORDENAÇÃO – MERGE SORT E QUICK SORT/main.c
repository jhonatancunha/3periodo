#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *v, int start, int middle, int end){

  int i, j, k;
  int sizeOfFirstSubVector = middle - start + 1;
  int sizeOfSecondSubVector = end - middle;
  int *firstSubVector = (int*) calloc((sizeOfFirstSubVector + 1), sizeof(int));
  int *secondSubVector = (int*) calloc((sizeOfSecondSubVector + 1) ,sizeof(int));

  for(i = 0; i < sizeOfFirstSubVector; i++){
      firstSubVector[i] = v[start + i];
  }
  firstSubVector[sizeOfFirstSubVector] = INT_MAX;

  for(j = 0; j < sizeOfSecondSubVector; j++){
      secondSubVector[j] = v[middle + j + 1];
  }
  secondSubVector[sizeOfSecondSubVector] = INT_MAX;
  i = 0;
  j = 0;


  for(k = start; k <= end; k++){
      if(firstSubVector[i] <= secondSubVector[j]){
          v[k] = firstSubVector[i++];
      }else{
          v[k] = secondSubVector[j++];
      }
  }

  free(firstSubVector);
  free(secondSubVector);
}

void mergeSort(int *v, int left, int right){
  if(left < right){
    int middle = (left + right)/2;
    mergeSort(v, left, middle);
    mergeSort(v, middle + 1, right);
    merge(v, left, middle, right);  
  }
}

void troca(int *vetor, int bigger, int lastPosition){
  int n1 = vetor[lastPosition];
  vetor[lastPosition] = vetor[bigger];
  vetor[bigger] = n1;
}

// QUICK SORT
int partition(int *v, int p, int r){
  int x;
  int i, j;
  x = v[r];
  i = p-1;

  for(j = p; j < r; j++){
    if(v[j] <= x){
      i++;
      troca(v, i, j);
    }
  }
  troca(v, i+1, r);

  return i+1;
}

void quickSort(int *v, int e, int d){
  int q;
  if(e < d){
    q = partition(v, e, d);
    quickSort(v, e, q-1);
    quickSort(v, q+1, d);
  }
}

int main(int argc, char** argv){
    // int v[8] = {3, 2, 5, 0, 7, 8, 1, 4};

  int tam = 8;
  int v[8] = {3, 2, 5, 0, 7, 8, 1, 4};
  for(int i = 0; i < tam; i++ ){
    printf("%d, ", v[i]);
  }
  printf("\n=============\n");
  mergeSort(v, 0, tam);

  for(int i = 0; i < tam; i++ ){
    printf("%d, ", v[i]);
  }

  printf("\n=============\n");

  int v2[10] = {10, 8, 6, 12, 13, 3, 15, 4, 11, 7};

  for(int i = 0; i < 10; i++ ){
    printf("%d, ", v2[i]);
  }
  printf("\n=============\n");

  quickSort(v2, 0, 9);

  printf("=============\n");
  for(int i = 0; i < 10; i++ ){
    printf("%d, ", v2[i]);
  }
    return 0;
}
