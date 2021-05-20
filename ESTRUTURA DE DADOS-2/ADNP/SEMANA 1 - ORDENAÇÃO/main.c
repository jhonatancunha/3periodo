#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SEED 0

// PROTOTYPES
void selectionSort(int *vetor, int size, int *ComparationCounter, int *SwapCounter);
void bubbleSort(int *vetor, int size, int *ComparationCounter, int *SwapCounter);
void insertionSort(int *vetor, int size, int *ComparationCounter);
int max(int *vetor, int start, int end, int *ComparationCounter);
void troca(int *vetor, int bigger, int lastPosition, int *SwapCounter);
void printVetor(int *vetor, int size);
void insertion(int *vetor, int size, int *ComparationCounter);
int* randomVector(int n, int max, int seed);

void insertionSort(int *vetor, int size, int *ComparationCounter){
  for(int i = 1; i < size; i++){
    insertion(vetor, i, ComparationCounter);
  }
}

void selectionSort(int *vetor, int size, int *ComparationCounter, int *SwapCounter){
  int bigger;
  for(int i = size-1; i > 0; i--){
      bigger = max(vetor,0, i, ComparationCounter);
      troca(vetor, bigger, i, SwapCounter);
  }
}

void bubbleSort(int *vetor, int size, int *ComparationCounter , int *SwapCounter){
  for(int i = size-1; i > 0; i--){
    for(int j = 0; j < i; j++){
      *ComparationCounter += 1;
      if(vetor[j] > vetor[j+1]){
        troca(vetor, j, j+1, SwapCounter);
      }
    }
  }
}

void insertion(int *vetor, int size, int *ComparationCounter){
  int i = size-1;
  int savedValue = vetor[size];

  while(i >= 0 && vetor[i] > savedValue){
    *ComparationCounter += 1;
    vetor[i+1] = vetor[i];
    i--;
  }

  vetor[i+1] = savedValue;
}

int max(int *vetor, int start, int end, int *ComparationCounter){
  int bigger = end;

  for(int i = start; i <= end; i++){
      *ComparationCounter += 1;
      if(vetor[i] > vetor[end] && vetor[i] > vetor[bigger]){
        bigger = i;
      }

  }

  return bigger;
}

void troca(int *vetor, int bigger, int lastPosition, int *SwapCounter){
  *SwapCounter += 1;
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

int main(int argc, char** argv){
  int ComparationCounter = 0;
  int size = 10;
  int max = 10000;

  int SwapCounter = 0;

  clock_t time;

 


  int *vet2 = randomVector(size, max, SEED);
  printf("=============\nBubble Sort\n");

  time = clock();
  bubbleSort(vet2, size, &ComparationCounter, &SwapCounter);
  time = clock() - time;
  

  printf("Comparations Bubble Sort: %d \nSwap Counter: %d\n", ComparationCounter, SwapCounter);
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));
  ComparationCounter = 0;
  SwapCounter = 0;

  int *vet4 = randomVector(size, max, SEED);
  printf("=============\nInsertion Sort\n");
 
  time = clock();
  insertionSort(vet4, size, &ComparationCounter);
  time = clock() - time;

  printf("Comparations Insertion Sort: %d\n", ComparationCounter);
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));
  ComparationCounter = 0;

   int *vet = randomVector(size, max, SEED);
  printf("=============\nSelection Sort\n");

  time = clock();
  selectionSort(vet, size, &ComparationCounter , &SwapCounter);
  time = clock() - time;

  printf("Comparations Selection Sort: %d \nSwap Counter: %d\n", ComparationCounter, SwapCounter);
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));
  ComparationCounter = 0;

  return 0;
}
