#include <stdio.h>

int c(int n, int k){
    if(k > n) return 0;
    else if(k == 1) return n;
    else return c(n-1, k) + c(n-1, k-1);
}

int main(int argc, char** argv){
    printf("%d\n", c(30,10));
    return 0;
}
