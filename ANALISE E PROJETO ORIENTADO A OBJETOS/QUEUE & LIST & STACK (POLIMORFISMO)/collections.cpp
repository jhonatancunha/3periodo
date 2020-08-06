#include <iostream>
#include <cstring>

using namespace std;

class Collections{
    protected:
        typedef int TypeValue;
        int size;
        int qtde;
        TypeValue* vetor;

        Collections(){
            size = 10;
            qtde = 0;
            vetor = new TypeValue[size];
        };
        
        ~Collections(){
        delete[] vetor; 
        }

        void ResizeVector(int newSize){
            size = newSize;
            TypeValue* aux = new TypeValue[size];
            memcpy(aux, vetor, sizeof(TypeValue) * qtde);
            delete vetor;
            vetor = aux;
        }

         /**
        * Used to know what's the size of the collections;
        * @return: size;
        */
        int sizeOf(){
            return size;
        };


        void shiftVetorRemove(int start){
            for(int i = start; i < qtde; i++)   vetor[i] = vetor[i+1];
        }   


    public:
        virtual int count(){    return qtde;    };
        virtual void insert(TypeValue value) = 0;
        virtual void insert(TypeValue value, int pos) = 0;
        virtual TypeValue remove() = 0;
        virtual TypeValue remove(int pos) = 0;

};

class Stack: public Collections{
    private:
    public:
        Stack(): Collections() {};

        void push(TypeValue value){
            if(count() >= sizeOf()) ResizeVector(size*2);
            vetor[qtde++] = value;
        }

        void insert(TypeValue value){
            this->push(value);
        }

        void insert(TypeValue value, int pos){
            throw "Too many arguments!";
        }

        TypeValue pop(){
            if((qtde/size) < 0.25) ResizeVector(size/2);
            return vetor[qtde--];
        }

        TypeValue remove(){
            return this->pop();
        }

        TypeValue remove(int pos){
            throw "Too many arguments!";
        }
};

class Queue: public Collections{
    private:
       

    public:
        Queue(): Collections(){};

        void insert(TypeValue value){
            if(count() >= sizeOf()) ResizeVector(size*2);
            vetor[qtde++] = value;
        }

        void insert(TypeValue value, int pos){
            throw "Too many arguments!";
        }

        TypeValue remove(){
            if((qtde/size) < 0.25) ResizeVector(size/2);
            int removed = vetor[0];
            shiftVetorRemove(0);
            qtde--;
            return removed;
        }

        TypeValue remove(int pos){
            throw "Too many arguments!";
        }
};

class List: public Collections{
    private:
        void shiftAdd(int pos){
            for(int i = qtde; i >= pos; i--) vetor[i] = vetor[i-1];
        };

    public:
        List():Collections(){};

        void insert(TypeValue value){
           throw "You need to inform the position you want to insert!";
        }

         void insert(TypeValue value, int pos){
            if(pos > qtde || pos < 0){
                cout << "Invalid Position! "<<endl;
                return; 
            }

            if(count() >= sizeOf()) ResizeVector(size*2);
            
           if(pos != qtde){
               shiftAdd(pos);
               vetor[pos] = value;
           }else{
               vetor[qtde] = value;
           }

            qtde++;
        }

        TypeValue remove(){
            throw "What's the position that you want to remove?";
        };

        TypeValue remove(int pos){
            if((qtde/size) < 0.25) ResizeVector(size/2);
            int removed = vetor[pos];
            shiftVetorRemove(pos);
            qtde--;
            return removed;
        }

        
};



int main(){
    //=========PILHA==============//

    Stack* pilha = new Stack();
    
    pilha->push(5);
    pilha->push(2);
    pilha->push(3);

    pilha->pop();
    //=========FILA==============//

    Queue* fila = new Queue();

    fila->insert(5);
    fila->insert(2);
    fila->insert(3);

    fila->remove();
    //=========LISTA==============//

    List* lista = new List();

    lista->insert(1,0);
    lista->insert(9,1);
    lista->insert(3,2);
    lista->insert(4,3);
    lista->insert(5,4);
    lista->insert(9,5);

    lista->remove(0);
    //============================//

    return 0;
};