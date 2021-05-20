#include <stdio.h>
#include <stdlib.h>


/////////////////////////////////////////////
//////////////////UTFPR//////////////////////
///////USADO PARA MEMOIZAÇAO DO CODIGO///////
//////////JHONATAN CUNHA RA=2135590//////////
/////////////////////////////////////////////
///MODIFICADO MEMOIZATION PARA ESTE CODIGO///
/////////////////////////////////////////////
typedef struct value{
    int id;
    int value;
    struct value* prox;
}Value;

struct Memoization{
    int qtde;
    Value* first;
    Value* last;
}memoization;
 

//VERIFICA SE ID ESTA CADASTRADO NA MEMORIA
int saved(int id, struct Memoization* saved){
    Value* aux = saved->first;
    for(int i = 0; i < saved->qtde; i++){
        if(id == aux->id){
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}

//RETORNA VALOR REFERENTE AO ID PASSADO
int getValue(int id, struct Memoization* saved){
    Value* aux = saved->first;
    for(int i = 0; i < saved->qtde; i++){
        if(id == aux->id){
            return aux->value;
        }
        aux = aux->prox;
    }

    return 0;
}

//CADASTRA VALOR E ID NA MEMORIA
void putValue(int id, int value, struct Memoization* saved){
    Value* new = malloc(sizeof(Value));
    new->id = id;
    new->value = value;



    if(saved->qtde == 0){
        saved->first = new;
    }else{
        saved->last->prox = new;
    }
    saved->last = new;
    saved->qtde++;
}
////////////////////////////////////
////////////////////////////////////

//#########################################################################//

int soma = 0;

int fibo(int f0, int f1, int n){

    ////////////////////////////////////////
    ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
    ////////////////////////////////////////
        if(saved(n, &memoization)){
            return getValue(n, &memoization);
        }
    //////////////////////////////////////
    //////////////////////////////////////
    

    if(n == 0) return f0;
    else if(n == 1) return f1;
    else if(n > 1) soma = fibo(f0,f1,n-1) + fibo(f0,f1,n-2);

    
    ////////////////////////////////////////
    ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
    ////////////////////////////////////////
        if(!saved(n, &memoization)){
            putValue(n, soma, &memoization);
        }
    //////////////////////////////////////
    //////////////////////////////////////
    return soma;
}

int main(int argc, char** argv){
    printf("%d\n", fibo(2,3,4));
    return 0;
}
