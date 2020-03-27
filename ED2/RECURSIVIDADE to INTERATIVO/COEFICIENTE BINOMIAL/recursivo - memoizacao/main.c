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
    int id0;
    int id1;
    int value;
    struct value* prox;
}Value;

struct Memoization{
    int qtde;
    Value* first;
    Value* last;
}memoization;
 

//VERIFICA SE ID ESTA CADASTRADO NA MEMORIA
int saved(int id0,int id1, struct Memoization* saved){
    Value* aux = saved->first;
    for(int i = 0; i < saved->qtde; i++){
        if((id0 == aux->id0) && (id1 == aux->id1)){
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}

//RETORNA VALOR REFERENTE AO ID PASSADO
int getValue(int id0,int id1, struct Memoization* saved){
    Value* aux = saved->first;
    for(int i = 0; i < saved->qtde; i++){
        if((id0 == aux->id0) && (id1 == aux->id1)){
            return aux->value;
        }
        aux = aux->prox;
    }

    return 0;
}

//CADASTRA VALOR E ID NA MEMORIA
void putValue(int id0,int id1, int value, struct Memoization* saved){
    Value* new = malloc(sizeof(Value));
    new->id0 = id0;
    new->id1 = id1;
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

int result;

int c(int n, int k){

    
    ////////////////////////////////////////
    ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
    ////////////////////////////////////////
        if(saved(n,k, &memoization)){
            return getValue(n,k, &memoization);
        }
    //////////////////////////////////////
    //////////////////////////////////////

    if(k > n) return 0;
    else if(k == 1) return n;
    else result =  c(n-1, k) + c(n-1, k-1);

    ////////////////////////////////////////
    ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
    ////////////////////////////////////////
        if(!saved(n,k, &memoization)){
            putValue(n,k, result, &memoization);
        }
    //////////////////////////////////////
    //////////////////////////////////////
    return result;
}

int main(int argc, char** argv){
    printf("%d\n", c(30,10));
    return 0;
}
