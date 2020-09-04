#include <stdio.h>
#include "busca.h"

int main(int argc, char** argv){
    int v[5] = { 1, 2, 55, 6, 3};
    // int *v2 = randomVectorUniqueElems(10, 0);
    // int v2[4] = {0, 1, 4, 5};
    // printf("%d", SelectionMinK(v2, 4, 3));

    printf("%d\n", HeapMinK(v, 5, 1));
    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
