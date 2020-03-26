#include <stdio.h>

int fibo(int f0, int f1, int n){
    if(n == 0) return f0;
    else if(n == 1) return f1;
    else if(n > 1) return fibo(f0,f1,n-1) + fibo(f0,f1,n-2);
}

int main(int argc, char** argv){
    printf("%d\n", fibo(5,5,30));
    return 0;
}
