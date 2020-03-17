#include <iostream>

using namespace std;

class Node{
    private:
        int value;
        Node* next;
        Node* before;

    public:

        Node(){
            this->value = 0;
            this->next = NULL;
            this->before = NULL;
        };

        /**
        * Used to get the next element of the list;
        * @return: the adress of the next node;
        */
        Node* getNext(){
            return next;
        };
        
        /**
        * Used to set the next element of the list;
        */
        void setNext(Node* node){
            next = node;
        };

        Node* getBefore(){
            return before;
        };
        
        void setBefore(Node* node){
            before = node;
        };

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

class List{
    private:
        int size;
        Node* start;
        Node* end;


        Node* findBeginning(int pos){
            Node* aux = start;

            for(int i = 0; i < pos; i++){
                aux = aux->getNext();
            }

            return aux;
        };

        Node* findEnd(int pos){
            Node* aux = end;

            for(int i = size-1; i > pos; i--){
                aux = aux->getBefore();
            }

            return aux;
        };

        Node* findPosition(int pos){
            int middle = size/2;

            if(middle == pos || middle >= pos ) return findBeginning(pos);
            else return findEnd(pos);
        };

    public:

        List(){
            this->size = 0;
            this->end = NULL;
            this->start = NULL;
        };

        /**
        * Insert one element in the position that you want of the list;
        * @param value: the value that you want to insert;
        * @param pos: the position that it will be inserted;
        */
        void push(int value, int pos){
            if(pos > size){
                cout << "INVALID INDEX!" << endl;
                return;
            } 

            Node* newNode = new Node();
            newNode->setValue(value);

            if(size == 0){
                cout << "EMPTY LIST, THE VALUE WILL BE INSERTED IN THE '0' POSITION!" << endl;
                start = newNode;
                end = newNode;
            }else if(size == pos){
                newNode->setBefore(end);
                end->setNext(newNode);
                end = newNode;
            }else{
                Node* position = findPosition(pos);
                newNode->setBefore(position->getBefore());
                newNode->setNext(position);
                
                if(pos != 0){   
                    Node* aux = position->getBefore();
                    aux->setNext(newNode);
                }else{
                    start = newNode;
                } 

                position->setBefore(newNode);
            }
            size++;
            
        };

                /**
         * Remove the first node that was inserted in the queue;
         * @param pos: the position of the element that will be removed; 
         */
        int remove(int pos){
            int number;
            try{
                if(pos < -1 || pos >= size){
                    throw -1;
                }else{
                    //ALL REMOTION ACTIONS IS HERE
                    Node* removed = findPosition(pos);
                    Node* next = removed->getNext();
                    Node* before = removed->getBefore();


                    if(before != NULL ) before->setNext(next);
                    next->setBefore(before);
                    number = removed->getValue();
                    delete removed;
                    size--;

                    //CHANGING POINTER OF START & END
                    if(pos == 0){
                        start = next;
                    }else if(pos == size-1){
                        end = before;
                    }

            }
            }catch(int error){
                if(error == -1){
                    cout << "Index out of Range!" << endl;
                    return 0;
                }
            }
            return number;
        };

        /**
        * Used to know how many elements are in the list;
        * @return: size of the list;
        */
        int sizeOf(){
            return size;
        }; 

        /**
        * Print all the elements of the queue;
        */
        void imprimir(){
            if(size == 0){
                cout << "The list is empty!" << endl;
                return;
            }
            for(Node* aux = start; aux != NULL; aux = aux->getNext()){
                cout << aux->getValue();
            }

            cout << endl;
        }


};


int main(){
    List* l1 = new List();


    // cout << l1->sizeOf() << endl;
    l1->push(0,0);
    l1->imprimir();

    l1->push(1,1);
    l1->imprimir();

    l1->push(2,2);
    l1->imprimir();

    l1->push(3,3);
    l1->imprimir();
    
    l1->push(4,4);
    l1->imprimir();

    l1->push(5,1);
    l1->imprimir();

    l1->push(9,3);
    l1->imprimir();
    

    cout << "=============" << endl;

    int removed = l1->remove(0);
    l1->imprimir();

    int removed2 = l1->remove(4);
    l1->imprimir();


}
