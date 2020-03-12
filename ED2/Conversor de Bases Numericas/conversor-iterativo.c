#include<stdio.h>
#include<math.h>

void convBase(int num, int base){
    int quociente;
    int resto;
    int tam = ceil((log(num)/log(base)));//Faz o log para saber quantos bits é necessario para armazenar o valor convertido 
    int convertido[tam];
    int i = 0;

    while(num >= base){
        quociente  = num/base;
        resto = num%base;
        convertido[i++] = resto;
        num = quociente;
    }
    convertido[i] = num;
    for(int j = tam-1; j >= 0; j--) printf("%d",convertido[j]);

}

void main(){
    convBase(10,3);
}
