#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *v, int start, int middle, int end){
    int i, j, k;
    int sizeOfFirstSubVector = middle - start + 1;
    int sizeOfSecondSubVector = end - middle;
    int *firstSubVector = (int*) malloc(sizeof(int) * (sizeOfFirstSubVector + 1));
    int *secondSubVector = (int*) malloc(sizeof(int) * (sizeOfSecondSubVector + 1));

    for(i = 0; i < sizeOfFirstSubVector; i++){
        firstSubVector[i] = v[start + i];
    }
    firstSubVector[sizeOfFirstSubVector] = INT_MAX;
    printf("i: %d\n", i);

    for(j = 0; j < sizeOfSecondSubVector; j++){
        secondSubVector[j] = v[middle + j + 1];
    }
    secondSubVector[sizeOfSecondSubVector] = INT_MAX;
    i = 0;
    j = 0;

    for(k = start; i <= end; k++){
        if(firstSubVector[i] <= secondSubVector[j]){
            v[k] = firstSubVector[i++];
        }else{
            v[k] = secondSubVector[j++];
        }
    }

    free(firstSubVector);
    free(secondSubVector);
}

int main(int argc, char** argv){
    int v[6] = {3, 5, 6, 0, 4 , 7};

    for(int i = 0; i < 6; i++ ){
        printf("%d, ", v[i]);
    }
    printf("\n=============\n");
    merge(v, 0, 2, 5);

    for(int i = 0; i < 6; i++ ){
        printf("%d, ", v[i]);
    }



    return 0;
}
