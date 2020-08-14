#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define SEED 0

// PROTOTYPES
void selectionSort(int *vetor, int size);
void bubbleSort(int *vetor, int size);
void insertionSort(int *vetor, int size);
int max(int *vetor, int start, int end);
void troca(int *vetor, int bigger, int lastPosition);
void printVetor(int *vetor, int size);
void insertion(int *vetor, int size);
int* randomVector(int n, int max, int seed);
int* orderedVector(int n, int max);
void merge(int *v, int start, int middle, int end);
void mergeSort(int *v, int left, int right);
int partition(int *v, int p, int r);
void quickSort(int *v, int e, int d);


void insertionSort(int *vetor, int size){
  for(int i = 1; i < size; i++){
    insertion(vetor, i);
  }
}

void selectionSort(int *vetor, int size){
  int bigger;
  for(int i = size-1; i > 0; i--){
      bigger = max(vetor,0, i);
      troca(vetor, bigger, i);
  }
}

void bubbleSort(int *vetor, int size ){
  for(int i = size-1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(vetor[j] > vetor[j+1]){
        troca(vetor, j, j+1);
      }
    }
  }
}

void insertion(int *vetor, int size){
  int i = size-1;
  int savedValue = vetor[size];

  while(i >= 0 && vetor[i] > savedValue){
    vetor[i+1] = vetor[i];
    i--;
  }

  vetor[i+1] = savedValue;
}

int max(int *vetor, int start, int end){
  int bigger = end;

  for(int i = start; i <= end; i++){
      if(vetor[i] > vetor[end] && vetor[i] > vetor[bigger]){
        bigger = i;
      }

  }

  return bigger;
}

void troca(int *vetor, int bigger, int lastPosition){
  int n1 = vetor[lastPosition];
  vetor[lastPosition] = vetor[bigger];
  vetor[bigger] = n1;
}

void printVetor(int *vetor, int size){
  for(int i = 0; i < size; i++){
      printf("%d, ", vetor[i]);
  }
}

int* randomVector(int n, int max, int seed){
  int* v = (int*) calloc(n, sizeof(int));
  srand(seed);
  for(int i = 0; i < n; i++)
    v[i] = rand() % max;

  return v;
}

int* orderedVector(int n, int max){
  int* v = (int*) calloc(n, sizeof(int));
  for(int i = 0; i < n; i++)
    v[i] = i+1;

  return v;
}

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

int partition(int *v, int p, int r){
  int x, i, j;
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
  while(e < d){
    q = partition(v, e, d);
    if(q - e < d - q){
      quickSort(v, e, q-1);
      e = q + 1;
    }else{
      quickSort(v, q+1, d);
      d = q-1;
    }
  }
}


int main(int argc, char** argv){
  int size = 500000;
  int max = size*100;


  clock_t time;

  int *vet2 = orderedVector(size, max);
  printf("=============\nBubble Sort\n");

  time = clock();
  bubbleSort(vet2, size);
  time = clock() - time;
  
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));

  int *vet4 = orderedVector(size, max);
  printf("=============\nInsertion Sort\n");
 
  time = clock();
  insertionSort(vet4, size);
  time = clock() - time;

  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));


  int *vet = orderedVector(size, max);
  printf("=============\nSelection Sort\n");

  time = clock();
  selectionSort(vet, size);
  time = clock() - time;

  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));

  printf("=============\nMerge Sort\n");
  int *mergeVector = orderedVector(size, max);

  time = clock();
  mergeSort(mergeVector, 0, size-1);
  time = clock() - time;
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));

  printf("=============\nQuick Sort\n");
  int *quickVector = orderedVector(size, max);

  time = clock();
  quickSort(quickVector, 0, size-1);
  time = clock() - time;
  printf("It took %lf seconds.\n", ((float)time/CLOCKS_PER_SEC));

  return 0;
}
