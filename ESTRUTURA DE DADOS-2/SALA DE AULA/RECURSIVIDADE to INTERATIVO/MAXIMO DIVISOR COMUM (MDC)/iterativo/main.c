#include <stdio.h>


int mdc(int x, int y){
    if((y <= x) && (x%y == 0)) return y;
    int min = (x > y)? y : x;
    int max = (x > y)? x : y;

    int resto = max%min;
    
    while(resto != 0){
        max = min;
        min = resto;
        resto = max%min;
    }

    return min;
}

int main(int argc, char** argv){
    printf("%d\n", mdc(4,3));
    return 0;
}
