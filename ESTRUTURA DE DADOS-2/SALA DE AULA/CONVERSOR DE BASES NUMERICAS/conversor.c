#include<stdio.h>

void convBase(int num, int base){
    if(num < base) {
        printf("%d", num);
        return;
    }
    int quociente = num/base;
    int resto = num%base;
    convBase(quociente, base);
    printf("%d", resto);
}

void main(){
    convBase(10,2);
}
