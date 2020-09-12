#include <stdio.h>
#include <stdlib.h>

int hash(int x, int m){
    return x % m;
} 
    
int main(int argc, char** argv){

    printf("%d\n", hash(723, 10));
    return 0;
}
