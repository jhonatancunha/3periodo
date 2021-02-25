#include <iostream>

class Node {
  private:
    int value;
    Node* next;

  public:
    Node(int value){
      this->value = value;
      this->next = NULL;
    }

    int getValue(){
      return this->value;
    }

    Node* getNext(){
      return this->next;
    }

    void setNext(Node* next){
      this->next = next;
    }
};

class List{
  private:
    Node* start;
    int size;

    Node *getNodeBeforeOfPosition(int position){
      Node *aux = this->start;
      while(position > 1){
          aux = aux->getNext();
          position--;
        }

        return aux;
    }

    void addOnStart(Node *node){
      node->setNext(this->start);
      this->start = node;
    }
  
  public:
    List(){
      this->start = NULL;
      this->size = 0;
    }

    int getSize(){
      return this->size;
    }

    void add(int value){
      Node *node = new Node(value);

      if(this->getSize() == 0){
        this->addOnStart(node);
      }else{
        Node *aux = this->start;
        while(aux->getNext() != NULL) aux = aux->getNext();
        
        aux->setNext(node);
      }

      this->size++;
    }

    void add(int value, int position){
      if(position > this->getSize() || this->getSize() == 0) return;
      Node *node = new Node(value);

      if(this->getSize() == 0 || position == 0){
        this->addOnStart(node);
      }else{
        Node *aux = this->getNodeBeforeOfPosition(position);
        if(aux->getNext() != NULL){
          node->setNext(aux->getNext());
        }
        aux->setNext(node);
      }

      this->size++;

    }

    void remove(int position){
      if(position > this->getSize() || this->getSize() == 0) return;
      Node *aux = this->start;
      Node *deleted;

      if(position == 0){
        deleted = aux;
        this->start = this->start->getNext();
      }else{
        aux = this->getNodeBeforeOfPosition(position);
        
        deleted = aux->getNext();
        aux->setNext(deleted->getNext());
      }


      this->size--;
      delete deleted;    
    }

    void print(){
      if(!this->getSize()){
        std::cout << "Lista Vazia!" << '\n';
        return;
      }

      Node *aux = this->start;
      for(int i = 0; i < this->getSize(); i++){
        std::cout << aux->getValue();
        std::cout << " - ";
        aux = aux->getNext();
      }

      std::cout << "\n";
    } 
};




int main(int argc, char *argv[]){

  List *l = new List();

  l->add(2);
  l->add(10);
  l->add(50);
  l->add(99, 0);
  l->add(3, 3);

  l->print();
  l->remove(0);
  l->print();
  l->remove(3);
  l->print();
  l->remove(2);
  l->print();
  l->remove(0);
  l->print();
  l->remove(0);
  l->print();



  return 0;
}