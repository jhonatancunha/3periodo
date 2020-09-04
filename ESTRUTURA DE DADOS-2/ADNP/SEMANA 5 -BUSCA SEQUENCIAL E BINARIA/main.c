#include <stdio.h>
#include "busca.h"

int main(int argc, char** argv){
    int v[5] = { 1, 0, 55, 3, 2};
    // int *v2 = randomVectorUniqueElems(10, 0);
    // int v2[4] = {0, 1, 4, 5};
    // printf("%d", SelectionMinK(v2, 4, 3));

    printf("%d\n", HeapMinK(v, 5, 4));
    return 0;
}
