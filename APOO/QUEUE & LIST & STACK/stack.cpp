#include <iostream>

using namespace std;

class Node{
    private:
        int value;
        Node* next;

    public:
        Node(){
            this->value = 0;
            this->next = NULL;
        };

        /**
        * Used to get the next element of the stack;
        * @return: the adress of the next node;
        */
        Node* getNext(){
            return next;
        };
        
        /**
        * Used to set the next element of the stack;
        */
        void setNext(Node* node){
            next = node;
        }

        /**
        * Used to get the value of one element that you want to know;
        * @return: the value of this node;
        */
        int getValue(){
            return value;
        };

        /**
        * Used to set the value of the element that you want;
        */
        void setValue(int n){
            value = n;
        };   
};

class Stack{
    private:
        int size;
        Node* top;

    public:

        Stack(){
            this->size = 0;
            this->top = NULL;
        };

        /**
         * Insert one element in the end of the stack;
         * @param value: the value that you want to insert;
         */
        void push(int value){
            Node* newElement = new Node();
            newElement->setValue(value);

            if(size != 0){
                newElement->setNext(top);
            }

            top = newElement;;
            size++;      
        };

        
        /**
         * Remove the first node that was inserted in the stack;
         */
        int pop(){
            int number;
            try{
                if(size < 1){
                    throw -1;
                }else{
                   number = top->getValue();
                   Node* objDeleted = top;
                   top = top->getNext();

                   delete objDeleted;
                   size--;
            }
            }catch(int error){
                if(error == -1){
                    cout << "Stack is Empty!" << endl;
                    return 0;
                }
            }
            return number;
        };

        /**
        * Used to know how many elements are in the stack;
        * @return: size of the queue;
        */
        int sizeOfStack(){
            return size;
        }; 

        /**
        * Print all the elements of the stack;
        */
        void imprimir(){
            if(size == 0){
                cout << "Stack is Empty!" << endl;
                return;
            }

            for(Node* aux = top; aux != NULL; aux = aux->getNext()) printf("%d\t",aux->getValue());

            printf("\n");
            
        }


};


int main(){
    Stack* f1 = new Stack();


    cout << f1->sizeOfStack() << endl;
    f1->push(50);
    f1->imprimir();

    f1->push(1);
    f1->imprimir();

    f1->push(2);
    f1->imprimir();

    f1->push(3);
    f1->imprimir();
    
    f1->push(4);
    f1->imprimir();

    f1->push(1);
    f1->imprimir();

    f1->push(3);
    f1->imprimir();
    

    cout << "===================================" << endl;

    int removed = f1->pop();
    f1->imprimir();

    int removed2 = f1->pop();
    f1->imprimir();

     int removed3 = f1->pop();
    f1->imprimir();

     int removed4 = f1->pop();
    f1->imprimir();



}
