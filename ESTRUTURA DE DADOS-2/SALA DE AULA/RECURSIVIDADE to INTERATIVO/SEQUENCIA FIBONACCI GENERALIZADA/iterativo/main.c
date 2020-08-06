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
    for(int nLeftParent = 0; nLeftParent < saved->qtde; nLeftParent++){
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
    for(int nLeftParent = 0; nLeftParent < saved->qtde; nLeftParent++){
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
    Memoization* memory = malloc(sizeof(Memoization));

    int resultValue = f1;

    for(int nLeftParent = 1; nLeftParent <= n; nLeftParent++){
        for(int nRightParent = nLeftParent; nRightParent >= 0; nRightParent -= 2){
                int childNRight = nRightParent;//AUXILIAR
                int savedRightChild = childNRight;//SAVED TO COMPARE
                

                while(childNRight >= 0){
                    childNRight -= 2;

                    ////////////////////////////////////////
                    ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
                    ////////////////////////////////////////
                        if(saved(childNRight, memory)){
                            resultValue += getValue(childNRight, memory);
                            break;    
                        }
                    //////////////////////////////////////
                    //////////////////////////////////////

                    if(childNRight == 1) resultValue += f1;
                    else if(childNRight == 0) resultValue += f0;
                    int childNLeft = childNRight-1;

                    if(childNLeft > 1){
                        nLeftParent = childNLeft+1;
                        nRightParent = childNRight;
                        break;
                    }else if(childNLeft == 1){
                        resultValue += f1;
                    }           
                }

                ////////////////////////////////////////
                ////FUNÇAO AUXILIAR PARA MEMOIZAÇAO/////
                ////////////////////////////////////////
                    if(!saved(savedRightChild, memory)){
                        putValue(savedRightChild, resultValue, memory);
                    }
                //////////////////////////////////////
                //////////////////////////////////////

            break;
        }
    }
    return resultValue;
}

int main(int argc, char** argv){
    printf("\n\nresultado: %d\n", fibo(2,3,4));
    return 0;
}
