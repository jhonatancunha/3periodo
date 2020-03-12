#include<stdio.h>
#define N 100

void convBase(int num, int base){
    int quociente;
    int resto;
    int convertido[N];
    int i = 0;

    while(num >= base){
        quociente  = num/base;
        resto = num%base;
        convertido[i++] = resto;
        num = quociente;
    }
    convertido[i] = num;
    for(int j = i; j >= 0; j--) printf("%d",convertido[j]);

}

void main(){
    convBase(9,8);
}