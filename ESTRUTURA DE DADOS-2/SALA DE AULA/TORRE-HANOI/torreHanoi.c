#include<stdio.h>

void hanoi(int n, char origem, char destino, char temp){
    if(n == 1){
        printf("Mova disco %d do: pino %c --> pino %c\n", n, origem, destino);
    }else{
        hanoi(n-1, origem, temp, destino);
        printf("Mova disco %d do: pino %c --> pino %c\n", n, origem, destino);
        hanoi(n-1, temp, destino, origem);
    }
}

void main(){
    hanoi(4,'a','c','b');
}