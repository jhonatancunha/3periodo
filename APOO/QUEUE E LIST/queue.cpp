#include <iostream>

using namespace std;

class Node{
    private:
        int value;
        Node* next;

    public:
        /**
        * Used to get the next element of the queue;
        * @return: the adress of the next node;
        */
        Node* getNext(){
            return next;
        };
        
        /**
        * Used to set the next element of the queue;
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
        }    
};

class Queue{
    private:
        int size = 0;
        Node* first;
        Node* last;

    public:

        /**
         * Insert one element in the end of the queue;
         * @param value: the value that you want to insert;
         */
        void push(int value){
            Node* newElement = new Node;
            newElement->setValue(value);
            newElement->setNext(NULL);
            
            if(size == 0){
                first = newElement;
            }else{
                last->setNext(newElement);
            }

            last = newElement;
            size++;
        };

        
        /**
         * Remove the first node that was inserted in the queue;
         */
        int pop(){
            int number;
            try{
                if(size < 1){
                    throw -1;
                }else{
                   number = first->getValue();
                   Node* objDeleted = first;
                   first = first->getNext();

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
        * Used to know how many elements are in the queue;
        * @return: size of the queue;
        */
        int size(){
            return size;
        }; 

        /**
        * Print all the elements of the queue;
        */
        void imprimir(){
            if(size == 0){
                cout << "Lista Vazia!" << endl;
                return;
            }

            for(Node* aux = first; aux != NULL; aux = aux->getNext()) printf("%d\t",aux->getValue());

            printf("\n");
            
        }


};


int main(){
    Queue* f1 = new Queue;


    cout << f1->size() << endl;
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