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
      Node *aux = this->getStart();
      while(position > 1){
          aux = aux->getNext();
          position--;
        }

        return aux;
    }

    Node *getStart(){
      return this->start;
    }

    void setStart(Node *node){
      this->start = node;
    }

    void addOnStart(Node *node){
      node->setNext(this->getStart());
      this->setStart(node);
    }

    void addSize(){
      this->size++;
    }

    void removeSize(){
      this->size--;
    }
  
  public:
    List(){
      this->start = NULL;
      this->size = 0;
    }

    ~List(){
      Node* node = this->getStart();
      while(this->getSize()){
        this->setStart(node->getNext());
        delete node;
        node = this->getStart();
        this->removeSize();
      }
    }

    int getSize(){
      return this->size;
    }

    void add(int value){
      Node *node = new Node(value);

      if(this->getSize() == 0){
        this->addOnStart(node);
      }else{
        Node *aux = this->getStart();
        while(aux->getNext() != NULL) aux = aux->getNext();
        
        aux->setNext(node);
      }

      this->addSize();
    }

    void add(int value, int position){
      if(position > this->getSize() || this->getSize() == 0) return;
      Node *node = new Node(value);

      if(this->getSize() == 0 || position == 0){
        this->addOnStart(node);
      }else{
        Node *aux = this->getNodeBeforeOfPosition(position);
        if(aux->getNext() != NULL) node->setNext(aux->getNext());
        
        aux->setNext(node);
      }

      this->addSize();

    }

    void remove(int position){
      if(position > this->getSize() || this->getSize() == 0) return;
      Node *aux = this->getStart();
      Node *deleted;

      if(position == 0){
        deleted = aux;
        this->setStart(getStart()->getNext());
      }else{
        aux = this->getNodeBeforeOfPosition(position);
        
        deleted = aux->getNext();
        aux->setNext(deleted->getNext());
      }


      this->removeSize();
      delete deleted;    
    }

    void print(){
      if(!this->getSize()){
        std::cout << "List is Empty!" << '\n';
        return;
      }

      Node *aux = this->getStart();
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

  l->~List();
  l->print();

  return 0;
}