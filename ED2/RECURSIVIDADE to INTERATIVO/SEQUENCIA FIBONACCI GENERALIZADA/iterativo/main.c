#include <stdio.h>
#include <stdlib.h>


/////////////////////////////////////////////
//////////////////UTFPR//////////////////////
///////USADO PARA MEMOIZAÇAO DO CODIGO///////
//////////JHONATAN CUNHA RA=2135590//////////
/////////////////////////////////////////////
typedef struct value{
    int id;
    int value;
    struct value* prox;
}Value;

typedef struct{
    int qtde;
    Value* first;
    Value* last;
}Memoization;
 

//VERIFICA SE ID ESTA CADASTRADO NA MEMORIA
int saved(int id, Memoization* saved){
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
int getValue(int id, Memoization* saved){
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
void putValue(int id, int value, Memoization* saved){
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

////////////////////////////////////
////////////////////////////////////
//////FUNÇAO ITERATIVA FIBO/////////
////////////////////////////////////
////////////////////////////////////
int fibo(int f0, int f1, int n){
    Memoization* save = malloc(sizeof(Memoization));

    int soma = f1;
    int i;
    int j;

    for(i = 1; i <= n; i++){
        for(j = i; j >= 0; j -= 2){
                int auxJ = j;
                int savedJ = auxJ;
                

                while(auxJ >= 0){
                    auxJ -= 2;
                    ////////////////////////////////////////
                    ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
                    ////////////////////////////////////////
                        if(saved(auxJ, save)){
                            soma += getValue(auxJ, save);
                            break;    
                        }
                    //////////////////////////////////////
                    //////////////////////////////////////

                    if(auxJ == 1) soma += f1;
                    else if(auxJ == 0) soma += f0;
                    int auxI = auxJ-1;

                    if(auxI > 1){
                        i = auxI+1;
                        j = auxJ;
                        break;
                    }else if(auxI == 1){
                        soma += f1;
                    }           
                }

                ////////////////////////////////////////
                ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
                ////////////////////////////////////////
                    if(!saved(savedJ, save)){
                        putValue(savedJ, soma, save);
                    }
                //////////////////////////////////////
                //////////////////////////////////////

            break;
        }
    }
    return soma;
}

int main(int argc, char** argv){
    printf("\n\nresultado: %d\n", fibo(2,3,4));
    return 0;
}
