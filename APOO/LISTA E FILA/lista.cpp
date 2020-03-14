#include <iostream>

using namespace std;

class Node{
    private:
        int value;
        Node* next;
        Node* before;

    public:
        Node* getNext(){
            return next;
        };
        
        void setNext(Node* node){
            next = node;
        }

        Node* getBefore(){
            return before;
        };
        
        void setBefore(Node* node){
            before = node;
        }

        int getValue(){
            return value;
        };

        void setValue(int n){
            value = n;
        }    
};

class List{
    private:
        int qtde = 0;
        Node* start;
        Node* end;


        Node* findBeginning(int pos){
            Node* aux = start;

            for(int i = 0; i < pos; i++){
                aux = aux->getNext();
            }

            return aux;
        }

        Node* findEnd(int pos){
            Node* aux = end;

            for(int i = qtde-1; i > pos; i--){
                aux = aux->getBefore();
            }

            return aux;
        }

        Node* findPosition(int pos){
            int middle = qtde/2;

            if(middle == pos || middle >= pos ) return findBeginning(pos);
            else return findEnd(pos);
        };

    public:

        void push(int value, int pos){
            if(pos > qtde){
                cout << "Posiçao Invalida!" << endl;
                return;
            } 

            Node* newNode = new Node;
            newNode->setValue(value);
            newNode->setNext(NULL);
            newNode->setBefore(NULL);

            if(qtde == 0){
                cout << "LISTA VAZIA, ALOCADO VALOR NA POSIÇAO 0!" << endl;
                start = newNode;
                end = newNode;
            }else if(qtde == pos){
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
            qtde++;
            
        };

        int remove(int pos){
            int number;
            try{
                if(pos < -1 || pos >= qtde){
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
                    qtde--;

                    //CHANGING POINTER OF START & END
                    if(pos == 0){
                        start = next;
                    }else if(pos == qtde-1){
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

        int size(){
            return qtde;
        }; 

        void imprimir(){
            if(qtde == 0){
                cout << "Lista Vazia!" << endl;
                return;
            }
            for(Node* aux = start; aux != NULL; aux = aux->getNext()){
                cout << aux->getValue();
            }

            cout << endl;
        }


};


int main(){
    List* l1 = new List;


    // cout << l1->size() << endl;
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